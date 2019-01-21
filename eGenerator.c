/*************************************************
* Function Title: eGenerator
*
* Summary: Computes e to the number of digits entered by the user
*
* Inputs: Keyboard
* Outputs: Monitor
**************************************************
* Pseudocode
*
* Begin
*	Declare as integer n, i, and j
*	Declare as double e and n_factorial and set e to one
*	Print program instructions
*	Scan input for integer and store to n
*	Set i to 1
*	Loop (n times)
*		Set j to 1
*		Set n_factorial to 1
*		Loop (i times)
*			Set n_factorial to itself times j
*			Add one to j
*		End Loop if j is greater than i
*		Set e to itself plus one divided by n_factorial
*		Add one to i
*	End Loop if i greater than n
*	Print message with final value of e
* End
**************************************************/

#include <stdio.h>

int main ()
{	// Begin
		short int n, i, j; 					// Declare as integer n, i, and j
		double e = 1, n_factorial;			// Declare as double e and n_factorial and set e to one
											// Print program instructions						
		printf ("Welcome to eGenerator!	\n");
		printf ("e will be approximated by using the infinite series 1 + 1/1! + ... + 1/n!\n");
		printf ("Enter the number for n: ");		
		scanf ("%d", &n);					// Scan input for integer and store to n
		
		for (i = 1; i <= n; i++) 			// Set i and j to 1 // Add one to i
		{									// Loop (n times)
			n_factorial = 1;					// Set n_factorial to 1
			for (j = 1; j <= i; j++)			// Set j to 1 // Add one to j
			{									// Loop (i times)
				n_factorial *= j;					// Set n_factorial to itself times j
			}									// End Loop if j is greater than i	
			e = e + (1 / n_factorial); 		// Set e to itself plus one divided by n_factorial
		}									// End Loop if i greater than n
		printf ("e: %.50g", e);			// Print message with final value of e
	return 0;
} 	// End