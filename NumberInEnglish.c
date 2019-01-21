/*************************************************
* Function Title:	NumberInEnglish
*
* Summary: Asks the user for a two-digit number and then prints the English word for that number.
*
* Inputs: Keyboard
* Outputs: Monitor
**************************************************
* Pseudocode
*
* Begin
*	Declare digit1 and digit2 as integers
*	Print program instructions
*	Scan for number and store first and second digits to digit1 and digit2 repectively
*	Print a message to be followed by the number in english
*	If digit1 equals one
*		Check the value of digit2 and print the english word for the combined number of digit1 and digit2 (e.g. "ten", "nineteen", etc.)
*	Else
*		Check the value of digit1 and print its english word equivalent (e.g. "twenty", "ninety", etc.)
*		If digit2 is not equal to zero
*			Print a hyphen at the end of the first digit word
*			Check the value of digit2 and print its english word equivalent (e.g. "one", "nine")
*		End If
*	End If
*	Print a period at the end of the sentence
* End
**************************************************/

#include <stdio.h>

int main ()
{ // Begin
	int digit1, digit2;		//	Declare digit1 and digit2 as integers

	printf("Welcome to NumberInEnglish! \nPlease enter a two-digit number: "); 	//	Print program instructions
	scanf("%1d %1d", &digit1, &digit2); // Scan for number and store the first and second digits to digit1 and digit2 repectively

	printf("You entered the number ");  //	Print a message to be followed by the number in english
	
	if (digit1 == 1)
	{ // If digit1 equals one
		switch (digit2) // Check the value of digit2 and print the english word for the combined number of digit1 and digit2 (e.g. "ten", "nineteen")
		{
			case 0: printf("ten"); break;
			case 1: printf("eleven"); break;
			case 2: printf("twelve"); break;
			case 3: printf( "thirteen"); break;
			case 4: printf("fourteen"); break;
			case 5: printf("fifteen"); break;
			case 6: printf("sixteen"); break;
			case 7: printf("seventeen"); break;
			case 8: printf("eighteen"); break;
			case 9: printf("nineteen"); break;
		}
	}
	else 
	{ // Else 
		switch (digit1) // Check the value of digit1 and print its english word equivalent (e.g. "twenty", "ninety", etc.)
		{
			case 2: printf("twenty"); break;
			case 3: printf("thirty"); break;
			case 4: printf("forty"); break;
			case 5: printf("fifty"); break;
			case 6: printf("sixty"); break;
			case 7: printf("seventy"); break;
			case 8: printf("eighty"); break;
			case 9: printf("ninety"); break;
		} 
		
		if (digit2) 
		{	// If digit2 is not equal to zero
			printf("-"); 	// Print a hyphen at the end of the first digit word
			switch (digit2) // Check the value of digit2 and print its english word equivalent (e.g. "one", "nine")
			{   
				case 1: printf("one"); break;
				case 2: printf("two"); break;
				case 3: printf("three"); break;
				case 4: printf("four"); break;
				case 5: printf("five"); break;
				case 6: printf("six"); break;
				case 7: printf("seven"); break;
				case 8: printf("eight"); break;
				case 9: printf("nine"); break;
			}
		}	// End If
	} // End If	

	printf(".\n"); // Print a period at the end of the sentence
	return 0;
} // End
