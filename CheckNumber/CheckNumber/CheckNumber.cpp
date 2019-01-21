/*************************************************
* Function Title: CheckNumber
*
* Summary: The user inputs the first 12 numbers of an EAN barcode then the corresponding check 
number is calculated and displayed.
*
* Inputs: Keyboard
* Outputs: Monitor
**************************************************
* Pseudocode
*
* Begin
*	Declare "first_sum", "second_sum", "total", "check_number", and "d1" through "d12" as integers
*	Print beginning instructions
*	Scan digits and store into d1 through d12
*	Set value of first_sum to the sum of d2, d4, d6, d8, d10, and d12
*	Set value of second_sum to the sum of d1, d3, d5, d7, d9, and d11
*	Set value of total to the product of first_sum and 3, plus second_sum
*	Subtract 1 from the total and compute the remainder when the result is divided by 10
*	Subtract the remainder from 9 and store result into check_number
*	Print check_number and check number message
* End
**************************************************/

#include "stdafx.h"
#include <stdio.h>

int main()
{ // Begin
	int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12; // Declare "first_sum", "second_sum", "total", "check_number", and "d1" through "d12" as integers
	int first_sum, second_sum, total, check_number;

	printf("Welcome to CheckNumber! \nPlease enter the first 12 digits of EAN Barcode: "); // Print beginning instructions
	scanf_s("%1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d", 
		&d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12); // Scan digits and store into d1 through d12

	first_sum = d2 + d4 + d6 + d8 + d10 + d12; // Set value of first_sum to the sum of d2, d4, d6, d8, d10, and d12
	second_sum = d1 + d3 + d5 + d7 + d9 + d11; // Set value of second_sum to the sum of d1, d3, d5, d7, d9, and d11
	total = (first_sum * 3) + second_sum; 	// Set value of total to the product of first_sum and 3, plus second_sum
	total = (total - 1) % 10; // Subtract 1 from the total and compute the remainder when the result is divided by 10
	check_number = 9 - total; 	// Subtract the remainder from 9 and store result into check_number

	printf("The check number is: %d\n\n", check_number); 	// Print check_number and check number message

    return 0;
} //End

