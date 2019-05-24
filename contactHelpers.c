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
#include <string.h>
#include "contactHelpers.h"
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard()
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause()
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt()
{
	int num_input; //this is return variable
	char  ch;// this char is use to scan enter key.

	scanf("%d%c", &num_input, &ch); //scan number followed by char.
	while (ch != '\n') // loop will continue unti user not press <ENTER> after number.
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &num_input, &ch);
	}

	return num_input;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int low_bound, int up_bound)
{
	int num_input;
	
	num_input = getInt();

	while ((num_input < low_bound) || (num_input > up_bound)) // loop continue until number not between the range.
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low_bound, up_bound);
		scanf("%d", &num_input);
	}

	return num_input;
}


// yes: Empty function definition goes here:
int yes(void)
{
	char ch, dummy; //Ch variable for ans(Y,y,N,n) and dummy for remain char.
	int ans = 1;
	
	scanf("%c%c", &ch, &dummy); //Take a input from user;

	while ((dummy != '\n') || ((ch != 'y') && (ch != 'Y') && (ch != 'N') && (ch != 'n')))
	{
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		clearKeyboard();
		scanf("%c%c", &ch, &dummy);
	}

	if ((ch == 'y') || (ch == 'Y') )
		ans = 1;
	else
		ans = 0;

	return ans;
}


// menu: Empty function definition goes here:
int menu(void)
{
	//this function displat menu
	/*
	Contact Management System<
	>-------------------------< (there are 25 dashes)
	>1. Display contacts<
	>2. Add a contact<
	>3. Update a contact<
	>4. Delete a contact<
	>5. Search contacts by cell phone number<
	>6. Sort contacts by cell phone number<
	>0. Exit<
	><
	>Select an option:> <
	*/


	int option;
	printf("Contact Management System");
	printf("\n-------------------------");
	printf("\n1. Display contacts");
	printf("\n2. Add a contact");
	printf("\n3. Update a contact");
	printf("\n4. Delete a contact");
	printf("\n5. Search contacts by cell phone number");
	printf("\n6. Sort contacts by cell phone number");
	printf("\n0. Exit");
	printf("\n");
	printf("\nSelect an option:> ");

	scanf("%d", &option);

	while (option < 0 || option > 6)
	{
		printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		scanf("%d", &option);
	}

	printf("\n");
	return option;
}


// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] = { 
		{ 
			{ "Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" }
		
		},
		{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" }
		},
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } 
		},
		{
			{ "Sasha",{ '\0' }, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } 
		}
	};

	char ans = 'n';

	do
	{
		int user_option = menu();
		clearKeyboard();
		switch (user_option)
		{
		case 1:
			//printf("\n<<< Feature %d is unavailable >>>\n\n", user_option);
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			//printf("\n<<< Feature %d is unavailable >>>\n\n", user_option);
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			//printf("\n<<< Feature %d is unavailable >>>\n\n", user_option);
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			//printf("\n<<< Feature %d is unavailable >>>\n\n", user_option);
			deleteContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			//printf("\n<<< Feature %d is unavailable >>>\n\n", user_option);
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			//printf("\n<<< Feature %d is unavailable >>>\n\n", user_option);
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			scanf(" %c",&ans);
			break;
		}

		printf("\n");
	} while ((ans == 'N') || (ans == 'n')); //(ans == 'y') || (ans == 'Y')
	

	if ((ans == 'y') || (ans == 'y'))
	{
		printf("Contact Management System: terminated\n");
	}
}



// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+



/*
	+-----------------------------------------------------------------------------+
	|                              getTenDigitPhone					              |
	+-----------------------------------------------------------------------------+

This function receives user input for a 10-digit phone number and stores the value to the parameter telNum. ---!!>
*/
void getTenDigitPhone(char telNum[11])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}




/*
	+-----------------------------------------------------------------------------+
	|                              findContactIndex					              |
	+-----------------------------------------------------------------------------+

This function’s purpose is to find a contact based on the provided cell phone number (parameter 3)
and return the index (position in the array) otherwise, if the contact is not found, the function should return -1
*/
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int index, i = 0, flag = 0;

	for (i = 0; i < size && !flag; i++)
	{
		// string function compare two string
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			index = i;
			flag = 1;
		}
		else 
			index = -1;
	}

	return index;
}




/* 
	+-----------------------------------------------------------------------------+
	|                              displayContactHeader                           |
	+-----------------------------------------------------------------------------+
	
	This function display’s a centered title “Contacts Listing” header that is surrounded in a border: --!!> 
*/
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}




/*
	+-----------------------------------------------------------------------------+
	|                              displayContactFooter                           |
	+-----------------------------------------------------------------------------+

	This function display’s a line and a total contact summary
*/
void displayContactFooter(int total_contacts)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", total_contacts);
}





/*
	+-----------------------------------------------------------------------------+
	|                              displayContact					              |
	+-----------------------------------------------------------------------------+

	This function displays the details for a single contact (see example below):

	Example: With middle initial and an apartment number:
		Maggie R. Greene [line-1]
			C: 9051112222 H: 9052223333 B: 9053334444 [line-2]
				55 Hightop House, Apt# 201, Bolton, A9A 3K3 [line-3]

	Example: No middle initial and no apartment number:
		Maggie Greene [line-1]
			C: 9051112222 H: 9052223333 B: 9053334444 [line-2]
				55 Hightop House, Bolton, A9A 3K3 [line-3]
*/

void displayContact(const struct Contact* contact)
{
	//display contact full name
	printf(" %s", contact->name.firstName);

	if(strlen(contact->name.middleInitial) > 0)
		printf(" %s", contact->name.middleInitial);

	printf(" %s\n", contact->name.lastName);


	//display contact numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	//display contact Address
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber)
		printf("Apt# %d, ", contact->address.apartmentNumber);

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}





/*
	+-----------------------------------------------------------------------------+
	|                              displayContacts					              |
	+-----------------------------------------------------------------------------+

	This function needs to display a title header, a detail listing of each VALID contact in the array and a footer section showing the total number of contacts.
*/
void displayContacts(const struct Contact contacts[] , int size)
{
	int i = 0, count = 0;

	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		//string function check that cell length is grater than zero !!!
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}

	displayContactFooter(count);
	printf("\n");
}






/*
	+-----------------------------------------------------------------------------+
	|                              searchContacts					              |
	+-----------------------------------------------------------------------------+

	This function should prompt the user to search the contact listings based on a cell phone number. If there is a match, display the details for the contact.
*/
void searchContacts(const struct Contact contacts[], int size)
{
	char cell_num[11];
	int index;
	
	//take cell number from user
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell_num);
	
	//find the index of user input number.
	index = findContactIndex(contacts, size, cell_num);

	// index foud than display contact details otherwise go to else case
	if (index >= 0)
	{
		printf("\n");
		displayContact(&contacts[index]);
	}
	else
		printf("*** Contact NOT FOUND ***");

	printf("\n");
}





/*
	+-----------------------------------------------------------------------------+
	|                              addContact					              |
	+-----------------------------------------------------------------------------+

	This function should first determine if there is an available slot (empty index) in the contact array. if space is avaliable than add new contacts
*/
void addContact(struct Contact contacts[], int size)
{
	int index, i, flag = 0;

	for (i = 0; i < size && !flag; i++)
	{
		//string function check that lenght of cell number is eual to zero.
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			index = i;
			flag = 1;
		}
		else
			index = -1;
	}

	//if index found than add new contact on that place otherwise go to else case
	if (index >= 0)
	{
		getContact(&contacts[index]);
		printf("--- New contact added! ---\n");
	}
	else
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
}






/*
	+-----------------------------------------------------------------------------+
	|                              updateContact					              |
	+-----------------------------------------------------------------------------+	

This function should prompt the user for the cell phone number of the contact to update. if contact found than ask for updation
*/
void updateContact(struct Contact contacts[], int size)
{
	char cell_num[11];
	int index;
	struct Contact temp = { { { 0 } } };

	//take user input
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell_num);

	//find the index of user value
	index = findContactIndex(contacts, size, cell_num);

	//if records contain value than update contact otherwise go to else case
	if (index >= 0)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[index]);

		printf("\nDo you want to update the name? (y or n): ");
		if (yes())
		{
			//befor insert new value replace old value with empty value.
			contacts[index].name = temp.name;
			
			//take user input for name
			getName(&contacts[index].name);
		}
		
		printf("Do you want to update the address? (y or n): ");
		clearKeyboard();
		if (yes())
		{
			//befor insert new value replace old value with empty value.
			contacts[index].address = temp.address;

			//take user input for address
			getAddress(&contacts[index].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		clearKeyboard();
		if (yes())
		{
			//befor insert new value replace old value with empty value.
			contacts[index].numbers = temp.numbers;

			//take user input for number
			getNumbers(&contacts[index].numbers);
		}

		printf("--- Contact Updated! ---");
	}
	else
		printf("*** Contact NOT FOUND ***");

	printf("\n");
}






/*
	+-----------------------------------------------------------------------------+
	|                              deleteContact					              |
	+-----------------------------------------------------------------------------+

This function should prompt the user for the cell phone number of the contact to delete from the list. if contact found than take conformation
*/
void deleteContact(struct Contact contacts[], int size)
{
	char cell_num[11];
	int index;
	struct Contact temp = { { { 0 } } };
	
	//take user input
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell_num);
	
	//find index for user value
	index = findContactIndex(contacts, size, cell_num);


	//if records containt same cell number than delete otherwise go to else case
	if (index >= 0)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[index]);

		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes())
		{
			contacts[index] = temp;
			//*contacts[index].numbers.cell = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
	else
		printf("*** Contact NOT FOUND ***\n");

	
}





/*
	+-----------------------------------------------------------------------------+
	|                              sortContacts						              |
	+-----------------------------------------------------------------------------+

This function reorders the elements in the contacts array from lowest to highest based on the cell phone numbers.
*/
void sortContacts(struct Contact contacts[], int size)
{
	int i = 0, j = 0;
	struct Contact temp;
	

	//below loop sort contact array base on the cell numbers
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) 
			{
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}


	printf("--- Contacts sorted! ---\n");
	
}
