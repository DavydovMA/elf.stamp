/* DavydovMA 2013040600 {
 * file:	main.c
 */

#define		SOFT_NAME	"Stamp"
#define		SOFT_VERSION	"19.07.b3"
#define		SOFT_COPYRIGHT	"Copyright 1990-2019"
#define		SOFT_AUTHOR	"DavydovMA"
#define		SOFT_URL	"http://domain"
#define		SOFT_EMAIL	"dev-c@domain"

#define		_FILE_OFFSET_BITS	64

#include	"main_head.c"
#include	"main_copying.c"
#include	"main_help.c"

#include	<dirent.h>
#include	<errno.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>
#include	<sys/time.h>
#include	<time.h>
#include	<unistd.h>
#include	<utime.h>


/* ------------- ---- ------
 * function:	stamp_rand {
 * rem:		get random stamp
 * date:	2019-02-21
 * in:
 *  vs_kill	struct tm
 * out:
 */
void stamp_rand( struct tm *vs_kill ) {

	vs_kill->tm_sec		= rand() % 60;		/* 00 - 59 */
	vs_kill->tm_min		= rand() % 60;		/* 00 - 59 */
	vs_kill->tm_hour	= rand() % 24;		/* 00 - 23 */
	vs_kill->tm_mday	= rand() % 30 + 1;	/* 01 - 31 */
	vs_kill->tm_mon		= rand() % 12;		/* 00 - 11 */
	vs_kill->tm_year	= rand() % 138;		/* 0 - o_O: This is the number of full calendar years since 1900. */
	vs_kill->tm_wday	= rand() % 7;		/* 0 - 6 */
	vs_kill->tm_yday	= rand() % 366;		/* 0 - 365 */
	vs_kill->tm_isdst	= rand() % 2;		/* 0 - 1   */
	vs_kill->tm_gmtoff	= 0;			/* ignor */
	vs_kill->tm_zone	= 0;			/* ignor */

}	/* } stamp_rand */
/* ------------- ---- ------
 * function:	stamp_mktime {
 * rem:		set stamp
 * date:	2019-07-24
 * in:
 *  vc_path	path to destination
 * out:
 */
void stamp_mktime( const char *vc_path ) {

	struct	tm	vs_killa;	/* atime */
	struct	tm	vs_killm;	/* mtime */
	struct	timeval	tvp[2];

	if ( flag.rand == 0 ) {
		vs_killa.tm_sec		= 6;	/* 00 - 59: This is the number of full seconds since the top of the minute (normally in the range 0 through 59, but the actual upper limit is 60, to allow for leap seconds if leap second support is available). */
		vs_killm.tm_sec		= vs_killa.tm_sec;
		vs_killa.tm_min		= 4;	/* 00 - 59: This is the number of full minutes since the top of the hour (in the range 0 through 59). */
		vs_killm.tm_min		= vs_killa.tm_min;
		vs_killa.tm_hour	= 13;	/* 00 - 23: This is the number of full hours past midnight (in the range 0 through 23). */
		vs_killm.tm_hour	= vs_killa.tm_hour;
		vs_killa.tm_mday	= 6;	/* 01 - 31: This is the ordinal day of the month (in the range 1 through 31). Watch out for this one! As the only ordinal number in the structure, it is inconsistent with the rest of the structure. */
		vs_killm.tm_mday	= vs_killa.tm_mday;
		vs_killa.tm_mon		= 3;	/* 00 - 11: This is the number of full calendar months since the beginning of the year (in the range 0 through 11). Watch out for this one! People usually use ordinal numbers for month-of-year (where January = 1). */
		vs_killm.tm_mon		= vs_killa.tm_mon;
		vs_killa.tm_year	= 113;	/* 0 - o_O: This is the number of full calendar years since 1900. */
		vs_killm.tm_year	= vs_killa.tm_year;
		vs_killa.tm_wday	= 6;	/* ignor: This is the number of full days since Sunday (in the range 0 through 6). */
		vs_killm.tm_wday	= vs_killa.tm_wday;
		vs_killa.tm_yday	= 96;	/* ignor: This is the number of full days since the beginning of the year (in the range 0 through 365). */
		vs_killm.tm_yday	= vs_killa.tm_yday;
		vs_killa.tm_isdst	= 0;	/* This is a flag that indicates whether Daylight Saving Time is (or was, or will be) in effect at the time described. The value is positive if Daylight Saving Time is in effect, zero if it is not, and negative if the information is not available. */
		vs_killm.tm_isdst	= vs_killa.tm_isdst;
		vs_killa.tm_gmtoff	= 0;	/* ignor: This field describes the time zone that was used to compute this brokendown time value, including any adjustment for daylight saving; it is the number of seconds that you must add to UTC to get local time. You can also think of this as the number of seconds east of UTC. For example, for U.S. Eastern Standard Time, the value is -5*60*60. The tm_gmtoff field is derived from BSD and is a GNU library extension; it is not visible in a strict ISO C environment. */
		vs_killm.tm_gmtoff	= vs_killa.tm_gmtoff;
		vs_killa.tm_zone	= 0;	/* ignor: This field is the name for the time zone that was used to compute this broken-down time value. Like tm_gmtoff, this field is a BSD and GNU extension, and is not visible in a strict ISO C environment. */
		vs_killm.tm_zone	= vs_killa.tm_zone;
	} else {
		stamp_rand( &vs_killa );
		stamp_rand( &vs_killm );
	}
	tvp[0].tv_sec	= mktime( &vs_killa );
	tvp[0].tv_usec	= 0;
	tvp[1].tv_sec	= mktime( &vs_killm );
	tvp[1].tv_usec	= 0;
	if ( (( flag.link == 0 ) && ( lutimes( vc_path, tvp ) == 0 ) ) || (( flag.link == 1 ) && ( utimes( vc_path, tvp ) == 0 )) ) {
if ( flag.verbose != 0 ) {
		printf( " mktime\t: [%s] - [%04d.%02d.%02d %02d:%02d:%02d]-[%04d.%02d.%02d %02d:%02d:%02d]\n", \
			vc_path, \
			vs_killa.tm_year + 1900, \
			vs_killa.tm_mon, \
			vs_killa.tm_mday, \
			vs_killa.tm_hour, \
			vs_killa.tm_min, \
			vs_killa.tm_sec, \
			vs_killm.tm_year + 1900, \
			vs_killm.tm_mon, \
			vs_killm.tm_mday, \
			vs_killm.tm_hour, \
			vs_killm.tm_min, \
			vs_killm.tm_sec \
			);
}
	} else {
printf( " error\t: [%s] - %s (mktime)\n", vc_path, strerror( errno ) );
	}
}	/* } stamp_mktime */
/* ------------- ---- ------
 * function:	stamp_path {
 * rem:		set stamp
 * date:	2018-12-30
 * in:
 *  vc_path	path to destination
 * out:
 */
void stamp_path( const char *vc_path ) {

	struct	stat	*vs_stat;
	char		*vc_path_new;

if ( flag.verbose != 0 ) {
	printf( " source\t: [%s]\n", vc_path );
}
	vs_stat = ( struct stat * ) malloc( sizeof( struct stat ) );	/* malloc-1 */
	if ( vs_stat != 0 ) {	/* malloc-1 */
		if ( (( flag.link == 0 ) && !( lstat( vc_path, vs_stat ) )) || (( flag.link == 1 ) && !( stat ( vc_path, vs_stat ) )) ) {	/* TYPE */
			if        ( S_ISDIR(  vs_stat->st_mode ) != 0 ) {	/* DIR: begin {*/
//*D				printf( " mode\t: [%s] - DIR\n", vc_path );
				DIR *dp;						/* From: " The GNU C Library Reference Manual" */
				struct dirent *ep;					/* From: " The GNU C Library Reference Manual" */
				dp = opendir( vc_path );				/* From: " The GNU C Library Reference Manual" */
				if ( dp != NULL ) {					/* From: " The GNU C Library Reference Manual" */
					while ( ep = readdir(dp) ) {			/* From: " The GNU C Library Reference Manual" */
						if ( strcmp( ".", ep->d_name ) && strcmp( "..", ep->d_name ) ) {
							vc_path_new = ( char * ) malloc( strlen( vc_path ) + 1 + strlen( ep->d_name ) + 1 );	/* malloc-2 */
							if ( vc_path_new != 0 ) {	/* malloc-2 */
								( char * ) memcpy( vc_path_new, vc_path, strlen( vc_path ) );
								( char * ) memcpy( vc_path_new + strlen( vc_path ), "/", 1 );
								( char * ) memcpy( vc_path_new + strlen( vc_path ) + 1, ep->d_name, strlen( ep->d_name ) );
								vc_path_new[ strlen( vc_path ) + 1 + strlen( ep->d_name ) ] = '\0';
								stamp_path( vc_path_new );	/* RUN recursive */
								free( vc_path_new );
							} else {	/* malloc-2 */
printf( " error\t: [%s] - %s (malloc-2)\n", vc_path, strerror( errno ) );
							}		/* malloc-2 */
//*D						} else {	[ . ] [ .. ]
//*D							printf( "[%s] - NO\n", ep->d_name );
						}
					}						/* From: " The GNU C Library Reference Manual" */
					(void) closedir(dp);				/* From: " The GNU C Library Reference Manual" */
				} else {						/* From: " The GNU C Library Reference Manual" */
printf( " error\t: [%s] - %s (dstrem)\n", vc_path, strerror( errno ) );
				}							/* From: " The GNU C Library Reference Manual" */
				;
if ( flag.verbose != 0 ) {
				printf( " dir\t: [%s]\n", vc_path );
}
				stamp_mktime( vc_path );
				;						/* } DIR: end */
//*D			} else if ( S_ISCHR(  vs_stat->st_mode ) != 0 ) {
//*D				printf( " skip\t: [%s] - CHR\n", vc_path );
//*D			} else if ( S_ISBLK(  vs_stat->st_mode ) != 0 ) {
//*D				printf( " skip\t: [%s] - BLK\n", vc_path );
			} else if ( S_ISREG(  vs_stat->st_mode ) != 0 ) {	/* FILE: begin { */
//*D				printf( " mode\t: [%s] - REG\n", vc_path );
if ( flag.verbose != 0 ) {
				printf( " file\t: [%s]\n", vc_path );
}
				stamp_mktime( vc_path );
				;						/* } FILE: end */
//*D			} else if ( S_ISFIFO( vs_stat->st_mode ) != 0 ) {
//*D				printf( " skip\t: [%s] - FIFO\n", vc_path );
			} else if ( S_ISLNK(  vs_stat->st_mode ) != 0 ) {	/* LINK:  begin { */
if ( flag.verbose != 0 ) {
				printf( " link\t: [%s]\n", vc_path );
}
				stamp_mktime( vc_path );
				;						/* } LINK: end */
//*D				printf( " skip\t: [%s] - LNK\n", vc_path );
//*D			} else if ( S_ISSOCK( vs_stat->st_mode ) != 0 ) {
//*D				printf( " skip\t: [%s] - SOCK\n", vc_path );
			}
		} else {	/* TYPE */
printf( " error\t: [%s] - %s (type)\n", vc_path, strerror( errno ) );
		}		/* TYPE */
		free( vs_stat );
	} else {	/* malloc-1 */
printf( " error\t: [%s] - %s (malloc-1)\n", vc_path, strerror( errno ) );
	}		/* malloc-1 */

}	/* } stamp_path */

/* ------------- ---- ------ *
 * Function:	main {
 * rem:		main function
 * date:	2019-07-24
 * in:
 *  vc_path	path to destination
 * out:
 */
int main( int argc, char *argv[] ) {
/* ------------- ---- ------
 * Block: Variable
 */
	int	vi_sh_path;	/* PATH - number of shell parametr */
	int	vi_count;
	char	*vc_path;

/* show : license */
	f_copy();
	sleep(1);
	file_elf = argv[0];

/* find : --help | -h */
	for ( int vi_count = 0; vi_count < argc; vi_count++ ) {
		if ( ( ! strcmp( "-h", argv[ vi_count ] ) ) || ( ! strcmp( "--help", argv[ vi_count ] ) ) ) {
			f_help();
			exit( 0 );
			break;
		}
	}
/* find : --verbose | -v */
	flag.verbose = 0;
	for ( vi_count = 0; vi_count < argc; vi_count++ ) {
		if ( ( ! strcmp( "-v", argv[ vi_count ] ) ) || ( ! strcmp( "--verbose", argv[ vi_count ] ) ) ) {
			printf( " verbose: [%s]\n", argv[ vi_count ] );
			flag.verbose	= 1;
			break;
		}
	}
/* find : --user | -u */
	flag.user = 0;
	for ( vi_count = 0; vi_count < argc; vi_count++ ) {
		if ( ( ! strcmp( "-u", argv[ vi_count ] ) ) || ( ! strcmp( "--user", argv[ vi_count ] ) ) ) {
			printf( " user\t: [%s]\n", argv[ vi_count ] );
			flag.user	= 1;
			break;
		}
	}
/* find : --random | -r */
	flag.rand = 0;
	for ( vi_count = 0; vi_count < argc; vi_count++ ) {
		if ( ( ! strcmp( "-r", argv[ vi_count ] ) ) || ( ! strcmp( "--random", argv[ vi_count ] ) ) ) {
			printf( " rand\t: [%s]\n", argv[ vi_count ] );
			flag.rand	= 1;
			srand( time( NULL ) );
			break;
		}
	}
/* find : --link | -l */
	flag.link = 0;
	for ( vi_count = 0; vi_count < argc; vi_count++ ) {
		if ( ( ! strcmp( "-l", argv[ vi_count ] ) ) || ( ! strcmp( "--link", argv[ vi_count ] ) ) ) {
			printf( " link\t: [%s]\n", argv[ vi_count ] );
			flag.link	= 1;
			srand( time( NULL ) );
			break;
		}
	}
/* find : Find PATH in shell */
	vi_sh_path = 0;
	for ( vi_count = 0; vi_count < argc; vi_count++ ) {
		if ( ( ! strcmp( "-p", argv[ vi_count ] ) ) || ( ! strcmp( "--path", argv[ vi_count ] ) ) ) {
			vi_sh_path = vi_count + 1;
			printf( " found\t: [%s]\n", argv[ vi_sh_path ] );
			break;
		}
	}

/* check root access  */
	if ( getuid() == 0 ) {
		printf( " access\t: root\n" );
	} else if ( flag.user == 1 ) {
		printf( " access\t: not-root [%d]\n", getuid() );
	} else {
		printf( " access\t: need root!\n" );
		f_help();
		goto m_exit;
	}

/* RUN */
	if ( ( vi_sh_path != 0 ) && ( vi_sh_path < argc ) ){
		vi_count = strlen( argv[ vi_sh_path ] );
		if ( ! strcmp( "/",  ( argv[ vi_sh_path ] + vi_count - 1 ) ) ) {
			vi_count--;
		}
		vc_path = ( char * ) malloc( vi_count + 1 );	/* malloc-0 */
		if ( vc_path != 0 ) {	/* malloc-0 */
			signal( SIGHUP,    SIG_IGN );	/* 01 : termination, report that the user’s terminal is disconnected */
			signal( SIGINT,    SIG_IGN );	/* 02 : termination, when the user types ctrl+c */
			signal( SIGQUIT,   SIG_IGN );	/* 03 : termination, core dump */
			signal( SIGILL,    SIG_IGN );	/* 04 : error, illegal instruction */
			signal( SIGTRAP,   SIG_IGN );	/* 05 : error, breakpoint instruction */
			signal( SIGABRT,   SIG_IGN );	/* 06 : error, calling abort  */
			signal( SIGBUS,    SIG_IGN );	/* 07 : error, invalid pointer is dereferenced */
			signal( SIGFPE,    SIG_IGN );	/* 08 : error, fatal arithmetic error */
//*off			signal( SIGKILL,   SIG_IGN );	/* 09 : termination, cannot be handled or ignored */
//*off			signal( SIGUSR1,   SIG_IGN );	/* 10 : miscellaneous, for you to use any way you want */
			signal( SIGSEGV,   SIG_IGN );	/* 11 : error, read or write outside the memory */
//*off			signal( SIGUSR2,   SIG_IGN );	/* 12 : miscellaneous, for you to use any way you want */
			signal( SIGPIPE,   SIG_IGN );	/* 13 : operation error, broken pipe */
			signal( SIGALRM,   SIG_IGN );	/* 14 : alarm, indicates expiration of a timer that measures real or clock time */
			signal( SIGTERM,   SIG_IGN );	/* 15 : termination, cause program termination */
			signal( SIGSTKFLT, SIG_IGN );	/* 16 : */
			signal( SIGCHLD,   SIG_IGN );	/* 17 : job, to a parent process whenever one of its child processes terminates or stops.*/
			signal( SIGCONT,   SIG_IGN );	/* 18 : job, make it continue */
			signal( SIGSTOP,   SIG_IGN );	/* 19 : job, stops the process */
			signal( SIGTSTP,   SIG_IGN );	/* 20 : job, interactive stop signal */
			signal( SIGTTIN,   SIG_IGN );	/* 21 : job, process in a background job tries to read from the terminal */
			signal( SIGTTOU,   SIG_IGN );	/* 22 : job, in a background job attempts to write to the terminal or set its modes*/
			signal( SIGURG,    SIG_IGN );	/* 23 : asynchronous i/o, when “urgent” or out-of-band data arrives on a socket */
			signal( SIGXCPU,   SIG_IGN );	/* 24 : operation error, CPU time limit exceeded */
			signal( SIGXFSZ,   SIG_IGN );	/* 25 : operation error, file size limit exceeded */
			signal( SIGVTALRM, SIG_IGN );	/* 26 : alarm, indicates expiration of a timer that measures CPU time */
			signal( SIGPROF,   SIG_IGN );	/* 27 : alarm, indicates expiration of a timer that measures both CPU time */
//*off			signal( SIGWINCH,  SIG_IGN );	/* 28 : miscellaneous, window size change */
			signal( SIGIO,     SIG_IGN );	/* 29 : asynchronous i/o, sent when a file descriptor is ready */
			signal( SIGPWR,    SIG_IGN );	/* 30 : */
			signal( SIGSYS,    SIG_IGN );	/* 31 : error, bad system call */
//*off			34-49 SIGRTMIN...+NN
//*off			50-64 SIGRTMAX...-NN
			( char * ) memcpy( vc_path, argv[ vi_sh_path ], vi_count );
			vc_path[ vi_count ] = '\0';
			stamp_path( vc_path );	/* RUN recursive */
			free( vc_path );
		} else {	/* malloc-0 */
printf( " error\t: [%s] - %s (malloc-0)\n", argv[ vi_sh_path ], strerror( errno ) );
		}		/* malloc-0 */
		;
	} else {
		f_help();
	}

m_exit:
	printf( " exit\t: bay.\n" );

}	/* } main */


/* } DavydovMA 2019072400 */
