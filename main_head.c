/* DavydovMA 2013040600 {
 * file:	main_head.c
 */

#include	<stdio.h>
#include	<signal.h>


struct {
	unsigned int	verbose	: 1;	/* flag verbose  : 0=off; 1=on; -v --verbose */
	unsigned int	user	: 1;	/* flag user     : 0=off; 1=on; -u --user    */
	unsigned int	rand	: 1;	/* flag rand     : 0=off; 1=on; -r --random  */
	unsigned int	link	: 1;	/* flag link     : 0=off; 1=on; -l --link    */
} flag;

	char		*file_elf	= NULL;


/* } DavydovMA 2019072400 */