#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/* Function Prototypes */
bool is_palindrome(char*);
void reformat_phrase(char*);

/*************************************************
* Function Title: main
*
* Summary: Asks the user to input a string of characters, checks to see if the 
* entered phrase is a palindrome, then prints the result.
*
* Inputs: none
* Outputs: none
**************************************************
* Psuedocode
*
* Begin
*	Declare "phrase" as size (MAX_LENGTH-1) char array: 
*	Print program instructions
*	Scan for string and store into phrase
*	Reformat phrase to remove any non-letter characters including spaces.
*	If phrase is a palindrome (check using bool function "is_palindrome")
*		Print palindrome message
*	Else
*		Print not palindrome message
*	End If
* End 
**************************************************/
int main()
{ // Begin
	char phrase[MAX_LENGTH+1], *temp = phrase;					  	// Declare "phrase" as size (MAX_LENGTH-1) char array: 
	printf("Welcome to Pali-Checker! \nEnter a phrase to check: "); // Print program instructions
	gets(phrase); 													// Scan for string and store into phrase
	reformat_phrase(phrase); 										// Reformat phrase to remove any non-letter characters including spaces.
	if (is_palindrome(phrase)) {									// If phrase is a palindrome (check using bool function "is_palindrome")
		printf("Palindrome!"); 											// Print palindrome message
	} else {														// Else
		printf("Not a palindrome."); 									// Print not palindrome message
	}																// End If
	return 0;
} // End 

/*************************************************
* Function Title: is_palindrome
*
* Summary: Checks to see if the provided string is a palindrome by using two pointers - one
* starting from the left side and one from the right - and comparing their values to each other
* 
* Input:  *phrase (char*, the phrase to check)
* Output: bool (true if palindrome; false if not)
**************************************************
* Psuedocode
*
* Begin
*	Declare "p" as "q" as pointers to a char
*	Loop (p = address of first index of phrase, q = last index of phrase; p <= q; p++, q--)
*		If the value at p is not equal to the value at q	
*			Return false
*		End If
*	End Loop	
*	Return true
* End
**************************************************/
bool is_palindrome(char *phrase)
{ // Begin
	char *p, *q;				// Declare "p" as "q" as pointers to a char
	for (p = phrase, q = (phrase) + strlen(phrase)-1; p < q; p++, q--)
	{  							// Loop (p = address of first index of phrase, q = last index of phrase; p <= q; p++, q--)			
		if (*p != *q){				// If the value at p is not equal to the value at q	
			return false;				// Return false
		}							// End If
	}						    // End Loop	
	return true;				// Return true as default
} // End

/*************************************************
* Function Title: reformat_phrase
*
* Summary: Because punctuation, case, and spacing should be ignored when checking for palindromes, 
* the phrase is reformatted (to be all lowercase letters and to exclude spaces and other non-letter 
* characters) by using two pointers to shift over the letter characters to cover up non-letter ones.

* Input:  *phrase (char*; the phrase to be reformatted)
* Output: none
**************************************************
* Psuedocode
*
* Begin
* 	Declare "a" as a char pointer that points to phrase
*	Loop (while the phrase hasn't ended, meaning the current char is not the null char)
*		 Set the char that "a" points to to equal the lowercase version of the char that "phrase" points to
*		 If the new value at a is a lowercase letter
*			Shift a to point to the next char in line, otherwise do nothing to keep it where it's at
*		 End If
* 	End Loop
* End
**************************************************/
void reformat_phrase(char *phrase)
{ // Begin
	char *a = phrase;					 // Declare "a" as a char pointer that points to phrase
	do { 						 		 // Loop (while the phrase hasn't ended, meaning the current char is not the null char)
		*a = tolower(*phrase); 			 	 // Set the char that "a" points to to equal the lowercase version of the char that "phrase" points to									
		if('a' <= *a && *a <= 'z'){ 		 // If the new value at a is a lowercase letter
			a++; 						 	  	// Shift a to point to the next char in line, otherwise do nothing to keep it there
		}									 // End If
	} while(*phrase++ != '\0');			// End Loop
} // End


