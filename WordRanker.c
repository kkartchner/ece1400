#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************************
* Function Title: Main
*
* Summary: Asks the user to enter a series of words (no more than 20 letters long), and then finds
* the "smallest"  and "largest" of the words based on which would come first alphabetically.
*
* Input: argc (int) and argv (**char) for determining the number of words to have the user enter
* Output: none
**************************************************
* Pseudocode
*
* Begin
*	Declare "smallest_word", "largest_word", and "new_word" as char[20 + 1]
*	Declare "word_num" as int and set to equal argv[1] converted to an int
*	Print program instructions
*	Scan for a string and copy into smallest_word and largest_word
*	Loop N times (with N equaling word_num; using int i = 1 as incrementer)
*		Print message followed by the value of i + 1
*		Scan for string and store to new_word
*		If new_word is smaller than smallest_word (strcmp < 0)
*			Copy new_word into smallest_word
*		Else 
*			If new_word is larger than largest_word
*				Copy new_word into largest_word
*			End If
*		End If
*	End Loop
*	Print largest and smallest word
* End
**************************************************/
int main (int argc, char **argv)
{ // Begin
	char smallest_word[20+1], largest_word[20+1], new_word[20+1]; 	// Declare "smallest_word", "largest_word", and "new_word" as char[20 + 1]
	int word_num = atoi(argv[1]); 				 	  		  		// Declare "word_num" as int and set to equal argv[1] converted to an int
	
	printf("Welcome to WordRanker!\n"				 				// Print program instructions
		   "You will be entering %d words (no longer than 20 letters each).\n" 
		   "Enter word 1: ", word_num); 
	stpcpy(smallest_word, gets(largest_word));				 		// Scan for a string and copy into smallest_word and largest_word
	
	for (int i = 1; i < word_num; i++) { 	     	  				// Loop N times (with N equaling word_num; using int i = 1 as incrementer)
		printf("Enter word %d: ", i + 1);			 		  			// Print message followed by the value of i + 1
		gets(new_word);									  				// Scan for string and store to new_word
		if (strcmp(new_word, smallest_word) < 0) {		  				// If new_word is smaller than smallest_word (strcmp < 0)
			stpcpy(smallest_word, new_word);			      				//  Copy new_word into smallest_word
		} else { 										  				// Else 
			if (strcmp(new_word, largest_word) > 0) {						// If new_word is larger than largest_word
				strcpy(largest_word, new_word);									// Copy new_word into largest_word
			}																// End If
		}																// End If
	}																// End Loop
	printf ("\nSmallest word: %s\n"									// Print largest and smallest word	
			"Largest word: %s\n", smallest_word, largest_word);	

} // End

	