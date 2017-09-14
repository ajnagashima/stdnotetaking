/*
    file: opt_handle.c
    desc: implements optional arguement handling for stdnote.c
    author: AJ Nagashima
    email: ajn3687@g.rit.edu
*/

#include <stdio.h>
#include <stdlib.h>
//unistd.h required for handling missing and incorrect input of existing options
#include <unistd.h>
#include <getopt.h>

typedef int bool;
enum {false, true};

extern bool date;
extern char * class;

//prints usage options for stdnote
void usage(){
    fprintf( stderr , "usage: stdnote [options]\n");
    fprintf( stderr , "By default, stdnote runs with current date\n");
}

int handle(int argc, char * argv[])
{
    return 0;
}

