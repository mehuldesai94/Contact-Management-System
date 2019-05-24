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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName: function take user input for Name(fname, lname, mname)
void getName(struct Name *user_name)
{
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", user_name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");	
	//if user enter the Yes(y) than and than only below condition exicute.
	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", user_name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", user_name->lastName);

}

// getAddress: function take address from user.
void getAddress(struct Address *user_address)
{
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	user_address->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", user_address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	clearKeyboard();

	//if user enter the Yes(y) than and than only below condition exicute.
	if (yes())
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &user_address->apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", user_address->postalCode);


	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", user_address->city);
}


// getNumbers: function take user numbers as input
void getNumbers(struct Numbers *user_numbers)
{

	// Contact Numbers Input:
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(user_numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	//if user enter the Yes(y) than and than only below condition exicute.
	if (yes())//(ans == 'y') || (ans == 'Y'))
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(user_numbers->home);
	}


	printf("Do you want to enter a business phone number? (y or n): ");
	//if user enter the Yes(y) than and than only below condition exicute.
	if (yes())//(ans == 'y') || (ans == 'Y'))
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(user_numbers->business);
	}
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *user_contact)
{
	getName(&user_contact->name); //call getName function
	getAddress(&user_contact->address); //call getAddress function
	getNumbers(&user_contact->numbers);// call getNumber function
}
