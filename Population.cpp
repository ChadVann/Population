/******************************************************************************
* Programmer: Chad Thornton
*
* Assigned Project Number: 6B
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     02/08/2016  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  Asks for four inputs from the user that will be used in calculations
*			Will then ask if the user will want to run the program again.
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   Displays text on the console asking for input. Once input is received
*			the program displays the calculations from the input received by the user.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* **** Add name and description of any other methods defined in this file ****
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file is required by the Visual Studio complier and
// MUST be first in the "include" files list
#include "stdafx.h"  // Defines IDE required "pre-compiled" definition files

#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
// -----------------
void toLower(string&);
char toLower(char);



/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** The user will be required to answer four questions asked by the program
* ** which will be used in calculating the population change over 'x' years.
* ** The program will then display on the console the population for each
* ** year leading up to the total years the user input. After the program
* ** displays the information to the console it will then ask the user if they
* ** want to run the program again.
*
*
* Preconditions
* -------------
* None
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
*                           *** No methods invoked ***
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution Status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors

	// Uninitialized Variable Declarations
	double population,
		birthRate,
		deathRate,
		newPop;
	int numberYears,
		years = 1;
	string endProgram;

	cout << "This program calculates a projected population change.\n" << endl;

	do
	{
		cout << "What is the starting population size?: ";
		cin >> population;
		while (population < 2)
		{
			cout << "\nThe starting population needs to be at least 2." << endl;
			cout << "Please enter the starting population: ";
			cin >> population;
		}

		cout << "\nWhat is the annual birth rate percentage?: ";
		cin >> birthRate;
		while ((birthRate < 0) || (birthRate>100))
		{
			cout << "\nSorry that was not a valid input.\nPlease enter the annual birth rate percentage: ";
			cin >> birthRate;
		}
		birthRate = (birthRate / 100);

		cout << "\nWhat is the annual death rate percentage?: ";
		cin >> deathRate;
		while ((deathRate < 0) || (deathRate>100))
		{
			cout << "\nSorry that was not a valid input.\nPlease enter the annual death rate percentage: ";
			cin >> deathRate;
		}
		deathRate = (deathRate / 100);

		cout << "\nHow many years do you want to calculate?: ";
		cin >> numberYears;
		while (numberYears < 1)
		{
			cout << "\nSorry that was not a valid input.\nYears calculated need to be at least 1";
			cin >> numberYears;
		}

		for (int i = 1; i <= numberYears; i++)
		{
			cout << "Year " << years << " results:\n";
			newPop = population*(1.0 + birthRate)*(1.0-deathRate);
			cout << " Starting population: "<< right<< setw(8) << round(population) << endl;
			cout << " Ending population: " << right << setw(10) << round(newPop) << endl;
			cout << " Population change: " << right << setw(10) << round(newPop - population) << endl;

			population = newPop;
			years++;
		}
		cout << "Would you like to run the program again? (Yes/No)" << endl;
		cin >> endProgram;
		while ((endProgram != "yes") && (endProgram != "no"))
		{
			cout << "Oops, that wasn't a valid answer.\nWould you like to run the program again?(Yes/No)" << endl;
			cin >> endProgram;
				toLower(endProgram);
		}
	} while (endProgram != "no");

		cout << "Thank you for using our program.\nHave a nice day!" << endl;
	

	/*Population should display the starting population and the projected population at the end of each year*/


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()


void toLower(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toLower(str[index]);
}

char toLower(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		unsigned short includeBit = 'a' - 'A';
		chr = chr | includeBit;
	}

	return chr;
}