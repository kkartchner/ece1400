/*************************************************
* Function Title: SquareRooter
*
* Summary: Calculates the square root of a number entered by the user
* using Newton's method for estimating square roots.
*
* Inputs: Keyboard
* Outputs: Monitor
**************************************************
* Pseudocode
*
* Begin
*	Define as double: num, y, and y_old
*	Set y to 1 and y_old to 0
*	Print program instructions
*	Scan for double and store to num
	If num is positive
*		Loop (While the absolute value of the difference of y and y_old is greater than the product of .00001 and y)
*			Set y_old to y
*			Set y to the sum of y plus the quotient of x and y, divided by two
*		End Loop
*		Print message with the final value of y	
*	Else
*		Print error message
*	End If	
* End
**************************************************/

#include <stdio.h>
#include <math.h>

int main ()
{ // Begin
	double num, y = 1, y_old = 0;   // Define as double: num, y, and y_old // Set y to 1 and y_old to 0
	
	printf ("Welcome to SquareRooter! \nPlease enter a number: ");   // Print program instructions
	scanf ("%lf",  &num);   // Scan for double and store to num
	if (num >= 0) 
	{ // If num is positive
		while (fabs(y - y_old) > .00001 * y)  
		{ // Loop (While the absolute value of the difference of y and y_old is greater than the product of .00001 and y)
			y_old = y;   // Set y_old to y
			y = (y + (num / y)) / 2;   // Set y to the sum of y plus the quotient of x and y, divided by two
		} // End Loop
		printf ("The square root is: %.10g", y);   // Print message with the final value of y	
	} 
	else
	{ // Else
		printf ("Negative number. Square root does not exist.");   // Print error message
	} // End If
	
	return 0;
} // End
