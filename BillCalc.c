#include <stdio.h>

/*Function Prototypes*/
void pay_amount(int, int*, int*, int*, int*);

/**************************************************
* Function Title: Main
***************************************************
* Summary: Asks the user to enter a U.S. dollar amount and then displays how to 
* pay the amount using the smallest number of $20, $10, $5, and $1 bills.
***************************************************
* Pseudocode
*
* Begin
*	Declare as int: "dollars", "twenties", "tens", "fives", and "ones"
*	Print program instructions
*	Scan for user input and store to dollars
* 	Calculate dollar amounts by calling function: "pay_amount"
* 	Print each bill type with the corresponding quantity	
* End 
**************************************************/
int main ()
{ 																 // Begin
	int dollars, twenties, tens, fives, ones; 			  		 //		Declare as int: "dollars", "twenties", "tens", "fives", and "ones"
	printf("Welcome to BillCalc! \nEnter a dollar amount: "); 	 // 	Print program instructions
	scanf("%d", &dollars);					 			  		 // 	Scan for user input and store to dollars
	pay_amount(dollars, &twenties, &tens, &fives, &ones); 		 // 	Calculate dollar amounts by calling function: "pay_amount"
	printf ("\n$20 bills: %d\n", twenties);				  		 // 	Print each bill type with the corresponding quantity	
	printf ("$10 bills: %d\n", tens);
	printf (" $5 bills: %d\n", fives);
	printf (" $1 bills: %d\n", ones);
	return 0;			
} 																 // End 

/**************************************************
* Function Title: Pay_Amount
***************************************************
* Summary: Determines the smallest number of $20, $10, $5, and $1 bills required to 
* pay the amount specified in the "dollar" parameter, and stores the results into ints
* at the specified addresses.
*
* Inputs: "dollars" (int) and 4 pointers to ints: "*twenties", "*tens", "*fives", and "*ones"
* Outputs: none
***************************************************
* Pseudocode 
*
* Begin
*	Set *twenties to dollars divided by 20
*	Set dollars to equal itself minus the result of 20 times the value of *twenties
*	Set *tens to dollars divided by 10
*	Set dollars to equal itself minus the result of 10 times the value of *tens
*	Set *fives to dollars divided by 5
*	Set dollars to equal itself minus the result of 5 times the value of *fives
*	Set *ones to remaining value of dollars
*	Set dollars to equal itself minus the value of *ones
* End
***************************************************/
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{ 								 // Begin
	*twenties = dollars / 20; 	 // 	Set *twenties to dollars divided by 20
	dollars -= (*twenties * 20); //		Set dollars to equal itself minus the result of 20 times the value of *twenties
	
	*tens = dollars / 10;		 //		Set *tens to dollars divided by 10
	dollars -= (*tens * 10);	 // 	Set dollars to equal itself minus the result of 10 times the value of *tens
	
	*fives = (dollars / 5);		 // 	Set *fives to dollars divided by 5
	dollars -= (*fives * 5);	 // 	Set dollars to equal itself minus the result of 5 times the value of *fives
	
	*ones = dollars;			 // 	Set *ones to remaining value of dollars
	dollars -= *ones;			 // 	Set dollars to equal itself minus the value of *ones
} 								 // End