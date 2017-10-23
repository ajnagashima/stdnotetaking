/*
    file: validate.c
    desc: validates month/day given by stdnote.c
    Author: AJ Nagashima
    email: ajn3687@g.rit.edu
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
/*
    @name: checkValidMonth
    @param: 
        char * month: a character array which potentionally holds a month
    @desc: validates if a proper month was given through command line
    @return: 0 if not month, 1 if 31 day month, 2 if 30 day month, 3 if 28 day month
*/
int checkValidMonth(char * month){
    //if string in month is less than three chars, return invalid
    if(strlen(month) < 3)
        return 0;

    //check if any truncation of a month is given then return
    if(strncmp(month, "january", strlen(month)) == 0){
        month = realloc(month, strlen("january")*sizeof(char));
        strncpy(month, "january", strlen("january"));
        return 1;
    }
    if(strncmp(month, "february", strlen(month)) == 0){
        month = realloc(month, strlen("febraury")*sizeof(char));
        strncpy(month, "february", strlen("february"));
        return 3;
    }
    if(strncmp(month, "march", strlen(month)) == 0){
        month = realloc(month, strlen("march")*sizeof(char));
        strncpy(month, "march", strlen("march"));
        return 1;
    }
    if(strncmp(month, "april", strlen(month)) == 0){
        month = realloc(month, strlen("april")*sizeof(char));
        strncpy(month, "april", strlen("april"));
        return 2;
    }
    if(strncmp(month, "may", strlen(month)) == 0){
        month = realloc(month, strlen("may")*sizeof(char));
        strncpy(month, "may", strlen("may"));
        return 1;
    }
    if(strncmp(month, "june", strlen(month)) == 0){
        month = realloc(month, strlen("june")*sizeof(char));
        strncpy(month, "june", strlen("june"));
        return 2;
    }
    if(strncmp(month, "july", strlen(month)) == 0){
        month = realloc(month, strlen("july")*sizeof(char));
        strncpy(month, "july", strlen("july"));
        return 1;
    }
    if(strncmp(month, "august",strlen(month)) == 0){
        month = realloc(month, strlen("august")*sizeof(char));
        strncpy(month, "august", strlen("august"));
        return 1;
    }
    if(strncmp(month, "september", strlen(month)) == 0){
        month = realloc(month, strlen("september")*sizeof(char));
        strncpy(month, "september", strlen("september"));
        return 2;
    }
    if(strncmp(month, "october", strlen(month)) == 0){
        month = realloc(month, strlen("october")*sizeof(char));
        strncpy(month, "october", strlen("october"));
        return 1;
    }
    if(strncmp(month, "november", strlen(month)) == 0){
        month = realloc(month, strlen("november")*sizeof(char));
        strncpy(month, "november", strlen("november"));
        return 2;
    }
    if(strncmp(month, "december", strlen(month)) == 0){
        month = realloc(month, strlen("december")*sizeof(char));
        strncpy(month, "december", strlen("december"));
        return 1;
    }

    return 0;
    
}

int checkValidDay(int mt, int d, int y)
{
    switch(mt){
    case 1:
        if(d > 31)
            return 0;
        break;
    case 2:
        if(d > 30)
            return 0;
        break;
    case 3:
        if(y % 4 == 0 && d > 29)
            return 0;
        else if(y % 4 != 0 &&  d > 28)
            return 0;
    }
    return 1;
}
