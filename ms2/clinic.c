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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++) { 
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
        }
    }
    putchar('\n');
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max) {

    int selection;

do {
    printf("Search Options\n");
    printf("==========================\n");
    printf("1) By patient number\n");
    printf("2) By phone number\n");
    printf("..........................\n");
    printf("0) Previous menu\n");
    printf("..........................\n");
    printf("Selection: ");
    selection = inputIntRange(0, 2);
    putchar('\n');
    switch (selection)
    {
    case 1:
        searchPatientByPatientNumber(patient, max);
        suspend();
        break;
    case 2:

        searchPatientByPhoneNumber(patient, max);
        suspend();
        break;
    }

} while (selection !=0);

}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max)
{

    int i;
    int newPatientIndex = -1, nextAvailablePatientNumber;

    for (i = 0; (i < max) && newPatientIndex == -1; i++) 
    { 
        if (patient[i].patientNumber == 0) 
        {
            newPatientIndex = i; //if patientNum is = 0 setting newPatientIndex to the current array 
        }
    }
    if (newPatientIndex == -1) // if empty elements not found
    { 
        printf("ERROR: Patient listing is FULL!\n");
    }
    else {
        nextAvailablePatientNumber = nextPatientNumber(patient, max); 
        patient[newPatientIndex].patientNumber = nextAvailablePatientNumber; 
        inputPatient(&patient[newPatientIndex]);
        printf("*** New patient record added ***\n");
    }

    putchar('\n');
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max)
{   
    int patientNumber, patientIndex;

    printf("Enter the patient number: ");
    scanf(" %d", &patientNumber);
    putchar('\n');

    patientIndex = findPatientIndexByPatientNum(patientNumber, patient, max);
    if (patientIndex == -1) { //means the patient with given num was not found
        printf("ERROR: Patient record not found!\n");
    }
    else { 
        menuPatientEdit(&patient[patientIndex]);
    }
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int max)
{
    int patientNumber, patientIndex;
    char selection;
    printf("Enter the patient number: ");
    scanf(" %d", &patientNumber);
    putchar('\n');

    patientIndex = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (patientIndex == -1) 
    {
        printf("ERROR: Patient record not found!\n");
}
    else // valid patient wasn't found
    {
        displayPatientData(&patient[patientIndex], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        selection = inputCharOption("yn");

        switch (selection) {
        case 'n':
            printf("Operation aborted.\n");
            break;
        case 'y': //confirmation of removing state
                patient[patientIndex].patientNumber = 0;
                strcpy(patient[patientIndex].name, "\0");
                strcpy(patient[patientIndex].phone.description, "\0");
                strcpy(patient[patientIndex].phone.number, "\0");
                printf("Patient record has been removed!\n");
        }
    } clearInputBuffer();
    putchar('\n');
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber, patientIndex;
    printf("Search by patient number: ");
    scanf(" %d", &patientNumber);
    putchar('\n');

    patientIndex = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (patientIndex == -1) //patientNumber not found
    {
        printf("*** No records found ***\n");
    }
    else {
        displayPatientData(&patient[patientIndex], FMT_FORM);
    }
    putchar('\n');
    clearInputBuffer();
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPhoneNumber(const struct Patient patient[], int max) 
{
    char phoneNumber[PHONE_LEN + 1];
    int i, phoneSearch = 0;

    printf("Search by phone number: ");
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    putchar('\n');

    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
            phoneSearch = 1;
        }
    }

    if (phoneSearch == 0) 
    {
        printf("\n*** No records found ***\n");
    }
    else {
        for (i = 0; i < max; i++) {
            if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
                displayPatientData(&patient[i], FMT_TABLE);
            }
        }
    }
    putchar('\n');
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int highestPatientNumber = 0, i; // check if pat num index is higher than the highestPatientNumber to change highestPatientNumber to that one.
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > highestPatientNumber)
        {
            highestPatientNumber = patient[i].patientNumber;

        }
    }  
    return (highestPatientNumber + 1);
}



// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max) {
{
    int i;

    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
            return i; //return to matching index
    }
}
return -1; //if matches not found
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN +1);
    putchar('\n');

    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone)
{
    int selection;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);

    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        printf("\nContact: CELL\n");
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("\nContact: HOME\n");
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("\nContact: WORK\n");
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "\0");
        break;


    }
    putchar('\n');
}

