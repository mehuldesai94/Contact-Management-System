/* ------------------------------------------------------------------
Name: Mehulkumar Desai
Student number: 110288172
Email: mmdesai@myseneca.ca
Section: IPC144SOO
Date: 5-Dec-2017
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.

#include "contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt();

// getIntInRange:
int getIntInRange(int, int);

// yes:
int yes();

// menu:
int menu();

// ContactManagerSystem:
void ContactManagerSystem(void);

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put new function prototypes below...            |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
// below does not return a value and expects a character array sized for 10 characters plus the null terminator.
void getTenDigitPhone(char[11]);

// findContactIndex (provided for you) 
// this function returns an integer and expects a Contact array (marked constant so changes can’t be made to it), an integer, and a character array.
int findContactIndex(const struct Contact[], int, const char[]);


// displayContactHeader
// this function does not return a value and has no parameters but its print header.
void displayContactHeader(void);


// displayContactFooter:
// this function does not return a value and receives one integer parameter (How many contacts array containts).
void displayContactFooter(int);


// displayContact:
// this function does not return a value and receives a constant Contact pointer (cannot be updated) parameter.
void displayContact(const struct Contact*);


// displayContacts:
// this function does not return a value and receives a constant Contact array (cannot be updated), and an integer for parameters.
void displayContacts(const struct Contact[], int);


// searchContacts:
// this function does not return a value and receives a constant Contact array (cannot be updated), and an integer for parameters.
void searchContacts(const struct Contact[], int);


// addContact:
//this function does not return a value and receives a Contact array, and an integer for parameters.
void addContact(struct Contact[], int);


// updateContact:
// this function does not return a value and receives a Contact array, and an integer for parameters.
void updateContact(struct Contact[], int);


// deleteContact:
// this function does not return a value and receives a Contact array, and an integer for parameters
void deleteContact(struct Contact[], int);

// sortContacts:
// this function does not return a value and receives a Contact array, and an integer for parameters.
void sortContacts(struct Contact[], int);