#!/bin/sh

# Copyright (C) 2016 Red Hat, Inc.
#
# This file is part of GnuTLS.
#
# GnuTLS is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at
# your option) any later version.
#
# GnuTLS is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GnuTLS.  If not, see <https://www.gnu.org/licenses/>.

#set -e

: ${srcdir=.}
: ${CERTTOOL=../../src/certtool${EXEEXT}}
: ${DIFF=diff -b -B}

if ! test -x "${CERTTOOL}"; then
	exit 77
fi

if ! test -z "${VALGRIND}"; then
	VALGRIND="${LIBTOOL:-libtool} --mode=execute ${VALGRIND} --error-exitcode=15"
fi

OUTFILE=out-pkcs7.$$.tmp
OUTFILE2=out2-pkcs7.$$.tmp

: ${ac_cv_sizeof_time_t=8}
if test "${ac_cv_sizeof_time_t}" -ge 8; then
	ATTIME_VALID="2038-10-12"  # almost the pregenerated cert expiration
else
	ATTIME_VALID="2037-12-31"  # before 2038
fi

# Test signing with MD5
FILE="signing"
${VALGRIND} "${CERTTOOL}" --p7-sign --hash md5 --load-privkey  "${srcdir}/../../doc/credentials/x509/key-rsa.pem" --load-certificate "${srcdir}/../../doc/credentials/x509/cert-rsa.pem" --infile "${srcdir}/data/pkcs7-detached.txt" >"${OUTFILE}"
rc=$?

if test "${rc}" != "0"; then
	echo "${FILE}: PKCS7 struct signing with MD5 failed"
	exit ${rc}
fi

FILE="signing-verify"
${VALGRIND} "${CERTTOOL}" --attime "${ATTIME_VALID}" --p7-verify --load-certificate "${srcdir}/../../doc/credentials/x509/cert-rsa.pem" <"${OUTFILE}"
rc=$?

if test "${rc}" != "1"; then
	echo "${FILE}: PKCS7 struct signing succeeded verification with MD5"
	exit ${rc}
fi

FILE="signing-verify"
${VALGRIND} "${CERTTOOL}" --attime "${ATTIME_VALID}" --p7-verify --verify-allow-broken --load-certificate "${srcdir}/../../doc/credentials/x509/cert-rsa.pem" <"${OUTFILE}"
rc=$?

if test "${rc}" != "0"; then
	echo "${FILE}: PKCS7 struct signing failed with MD5 and allow-broken"
	exit ${rc}
fi

rm -f "${OUTFILE}"
rm -f "${OUTFILE2}"

exit 0
