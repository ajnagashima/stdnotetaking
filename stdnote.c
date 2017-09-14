/*
    file: formatNotes.c
    desc: creates a note header and file for a day given in command line
    Author: AJ Nagashima
    email: ajn3687@g.rit.edu
*/

/*
TODO list:
    make optional arguments
    expand handle.c class
    un-hardcode arguements
    make code more versitile
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define YEARMADE 2017

//change to fit person
#define STUDENTNAME "AJ Nagashima"
#define STUDENTEMAIL "ajn3687@g.rit.edu"
#define HALFLINEMAX 40

//found in validate.c
int checkValidMonth(char * month);
int checkValidDay(int mt, int d, int y);

//header used in opt_handle.c
int handle(int argc, char * argv[]);

//early main function
int main(int argc, char * argv[])
{
    //hardcoded for now //TODO expand to multiple classes//
    //make sure there are five arguments
    if(argc != 5){
        fprintf(stderr, "usage: stdnote <month> <day> <year> <class>\n");
        return 0;
    }

    
    //currently doesnt do anything //TODO implement//
    if(handle(argc, argv))
        return 0;

    char * month = malloc(strlen(argv[1]) * sizeof(char));
    strcpy(month, argv[1]);

    for(int i = 0; i < strlen(month); i++)
        month[i] = tolower(month[i]);

    int monthType = checkValidMonth(month);
    if(monthType == 0){
        fprintf(stderr, "error: Month is not valid\n");
        return 0;
    }

    int year;
    if(sscanf(argv[3], "%d", &year) == 0)
        year = 0;
    if(year < YEARMADE){
        fprintf(stderr, "error: Year must be an integer greater than or equal to %d\n", YEARMADE);
        return 0;
    }

    int day;
    if(sscanf(argv[2], "%d", &day) == 0)
        day = 0;
    if(checkValidDay(monthType, day, year) == 0){
        fprintf(stderr, "error: Number of days invalid for month\n");
        return 0;
    }

    char * class = malloc((strlen(argv[4])+1) * sizeof(char));
    strncpy(class, argv[4], strlen(argv[4]));
    class[strlen(class)] = '\0';
   

    char filename[14];
    char moncat[4];
    strncpy(moncat, month, 3);
    moncat[3] = '\0';

    sprintf(filename, "%s%d_%d.txt", moncat, day, year);
    printf("%s\n", filename);

    if(access(filename, F_OK) !=-1){
        fprintf(stderr, "error: File already exists\n");
        return 0;
    }

    char th[2];
    switch(day){
    case 1:
        strcpy(th, "st");
        break;
    case 2:
        strcpy(th, "nd");
        break;
    case 3:
        strcpy(th, "rd");
        break;
    default:
        strcpy(th, "th");
    }

    int numrows = 4;
    int nspaces[numrows];

    char * line1 = malloc(20*sizeof(char));
    snprintf(line1, 20, "%s %d%s, %d", month, day, th, year);

    //decides number of spaces per line (needed for centering)
    nspaces[0] = strlen(line1);
    nspaces[1] = strlen(class);
    nspaces[2] = strlen(STUDENTNAME);
    nspaces[3] = strlen(STUDENTEMAIL);

    for(int i = 0; i < numrows; i++)
        nspaces[i] += 10;

    for(int i = 0; i< numrows; i++)
        nspaces[i] = HALFLINEMAX - (nspaces[i]/2);

    char * spaces[numrows];

    for(int i = 0; i< numrows; i++){
        char *temp = malloc((nspaces[i]+1)*sizeof(char));

        for(int j = 0; j< nspaces[i];j++)
            strcat(temp, " ");
        temp[nspaces[i]-1] = '\0';

        spaces[i] = malloc(sizeof(char) * strlen(temp));
        strcat(spaces[i], temp);
    }

    


    FILE * fp;
    fp = fopen(filename, "a");
    fprintf(fp, "%s---- %s ----\n", spaces[0], line1);
    fprintf(fp, "%s---- %s ----\n", spaces[1], class);
    fprintf(fp, "%s---- %s ----\n", spaces[2], STUDENTNAME);
    fprintf(fp, "%s---- %s ----\n", spaces[3], STUDENTEMAIL);
    fprintf(fp, "\n\n");
    fclose(fp);
    return 1;
}
