/* File generated by GAA 1.6.6
 */
#define GAA_NO_WIN32
#line 1 "tls_test.gaa"


/* C declarations */

#include <config.h>
#ifdef _WIN32
# include <io.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef GAA_NO_WIN32
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(WINDOWS)
#define GAA_WIN32
#endif
#endif

static void *gaa_malloc(size_t size)
{
    void *ret;
    ret = malloc(size);
    if (ret == NULL) {
	fprintf(stderr, "gaa: could not allocate memory");
	exit(1);
    }
    return ret;
}

static void __gaa_helpsingle(char short_name, char *name,
			     char *arg_desc, char *opt_help)
{
    int col1, col3, col4, tabsize = 3, curr;
    int i;

    col1 = 5;			/* Default values */
    col3 = 30;
    col4 = 70;

    curr = 0;
    for (i = 0; i < col1; i++) {
	printf(" ");
	curr++;
    }
    if (short_name) {
	if (name && *name) {
	    printf("-%c, ", short_name);
	    curr += 4;
	} else {
	    printf("-%c ", short_name);
	    curr += 3;
	}
    }
    if (name && *name) {
	printf("--%s ", name);
	curr += 3 + strlen(name);
    }
    if (arg_desc && *arg_desc) {
	printf("%s ", arg_desc);
	curr += 1 + strlen(arg_desc);
    }
    if (curr >= col3) {
	printf("\n");
	curr = 0;
    }
    if (opt_help) {		/* let's print the option's help body */
	const char *str = opt_help;
	while (*str) {
	    while (curr < col3) {
		printf(" ");
		curr++;
	    }
	    switch (*str) {
	    case '\n':
		printf("\n");
		curr = 0;
		break;
	    case '\t':
		do {
		    printf(" ");
		    curr++;
		}
		while ((curr - col3) % tabsize != 0 && curr < col4);
	    case ' ':
		if (*str == ' ') {
		    curr++;
		    printf(" ");
		}
		for (i = 1; str[i] && str[i] != ' ' && str[i] != '\n'
		     && str[i] != '\t'; i++);
		if (curr + i - 1 >= col4)
		    curr = col4;
		break;
	    default:
		printf("%c", *str);
		curr++;
	    }
	    if (curr >= col4) {
		printf("\n");
		curr = 0;
	    }
	    str++;
	}
    }
    printf("\n");
}

void gaa_help(void)
{
    printf
	("GNU TLS debug client\nUsage: gnutls-cli-debug [options] hostname\n\n\n");
    __gaa_helpsingle('p', "port", "integer ", "The port to connect to.");
    __gaa_helpsingle('d', "debug", "integer ", "Enable debugging");
    __gaa_helpsingle('v', "verbose", "", "More verbose output");
    __gaa_helpsingle('h', "help", "", "prints this help");

#line 100 "gaa.skel"
}

/* Copy of C area */

#line 104 "gaa.skel"
/* GAA HEADER */
#ifndef GAA_HEADER_POKY
#define GAA_HEADER_POKY

typedef struct _gaainfo gaainfo;

struct _gaainfo {
#line 26 "tls_test.gaa"
    char *rest_args;
#line 20 "tls_test.gaa"
    int more_info;
#line 17 "tls_test.gaa"
    int debug;
#line 14 "tls_test.gaa"
    int pp;

#line 114 "gaa.skel"
};

#ifdef __cplusplus
extern "C" {
#endif

    int gaa(int argc, char *argv[], gaainfo * gaaval);

    void gaa_help(void);

    int gaa_file(const char *name, gaainfo * gaaval);

#ifdef __cplusplus
}
#endif
#endif
#line 135 "gaa.skel"
/* C declarations */
#define GAAERROR(x)    \
{                   \
gaa_error = 1;      \
return x;        \
}
static char *gaa_current_option;
static int gaa_error = 0;

/* Generated by gaa */

#include <string.h>
#include <stdlib.h>


#define GAA_OK                       -1

#define GAA_ERROR_NOMATCH            0
#define GAA_ERROR_NOTENOUGH_ARGS     1
#define GAA_ERROR_INVALID_ARG        2
#define GAA_ERROR_UNKNOWN            3

#define GAA_NOT_AN_OPTION       0
#define GAA_WORD_OPTION         1
#define GAA_LETTER_OPTION       2
#define GAA_MULTIPLE_OPTION     3

#define GAA_REST                0
#define GAA_NB_OPTION           4
#define GAAOPTID_help	1
#define GAAOPTID_verbose	2
#define GAAOPTID_debug	3
#define GAAOPTID_port	4

#line 168 "gaa.skel"

#define GAA_CHECK1STR(a,b)      \
if(a[0] == str[0])              \
{                               \
    gaa_current_option = a;     \
    return b;                   \
}

#define GAA_CHECKSTR(a,b)                \
if(strcmp(a,str) == 0)                   \
{                                        \
    gaa_current_option = a;              \
    return b;                            \
}

#define GAA_TESTMOREARGS                                                  \
if(!OK)                                                                     \
{                                  \
while((gaa_last_non_option != gaa_index) && (gaa_arg_used[gaa_index] == 1)) \
    gaa_index++;                                                            \
if(gaa_last_non_option == gaa_index)                                        \
    return GAA_ERROR_NOTENOUGH_ARGS; \
}

#define GAA_TESTMOREOPTIONALARGS                                                  \
if(!OK) \
{ \
while((gaa_last_non_option != gaa_index) && (gaa_arg_used[gaa_index] == 1)) \
    gaa_index++;                                                            \
if(gaa_last_non_option == gaa_index)                                        \
    OK = 1; \
}

#define GAA_FILL_2ARGS(target, func)           \
target = func(GAAargv[gaa_index]);       \
gaa_arg_used[gaa_index] = 1;             \
if(gaa_error == 1)                       \
{                                        \
    gaa_error = 0;                       \
    return GAA_ERROR_INVALID_ARG;        \
}



#define GAA_FILL(target, func, num)           \
if(!OK) \
{ \
target = func(GAAargv[gaa_index]);       \
gaa_arg_used[gaa_index] = 1;             \
if(gaa_error == 1)                       \
{                                        \
    gaa_error = 0;                       \
    return GAA_ERROR_INVALID_ARG;        \
} \
num = 1;  \
} \
else \
{ \
num = 0; \
}

#define GAA_LIST_FILL(target, func, type ,num)                      \
if(!OK) \
{ \
num = 0;                                                            \
target = NULL;                                                      \
if ( gaa_last_non_option - gaa_index > 0)                           \
  target = gaa_malloc((gaa_last_non_option - gaa_index) * sizeof(type));\
for(; gaa_index < gaa_last_non_option; gaa_index++)                 \
{                                                                   \
    if(gaa_arg_used[gaa_index] == 0)                                \
    {                                                               \
        GAA_FILL_2ARGS(target[num], func);                          \
        num++;                                                      \
    }                                                               \
}                                                                   \
if(num == 0)                                                        \
    return GAA_ERROR_NOTENOUGH_ARGS; \
}

#define GAA_OPTIONALLIST_FILL(target, func, type ,num)                      \
if(!OK) \
{ \
num = 0;                                                            \
target = NULL;                                                      \
if ( gaa_last_non_option - gaa_index > 0)                           \
  target = gaa_malloc((gaa_last_non_option - gaa_index) * sizeof(type));\
for(; gaa_index < gaa_last_non_option; gaa_index++)                 \
{                                                                   \
    if(gaa_arg_used[gaa_index] == 0)                                \
    {                                                               \
        GAA_FILL_2ARGS(target[num], func);                                \
        num++;                                                      \
    }                                                               \
} \
}

#define GAA_OBLIGAT(str)                                            \
k = 0;                                                              \
for(i = 0; i < strlen(str); i++)                                    \
{                                                                   \
    j = gaa_get_option_num(str + i, GAA_LETTER_OPTION);           \
    if(j == GAA_ERROR_NOMATCH)                                       \
    {                                                               \
        printf("Error: invalid 'obligat' set\n");                  \
        exit(-1);                                                   \
    }                                                               \
    if(opt_list[j] == 1)                                            \
        k = 1;                                                      \
}                                                                    \
if(k == 0)                                                            \
{                                                                      \
    if(strlen(str) == 1)                                                \
        printf("You must give the -%s option\n", str);                     \
    else                                                                  \
        printf("You must give at least one option of '%s'\n", str);          \
    return 0;         \
}

#define GAA_INCOMP(str)                                                \
k = 0;                                                              \
for(i = 0; i < strlen(str); i++)                                    \
{                                                                   \
    j = gaa_get_option_num(str + i, GAA_LETTER_OPTION);           \
    if(j == GAA_ERROR_NOMATCH)                                      \
    {                                                               \
        printf("Error: invalid 'obligat' set\n");                  \
        exit(-1);                                                   \
    }                                                               \
    if(opt_list[j] == 1)                                            \
        k++;                                                      \
}                   \
if(k > 1)                                                            \
{                                                                      \
    printf("The options '%s' are incompatible\n", str);              \
    return 0;                                                          \
}


static char **GAAargv;
static int GAAargc;
static char *gaa_arg_used;
static int gaa_processing_file = 0;
static int inited = 0;

static int gaa_getint(char *arg)
{
    int tmp;
    char a;
    if (sscanf(arg, "%d%c", &tmp, &a) < 1) {
	printf("Option %s: '%s' isn't an integer\n", gaa_current_option,
	       arg);
	GAAERROR(-1);
    }
    return tmp;
}

static char gaa_getchar(char *arg)
{
    if (strlen(arg) != 1) {
	printf("Option %s: '%s' isn't an character\n", gaa_current_option,
	       arg);
	GAAERROR(-1);
    }
    return arg[0];
}

static char *gaa_getstr(char *arg)
{
    return arg;
}
static float gaa_getfloat(char *arg)
{
    float tmp;
    char a;
    if (sscanf(arg, "%f%c", &tmp, &a) < 1) {
	printf("Option %s: '%s' isn't a float number\n",
	       gaa_current_option, arg);
	GAAERROR(-1);
    }
    return tmp;
}

/* option structures */

struct GAAOPTION_debug {
    int arg1;
    int size1;
};

struct GAAOPTION_port {
    int arg1;
    int size1;
};
#define GAA_REST_EXISTS

struct GAAREST {
    char *arg1;
    int size1;
};

#line 349 "gaa.skel"
static int gaa_is_an_argument(char *str)
{
#ifdef GAA_WIN32
    if (str[0] == '/' && str[1] != 0)
	return GAA_MULTIPLE_OPTION;
#endif
    if (str[0] != '-')
	return GAA_NOT_AN_OPTION;
    if (str[1] == 0)
	return GAA_NOT_AN_OPTION;
    if (str[1] == '-') {
	if (str[2] != 0)
	    return GAA_WORD_OPTION;
	else
	    return GAA_NOT_AN_OPTION;
    }
    if (str[2] == 0)
	return GAA_LETTER_OPTION;
    else
	return GAA_MULTIPLE_OPTION;
}

static int gaa_get_option_num(char *str, int status)
{
    switch (status) {
    case GAA_LETTER_OPTION:
	GAA_CHECK1STR("d", GAAOPTID_debug);
	GAA_CHECK1STR("p", GAAOPTID_port);
    case GAA_MULTIPLE_OPTION:
#line 375 "gaa.skel"
	GAA_CHECK1STR("h", GAAOPTID_help);
	GAA_CHECK1STR("v", GAAOPTID_verbose);

#line 277 "gaa.skel"
	break;
    case GAA_WORD_OPTION:
	GAA_CHECKSTR("help", GAAOPTID_help);
	GAA_CHECKSTR("verbose", GAAOPTID_verbose);
	GAA_CHECKSTR("debug", GAAOPTID_debug);
	GAA_CHECKSTR("port", GAAOPTID_port);

#line 281 "gaa.skel"
	break;
    default:
	break;
    }
    return GAA_ERROR_NOMATCH;
}

static int gaa_try(int gaa_num, int gaa_index, gaainfo * gaaval,
		   char *opt_list)
{
    int OK = 0;
    int gaa_last_non_option;
    struct GAAOPTION_debug GAATMP_debug;
    struct GAAOPTION_port GAATMP_port;

#line 393 "gaa.skel"
#ifdef GAA_REST_EXISTS
    struct GAAREST GAAREST_tmp;
#endif

    opt_list[gaa_num] = 1;

    for (gaa_last_non_option = gaa_index;
	 (gaa_last_non_option != GAAargc)
	 && (gaa_is_an_argument(GAAargv[gaa_last_non_option]) ==
	     GAA_NOT_AN_OPTION); gaa_last_non_option++);

    if (gaa_num == GAA_REST) {
	gaa_index = 1;
	gaa_last_non_option = GAAargc;
    }

    switch (gaa_num) {
    case GAAOPTID_help:
	OK = 0;
#line 23 "tls_test.gaa"
	{
	    gaa_help();
	    exit(0);;
	};

	return GAA_OK;
	break;
    case GAAOPTID_verbose:
	OK = 0;
#line 21 "tls_test.gaa"
	{
	    gaaval->more_info += 1;
	};

	return GAA_OK;
	break;
    case GAAOPTID_debug:
	OK = 0;
	GAA_TESTMOREARGS;
	GAA_FILL(GAATMP_debug.arg1, gaa_getint, GAATMP_debug.size1);
	gaa_index++;
#line 18 "tls_test.gaa"
	{
	    gaaval->debug = GAATMP_debug.arg1;
	};

	return GAA_OK;
	break;
    case GAAOPTID_port:
	OK = 0;
	GAA_TESTMOREARGS;
	GAA_FILL(GAATMP_port.arg1, gaa_getint, GAATMP_port.size1);
	gaa_index++;
#line 15 "tls_test.gaa"
	{
	    gaaval->pp = GAATMP_port.arg1;
	};

	return GAA_OK;
	break;
    case GAA_REST:
	GAA_TESTMOREARGS;
	GAA_FILL(GAAREST_tmp.arg1, gaa_getstr, GAAREST_tmp.size1);
	gaa_index++;
#line 27 "tls_test.gaa"
	{
	    gaaval->rest_args = GAAREST_tmp.arg1;;
	};

	return GAA_OK;
	break;

#line 413 "gaa.skel"
    default:
	break;
    }
    return GAA_ERROR_UNKNOWN;
}

int gaa(int argc, char **argv, gaainfo * gaaval)
{
    int tmp1, tmp2;
    int i, j;
    char *opt_list;

    GAAargv = argv;
    GAAargc = argc;

    opt_list = (char *) gaa_malloc(GAA_NB_OPTION + 1);

    for (i = 0; i < GAA_NB_OPTION + 1; i++)
	opt_list[i] = 0;
    /* initialization */
    if (inited == 0) {

#line 29 "tls_test.gaa"
	{
	    gaaval->rest_args = NULL;
	    gaaval->pp = 443;
	    gaaval->more_info = 0;;
	};

    }
    inited = 1;
#line 438 "gaa.skel"
    gaa_arg_used = NULL;

    if (argc > 0) {
	gaa_arg_used = gaa_malloc(argc * sizeof(char));
    }

    for (i = 1; i < argc; i++)
	gaa_arg_used[i] = 0;
    for (i = 1; i < argc; i++) {
	if (gaa_arg_used[i] == 0) {
	    j = 0;
	    tmp1 = gaa_is_an_argument(GAAargv[i]);
	    switch (tmp1) {
	    case GAA_WORD_OPTION:
		j++;
	    case GAA_LETTER_OPTION:
		j++;
		tmp2 = gaa_get_option_num(argv[i] + j, tmp1);
		if (tmp2 == GAA_ERROR_NOMATCH) {
		    printf("Invalid option '%s'\n", argv[i] + j);
		    return 0;
		}
		switch (gaa_try(tmp2, i + 1, gaaval, opt_list)) {
		case GAA_ERROR_NOTENOUGH_ARGS:
		    printf("'%s': not enough arguments\n",
			   gaa_current_option);
		    return 0;
		case GAA_ERROR_INVALID_ARG:
		    printf("Invalid arguments\n");
		    return 0;
		case GAA_OK:
		    break;
		default:
		    printf("Unknown error\n");
		}
		gaa_arg_used[i] = 1;
		break;
	    case GAA_MULTIPLE_OPTION:
		for (j = 1; j < strlen(argv[i]); j++) {
		    tmp2 = gaa_get_option_num(argv[i] + j, tmp1);
		    if (tmp2 == GAA_ERROR_NOMATCH) {
			printf("Invalid option '%c'\n", *(argv[i] + j));
			return 0;
		    }
		    switch (gaa_try(tmp2, i + 1, gaaval, opt_list)) {
		    case GAA_ERROR_NOTENOUGH_ARGS:
			printf("'%s': not enough arguments\n",
			       gaa_current_option);
			return 0;
		    case GAA_ERROR_INVALID_ARG:
			printf("Invalid arguments\n");
			return 0;
		    case GAA_OK:
			break;
		    default:
			printf("Unknown error\n");
		    }
		}
		gaa_arg_used[i] = 1;
		break;
	    default:
		break;
	    }
	}
    }
    if (gaa_processing_file == 0) {

#line 507 "gaa.skel"
#ifdef GAA_REST_EXISTS
	switch (gaa_try(GAA_REST, 1, gaaval, opt_list)) {
	case GAA_ERROR_NOTENOUGH_ARGS:
	    printf("Rest: not enough arguments\n");
	    return 0;
	case GAA_ERROR_INVALID_ARG:
	    printf("Invalid arguments\n");
	    return 0;
	case GAA_OK:
	    break;
	default:
	    printf("Unknown error\n");
	}
#endif
    }
    for (i = 1; i < argc; i++) {
	if (gaa_arg_used[i] == 0) {
	    printf("Too many arguments\n");
	    return 0;
	}
    }
    free(gaa_arg_used);
    free(opt_list);
    return -1;
}

struct gaastrnode {
    char *str;
    struct gaastrnode *next;
};

typedef struct gaastrnode gaa_str_node;

static int gaa_internal_get_next_str(FILE * file, gaa_str_node * tmp_str,
				     int argc)
{
    int pos_ini;
    int a;
    int i = 0, len = 0, newline = 0;

    if (argc == 1) {
	newline = 1;
	len = 2;
    }

    a = fgetc(file);
    if (a == EOF)
	return 0;

    while (a == ' ' || a == 9 || a == '\n') {
	if (a == '\n') {
	    newline = 1;
	    len = 2;
	}
	a = fgetc(file);
	if (a == EOF)
	    return 0;
    }

    pos_ini = ftell(file) - 1;

    while (a != ' ' && a != 9 && a != '\n') {

	len++;
	a = fgetc(file);
	if (a == EOF)
	    return 0;		//a = ' ';
    }

    len += 1;
    tmp_str->str = gaa_malloc((len) * sizeof(char));

    if (newline == 1) {
	tmp_str->str[0] = '-';
	tmp_str->str[1] = '-';
	i = 2;
    } else {
	i = 0;
    }

    fseek(file, pos_ini, SEEK_SET);
    do {
	a = fgetc(file);

	if (a == EOF) {
	    i += 2;
	    break;
	}
	tmp_str->str[i] = a;
	i++;
    }
    while (a != ' ' && a != 9 && a != '\n' && i < len);

    tmp_str->str[i - 1] = 0;

    fseek(file, -1, SEEK_CUR);
/*    printf("%d\n", ftell(file)); */

    return -1;
}

int gaa_file(const char *name, gaainfo * gaaval)
{
    gaa_str_node *first_str, **tmp_str, *tmp_str2;
    int rval, i;
    char **argv;
    int argc = 0;
    FILE *file;

    gaa_processing_file = 1;

    if ((file = fopen(name, "r")) == NULL) {
	printf("Couldn't open '%s' configuration file for reading\n",
	       name);
	return 1;
    }

    tmp_str = &first_str;
    do {
	argc++;
	*tmp_str = gaa_malloc(sizeof(gaa_str_node));

	(*tmp_str)->str = NULL;
	(*tmp_str)->next = NULL;

	rval = gaa_internal_get_next_str(file, *tmp_str, argc);
	tmp_str = &((*tmp_str)->next);
    }
    while (rval == -1);

    if (rval == 1)
	return 0;

    argv = gaa_malloc((1 + argc) * sizeof(char *));

    tmp_str2 = first_str;
    argv[0] = "cfg";
    for (i = 1; i < argc; i++) {
	argv[i] = tmp_str2->str;
	tmp_str2 = tmp_str2->next;
    }

    rval = gaa(argc, argv, gaaval);
    gaa_processing_file = 0;
    return rval;
}
