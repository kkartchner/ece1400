#include "myLinkedList.h"
#include <math.h>

/***************************************************************************************
* main: Reads in integers with value zero or greater from an input file then writes 
the integers and corresponding base 10 logarithms in ascending order to an output file.
****************************************************************************************
Psuedocode

Begin
	Declare variables to be used
	Check for 3 arguments on command line
		If there is an error with the command-line
			Print error message and terminate the program
		End If
	Try to open the input file for reading
		If there is an error 
			Print an error message and terminate the program
		End If
	Try to open the output file for writing
		If there is an error 
			Print an error message and terminate the program
		End If
	Read in integers from the input file
		Loop
			Scan the input file for an integer 
				Add the integer to proper place in linked list
			End Loop
	Print integers with accompanying log to output file
		Loop through entire linked list
			Print integer and log10 to output file
			Free the previous node from memory
		End Loop
	Close both files
	Print program execution success message
End
****************************************************************************************/
int main (int argc, char* argv[])
{ 																				// Begin
	FILE *input_fp, *output_fp;														// Declare variables to be used
	struct node *list_of_ints = NULL, *cur, *prev;
	int cur_int;
																					// Check for 3 arguments on command line
	if (argc != 3){																		// If there is an error with the command-line
		printf ("Invalid number of arguments:\n" 										// 		Print error message and terminate the program
				"Must include names of input and output files.");
	}																					// End If
	
																					// Try to open the input file for reading
	if ((input_fp = fopen(argv[1], "r"))== NULL){										// If there is an error 
		printf ("Problem opening \"%s\"", argv[1]);	exit (1);							// 		Print an error message and terminate the program
	}																					// End If
																					// Try to open the output file for writing
	if ((output_fp = fopen(argv[2], "w"))== NULL){										// If there is an error 
		printf ("Problem opening \"%s\"", argv[2]);	exit (2);							// 		Print an error message and terminate the program
	}																					// End If
	
																					// Read in integers from the input file
	while (!feof(input_fp)){															// Loop
		fscanf (input_fp, "%d", &cur_int);												// 		Scan the input file for an integer 
		insert_into_list(&list_of_ints, cur_int);										// 		Add the integer to proper place in linked list
	}																					// End Loop
	
																					// Print integers with accompanying log to output file
	for (cur = list_of_ints, prev = NULL; cur != NULL; prev = cur, cur = cur->next){ 	// Loop through entire linked list
		fprintf(output_fp, "%d \t %.6f\n", cur->value, log10((double)cur->value));		//		Print integer and log10 to output file
		free (prev);																	// 	Free the previous node from memory
	}																					// End Loop
	
	fclose(input_fp);																// Close both files
	fclose(output_fp);
	
	printf("Program execution successful. Check the output file to see results.");	// Print program execution success message
	
	
} 																				// End



