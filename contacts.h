// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------


/* -------------------------------------------
Name: Mehulkumar Desai
Student number: 110288172
Email: mmdesai@myseneca.ca
Section: IPC144SOO
Date: 5-Dec-2017
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */


//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
//Structure Address has five(5) members:  street, streetNumber, apartmentNumber, postalCode, and city.
struct Address
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration
// NOTE: Modify the C String arrays sizes according to the
// Assignment-2 Milestone-1 specifications
//Structure Numbers has three (3) members:  cell, home, and business. 
struct Numbers
{
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};



//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Get and store from standard input the values for Name
void getName(struct Name *);


// Get and store from standard input the values for Address
void getAddress(struct Address *);


// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *);


// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact *);


// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_