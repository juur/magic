/* magic, (c) 1999 Ian Kirk
 * 
 * magic produces output from no input, using magic.
 * 
 * License as per the COPYING file.
 * 
 */

#define _XOPEN_SOURCE 700
#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/time.h>
#include <string.h>

char *options = "shvfe";

int special = 0;

struct option long_options[] = {
     { "special", 0, &special, 1 },
     { "help", 0, NULL, 0 },
     { "version", 0, NULL, 0 },
     { "freshmeat-version", 0, NULL, 0 },
     { "segfault", 0, NULL, 0 },
     { "egg", 0, NULL, 0 },
     { NULL, 0, NULL, 0 }
};

static int number(int from, int to)
{
   if (from > to) {
      int tmp = from;
      from = to;
      to = tmp;
   }
   
   return ((int)(random() % (to - from + 1)) + from);
}

static void doegg()
{
   printf("####   ###    ###\n"
	  "#     #   #  #   #\n"
	  "###   #      #\n"
	  "#     #  ##  #  ##\n"
	  "####   ###    ###\n");
}

static void dieyoucunt()
{
   char *blah = NULL;
   int i;
   
   i = *blah;
   i = *(blah+1);
   
   free(blah);
   memcpy(0, blah, 10000);
}

static void gen_version()
{
   char verbuf[1024];
   
   int length,c;
   
   length = number(3,6);
   
   verbuf[0]='\0';
   
   for(c=length;c;c--) {
      sprintf(verbuf, "%s%s%u", verbuf, (c==length) ? "" : ".",
	      number(0,length-c) + (c==1) );
   }
   
   printf("%s\n", verbuf);
}

static void print_version()
{
   printf("magic (SPOD magicutils) " VERSION "\n");
}

static void print_help()
{
   printf("Usage: magic [OPTION]...\n"
	  "Produces the required output from no input.\n\n"
	  "-s, --special            extra special magic, for more complex inputs.\n"
	  "-h, --help               this help page\n"
	  "-v, --version            output version information and exit\n"
	  "-f, --freshmeat-version  create a freshmeat version number\n"
	  "    --segfault           segfault\n"
	  "\nReport bugs to <magic@localhost>\n");
}

int main(int ac, char *av[])
{
   int arg;
   struct timeval tv;
   
   
   gettimeofday(&tv, NULL);
   srandom(tv.tv_usec);
   
   while( 1 ) {
      int this_option_optind = optind ? optind : 1;
      int option_index = 0;
      
      arg = getopt_long( ac, av, options, long_options, &option_index);
      
      if( arg == -1 ) {
	 break;
      }
      
      if( arg==0 ) {
	 arg = option_index;
      }
      
      switch( arg ) {
       case 1:
       case 'h':
	 print_help();
	 exit(0);
	 break;
       case 2:
       case 'v':
	 print_version();
	 exit(0);
	 break;
       case 3:
       case 'f':
	 gen_version();
	 exit(0);
	 break;
       case 's':
	 special = 1;
       case 0:
	 break;
       case 4:
	 dieyoucunt();
	 exit(0);
	 break;
       case '5':
       case 'e':
	 doegg();
	 exit(0);
	 break;
       default:
	 exit(0);
      }
   }
   
   if( special ) {
      printf("Secret Squirrel\n");
   } else {
      printf("Crazy Ass Shit\n");
   }
   
}
