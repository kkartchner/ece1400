/*************************************************
* Function Title: IntRanker
*
* Summary: Finds the largest and smallest of four integers entered by the user
*
* Inputs: Keyboard
* Outputs: Monitor
**************************************************
* Pseudocode
*
* Begin
*	Declare currentNum, smallestNum, and largestNum as integers
*	Print program instructions
*	Scan first number and store into currentNum
*	Set smallestNum and largestNum to currentNum
*	Declare i as int and set to 1
*	Loop
*		Scan number and store into currentNum
*		If currentNum is greater than largestNum
*			Set largestNum to currentNum
*		Else
*			If currentNum is less than smallestNun
*				Set smallestNum to currentNum
*			End If
*		End If
*		Add one to i
*	End Loop if i equals the number of allowable ints (INT_NUM)
*	Print message with largestNum
*	Print message with smallestNum
* End
**************************************************/

#define INT_NUM 4
#include <stdio.h>

int main()
{ // Begin
	int currentNum, smallestNum, largestNum; // Declare currentNum, smallestNum, and largestNum as integers

	printf("Welcome to IntRanker! \nPlease enter four integers: "); // Print program instructions

	scanf("%d", &currentNum); // Scan first number and store into currentNum
	smallestNum = largestNum = currentNum; // Set smallestNum and largestNum to currentNum
	// Declare i as int and set to 1
	// Loop
		for (int i = 1; i < INT_NUM; i++)
		{
		  scanf("%d", &currentNum); // Scan number and store into currentNum
		  if (currentNum > largestNum)
		  { // If currentNum is greater than largestNum
			  largestNum = currentNum; // Set largestNum to currentNum
		  }
		  else if (currentNum < smallestNum) 
		  { // Else 
				//If currentNum is less than smallestNum
			  smallestNum = currentNum; // Set smallestNum to currentNum
				// End If
		  } // End If
		// Add one to i
		}
	// End Loop if i equals 4

	printf("Largest number: %d\n", largestNum); // Print message with largestNum
	printf("Smallest number: %d\n", smallestNum); // Print message with smallestNum

	return 0;
} // End