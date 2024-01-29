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

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// Display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* pnum);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// 3. Get user input of int type and validate for a number. 
// Display an error message if an invalid value is entered   
int inputInt();

// 4. Display an error message if the value is a zero or less and prompt for a value until it is greater that 0
int inputIntPositive();

// 5. Display an error message if the value is outside the permitted range 
// continue to prompt for a value until a value is between the permitted range
int inputIntRange(int lower, int upper);

// 6. Display an error message if the entered character value is not in the list of valid characters
// Include in the error message the C string permitted characters
char inputCharOption(const char array[]);

// 7. Must continue to prompt for a C string value until a valid length is entered
void inputCString(char* str, int minchar, int maxchar);
















// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
