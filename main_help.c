/* DavydovMA 2013040600 {
 * file:	main_help.c
 */

#include	<stdio.h>


/* ------------- ---- ------
 * function:	f_help {
 * rem:		show help
 * date:	2019-02-21
 * in:
 * out:
 */
void f_help( void ) {

	printf( "\nUsage:\t%s <options>\n"
		"Common options:\n"
		"\t-h|--help\t\t: this help\n"
		"\t-v|--verbose\t\t: verbose mode\n"
		"\t-r|--random\t\t: use random date/time\n"
		"\t-u|--user\t\t: don't check on root\n"
		"\t-l|--link\t\t: follow link; default=(link as file)\n"
		"\t-p|--path <path>\t: path to directory or file\n"
		"\n",
		file_elf
		);

}	/* } f_help */


/* } DavydovMA 2019072400 */