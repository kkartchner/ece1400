#include <stdio.h>

/**************************************************************************************************************************************
main: Asks the user to enter an international dialing code and then looks it up in the country_codes array. 
If it finds the code, the name of the corresponding country  is displayed; if it does not find the code, an error message is displayed.
***************************************************************************************************************************************
* Psuedocode
*
* Begin
*	Declare "dialing_codes" as struct with element char* "country" and int "code"
*	Declare "country_codes" as struct dialing_codes and iniatilize dialing code and country values
*	Print program instructions
*	Declare "code" as unsigned short int
*	Scan for int (max of 3 digits) and store to code
*	Loop through country codes array (using int i as incrementer)
*		If code is equal to country_codes[i].code
*			Print country name
*			Set code to equal 0
*			break;
*		End If
*	End Loop
*	If code is not equal to 0
*		Print error message
*	End If
*	Keep results open
* End
***************************************************************************************************************************************/
int main (void)
{	// Begin
	struct  dialing_code {																						//	Declare "dialing_codes" as struct with element char* "country" and int "code"
		char *country;
		unsigned short int code;
	};

	const struct dialing_code country_codes[] = { {"Argentina", 54}, {"Bangladesh",	880}, {"Brazil",	55},	//	Declare "country_codes" as struct dialing_codes and iniatilize dialing code and country value
												  {"Burma (Myanmar)", 95}, {"China", 86}, {"Columbia",	57},
												  {"Congo, Dem. Rep. of", 243}, {"Egypt", 20}, {"Ethiopia", 251},
												  {"France", 33}, {"Germany", 49}, {"India", 91},
												  {"Indonesia", 62}, {"Iran", 98}, {"Italy", 39},
												  {"Mexico", 52}, {"Pakistan", 92}, {"Poland", 48},
												  {"South Africa", 27}, {"Spain", 34}, {"Thailand", 66},
												  {"Ukraine", 380}, {"United States", 1}, {"Japan", 81},
												  {"Nigeria", 234}, {"Philipinnes", 63}, {"Russia", 7},
												  {"South Korea", 82}, {"Sudan", 249}, {"Turkey", 90},
												  {"United Kingdom", 44}, {"Vietnam", 84} };

	unsigned short int code;																					//	Declare "code" as unsigned short int
	
	printf("Welcome to Dial-Finder! \nEnter a code to display the country it is in: ");							//	Print program instructions
	scanf_s ("%3u", &code);																						//	Scan for int (max of 3 digits) and store to code
	
	for (int i = 0; i < (int) (sizeof (country_codes)) / (sizeof (struct dialing_code)); i++) {					//	Loop through country codes array (using int i as incrementer)
		if (code == country_codes[i].code) {																	//		If code is equal to country_codes[i].code
			printf(country_codes->country);																		//			Print country name
			code = 0;																							//			Set code to equal 0
			break;																								//			Exit out of loop
		}																										//		End If
	}																											//	End Loop
	
	if (code != 0) {																							//	If code is not equal to 0
		printf("Invalid code.");																				//		Print error message
	}																											//	End If
	
	printf("\n\nPress any key then ENTER to continue..."); getchar(); getchar();								//	Keep results open

	return 0;
}	// End

	
