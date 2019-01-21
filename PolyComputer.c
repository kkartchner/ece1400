/*************************************************
* Function Title : Main
*
* Summary : Computes and prints the value of the polynomial "3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6", with the value
*	of x being entered by the user
*
* Inputs : none
* Outputs : none
**************************************************
* Pseudocode
*
* Begin
*	Declare "x" as double
*	Print program instructions
*	Scan for double and store to x
*	Compute and print the value of the polynomial
*	Keep results open
* End
**************************************************/


#include <stdio.h>
#include <math.h>

double compute_polynomial(double x);


int main()
{ // Begin
	double x;																				// Declare "x" as double

	printf("Welcome to PolyComputer! \nTo compute 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6");		// Print program instructions
	printf ("\nEnter a value for x: ");		
	
	scanf_s("%lf", &x);																		// Scan for double and store to x
	printf("\nThe value of the polynomial is: %g", compute_polynomial(x));					// Compute and print the value of the polynomial
															
	getchar();	getchar();																	// Keep results open
											
	return 0;
} // End



/**************************************************
* Function Title : Compute_Polynomial
* 
* Summary : Computes the polynomial and returns its value
*
* Inputs : x(a double providing the value for x)
* Outputs : double containing the value of the polynomial
***************************************************
* Pseudocode
*
* Begin
*	Return computed value of (3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6);
* End 
**************************************************/

double compute_polynomial(double x)
{ // Begin
	return (3 * pow(x, 5)) + (2 * pow(x, 4)) - (5*pow(x, 3)) - pow(x, 2) + (7 * x) - 6;		// Return computed value of (3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6);
} // End