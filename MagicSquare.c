/*************************************************
* Function Title: MagicSquare
*
* Summary: The user inputs numbers from 1 to 16 in any order, then the numbers are displayed in a 4 by 4 
* arrangement, followed by the sums of the rows, columns, and diagonals. If all the sums are the same, 
* it's a magic square.
*
* Inputs: Keyboard
* Outputs: Monitor
**************************************************
* Pseudocode
*
* Begin
*	Declare n1 through n16 as integers
*	Print instructions
*	Scan numbers and store into n1 through n16
*	Print numbers into 4 by 4 grid
*	Print sum of grid rows
*	Print sum of grid columns
*	Print sum of grid diagonals
* End
**************************************************/

#include <stdio.h>

int main () { // Begin
	// Declare n1 through n16 as integers
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;

	// Print instructions
	printf ("Welcome to Magic Square!\nPlease enter the numbers from 1 to 16 in any order with a space in between each number:\n");
	
	// Scan numbers and store into n1 through n16
	scanf_s ("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
		&n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16); 

	// Print numbers into a 4 by 4 grid
	printf("\n%d \t %d \t %d \t %d\n", n1, n2, n3, n4);   
	printf("%d \t %d \t %d \t %d\n", n5, n6, n7, n8);
	printf("%d \t %d \t %d \t %d\n", n9, n10, n11, n12);
	printf("%d \t %d \t %d \t %d\n \n", n13, n14, n15, n16);

	// Print sum of grid rows
	printf("Row sums: %d %d %d %d\n", (n1 + n2 +n3 + n4), (n5 + n6 + n7 + n8),
		(n9 + n10 + n11 + n12), (n13 + n14 + n15 + n16));

	// Print sum of grid columns
	printf("Column sums: %d %d %d %d\n", (n1 + n5 + n9 + n13), (n2 + n6 + n10 + n14),
		(n3 + n7 + n11 + n15), (n4 + n8 + n12 + n16));


	// Print sum of grid diagonals
	printf("Diagonal sums: %d %d\n\n", (n1 + n6 + n11 + n16), (n4 + n7 + n10 + n13));


	printf("Press any key then enter to exit... \n");
	scanf_s(" ");  // Keep window open

	return 0;
} // End
