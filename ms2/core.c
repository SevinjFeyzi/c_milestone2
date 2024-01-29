/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Sevinj Feyziyeva
Student ID#: 154057194
Email      : sfeyziyeva@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// User-Defined Libraries
#include "core.h"


// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}



int inputInt() {
    int num, newLine = 0;
    char ch;

    do {
        scanf("%d%c", &num, &ch);
        if (ch != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else {
            newLine = 1;
        }

    } while (!newLine);
    return num;

}

int inputIntPositive() {
    int num;
    do {
        num = inputInt();
        if (num < 1) {
            printf("ERROR! Value must be > 0: ");
        }

    } while (num < 1);
    return num;
}


int inputIntRange(int lower, int upper)
{
    int num;
    char newLine;

    do {
        scanf(" %d%c", &num, &newLine);

        if (newLine != '\n') { //check if integer was not entered
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if ((num < lower) || (num > upper)) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }

    } while ((newLine != '\n') || (num < lower) || (num > upper));

    return num;
}

char inputCharOption(const char array[]){
    char ch;
    do {
        scanf(" %c", &ch);
                
        if (strchr(array, ch) == '\0') {
            printf("ERROR: Character must be one of [%s]: ", array);
        }

    } while (strchr(array, ch) == '\0');
    
   return ch; 
}


void inputCString(char* str, int minchar, int maxchar)
{
    int stringLength;
    int StringValid = 0;
    char inputstr[60] = { '\0' };

    while (!StringValid) {
        scanf("%[^\n]", inputstr);

        stringLength = strlen(inputstr);

        if ((stringLength >= minchar) && (stringLength <= maxchar)) {
            StringValid = 1;
        }

        if (!StringValid) {

            if (minchar == maxchar) {
                printf("ERROR: String length must be exactly %d chars: ", maxchar);
            }
            else {
                if (stringLength < minchar) {
                    printf("ERROR: String length must be between %d and %d chars: ", minchar, maxchar);
                }
                else if (stringLength > maxchar) {
                    printf("ERROR: String length must be no more than %d chars: ", maxchar);
                }
            }
        }
        clearInputBuffer();
    }
    strcpy(str, inputstr);
}

void displayFormattedPhone(const char* pnum)
{
    int i;
    int stringvalid = 1; // boolean


    if (pnum != NULL)
    {
        for (i = 0; pnum[i] != '\0'; i++)
        {
            if (pnum[i] < '0' || pnum[i] > '9')
            {
                stringvalid = 0;
            }
        }

    }
    else
    {
        stringvalid = 0;
    }
    if (strlen(pnum) != 10)
    {
        stringvalid = 0;
    }

    // output
    if (stringvalid == 0)
    {
        printf("(___)___-____");
    }
    else {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            pnum[0],
            pnum[1],
            pnum[2],
            pnum[3],
            pnum[4],
            pnum[5],
            pnum[6],
            pnum[7],
            pnum[8],
            pnum[9]);



    }
}