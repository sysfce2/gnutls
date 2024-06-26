#!/bin/sh

# Copyright (C) 2010-2016 Free Software Foundation, Inc.
#
# Author: Nikos Mavrogiannopoulos
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

: ${srcdir=.}
: ${SERV=../src/gnutls-serv${EXEEXT}}
: ${CLI=../src/gnutls-cli${EXEEXT}}
unset RETCODE

if ! test -x "${SERV}"; then
	exit 77
fi

if ! test -x "${CLI}"; then
	exit 77
fi

if test "${WINDIR}" != ""; then
	exit 77
fi

if ! test -z "${VALGRIND}"; then
	VALGRIND="${LIBTOOL:-libtool} --mode=execute ${VALGRIND} --error-exitcode=15"
fi


SERV="${SERV} -q"

. "${srcdir}/scripts/common.sh"

: ${ac_cv_sizeof_time_t=8}
if test "${ac_cv_sizeof_time_t}" -ge 8; then
	ATTIME_VALID="2038-10-12"  # almost the pregenerated cert expiration
else
	ATTIME_VALID="2037-12-31"  # before 2038
fi

echo "Checking Fast open"

KEY1=${srcdir}/../doc/credentials/x509/key-rsa.pem
CERT1=${srcdir}/../doc/credentials/x509/cert-rsa.pem
CA1=${srcdir}/../doc/credentials/x509/ca.pem

eval "${GETPORT}"
launch_server --echo --x509keyfile ${KEY1} --x509certfile ${CERT1}
PID=$!
wait_server ${PID}

${VALGRIND} "${CLI}" --attime "${ATTIME_VALID}" -p "${PORT}" localhost --fastopen --priority "NORMAL:-VERS-ALL:+VERS-TLS1.2" --x509cafile ${CA1}  </dev/null || \
	fail ${PID} "1. TLS1.2 handshake should have succeeded!"

${VALGRIND} "${CLI}" --attime "${ATTIME_VALID}" -p "${PORT}" localhost --fastopen --x509cafile ${CA1}  </dev/null || \
	fail ${PID} "2. handshake should have succeeded!"


kill ${PID}
wait

exit 0
