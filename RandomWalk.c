#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Declare Function and type definitions to be used
typedef struct position { int x;	int y; } Position;
void initialize_grid(void);
void print_grid(void);
bool is_in_grid(Position);

bool Move_Is_Legal(int);
int Get_Legal_Moves(void);
void Walk(int, bool);


#define ROW_NUM 10
#define COL_NUM 10

// Declare global Variables
char grid[COL_NUM][ROW_NUM];  // Declare "grid" as an int array size COL_NUM by ROW_NOW
char cur_step_char = 'A';  // Declare "cur_step_char" as char and set to 'A'
Position cur_pos = { 0, 0 }, new_pos = { 0, 0 }; // Declare "cur_pos" and "new_pos" as Position and set their values to 0

/*************************************************
* Function Title: main
*
* Summary: Displays each step of the path that the computer has randomly taking starting with 'A' and ending with 'Z'
*
* Inputs: none
* Outputs: none
**************************************************
* Pseudocode
*
* Begin
*	Declare "direction" as int
*	Initialize the grid
*	Initialize the random number generator
*	Loop while at least one legal move is left and the step character is before or equal to 'Z'
*		Set direction to a random number between 0 and 3
*		If moving in that direction is legal
*			Walk in that direction
*		End If
*	End loop
*	Print the grid
*	Keep the window open
* End
**************************************************/

int main()
{  // Begin
	int direction;										    // Declare "direction" as int

	initialize_grid();										// Initialize the grid
	srand((unsigned)time(NULL));							// Initialize the random number generator
	
	while (Get_Legal_Moves() > 0 && cur_step_char <= 'Z')    // Loop while at least one legal move is left and the step character is before or equal to 'Z'
	{
		direction = rand() % 4;									 // Set direction to a random number between 0 and 3

		if (Move_Is_Legal(direction)) {							 // If moving in that direction is legal
			Walk(direction, true);										// Walk in that direction
		}														 // End If

	}														 // End loop

	print_grid();											 // Print the grid

	printf("\nPress [ENTER} to continue..."); 	             // Keep the window open
	getchar();

	return 0;
}  // End


/************************************************************
* Function Title: initialize_grid
*
* Summary: Assigns each element of the grid to '.' and places the current step character at starting position
*
* Inputs: none
* Outputs: none
*************************************************************
* Psuedocode
*
* Begin
*	Loop ROW_NUM times (using "row" as an incrementer)
*		Loop COL_NUM times (using "col" as an incrementer)
*			Set the current element grid[row][col] to '.'
*		End Loop
*	End Loop
*	Set cur_step_char to starting position, then increment to next the character
* End
************************************************************/
void initialize_grid(void)
{ // Begin
	for (int row = 0; row < ROW_NUM; row++) {				// Loop ROW_NUM times (using "row" as an incrementer)
		for (int col = 0; col < COL_NUM; col++) {				// Loop COL_NUM times (using "col" as an incrementer)
			grid[col][row] = '.';									// Set the current element grid[row][col] to '.'
		}														// End Loop
	}														// End Loop
	grid[cur_pos.x][cur_pos.y] = cur_step_char++;			// Set cur_step_char to starting position, then increment to next the char
} // End


/************************************************************
* Function Title: print_grid
*
* Summary: Prints a grid of size COL_NUM by ROW_NUM
*
* Inputs: none
* Outputs: none
*************************************************************
* Psuedocode
*
* Begin
*	Loop ROW_NUM times (using "row" as an incrementer)
*		Loop COL_NUM times (using "col" as an incrementer)
*			Print the current element grid[row][col]
*		End Loop
*		Print a new line after each row
*	End Loop
* End
*************************************************************/
void print_grid(void)
{ // Begin
	for (int row = 0; row < ROW_NUM; row++) {				// Loop ROW_NUM times (using "row" as an incrementer)
		for (int col = 0; col < COL_NUM; col++) {				// Loop COL_NUM times (using "col" as an incrementer)
			printf("%c ", grid[col][row]);						  // Print the current element grid[row][col]
		}														// End Loop
		printf("\n");											// Print a new line after each row
	}														// End Loop
} // End


/************************************************************
* Function Title: is_in_grid
*
* Summary: Determines whether or not the specifed position is is inside the grid
*
* Inputs: pos (The Position to be checked)
* Outputs: boolean (true if inside; false if not)
************************************************************
* Psuedocode
*
* Begin
*	If pos.x is between 0 and the last index in the column and pos.y is between 0 and the last index in the row
*		Return the value of true
*	Else
*		Return the value of false
*	End If
* End
*************************************************************/
bool is_in_grid(Position pos)
{ // Begin
	if (0 <= pos.x && pos.x < COL_NUM && 0 <= pos.y && pos.y < ROW_NUM) { // If pos.x is between 0 and the last index in the column and pos.y is between 0 and the last index in the row
		return true;															// Return the value of true
	}																	
	else {																  // Else
		return false;															// Return the value of false
	}																	  // End If
} // End


/************************************************************
* Function Title: Move_Is_Legal
*
* Summary: Determines whether or not moving in the specified direction is legal
*
* Inputs: direction (int representing the direction of the move being checked)
* Outputs: boolean (true if the move is legal; false if it is not)
************************************************************
* Psuedocode
*
* Begin
*	"Hypothetically walk" in the specified direction to determine the new position
*	If the grid contains the hypothecial new position and it does not already contain a step character
*		Reset new_pos back to the current position
*		Return the value of true
*	Else
*		Reset new_pos back to the current position
*		Return the value of false
*	End If
* End
*************************************************************/
bool Move_Is_Legal(int direction)
{ // Begin
	Walk(direction, false);												// "Hypothetically walk" in the specified direction to determine the new position

	if (is_in_grid(new_pos) && grid[new_pos.x][new_pos.y] == '.') {		// If the grid contains the hypothecial new position and it does not already contain a step character
		new_pos = cur_pos;													// Reset new_pos back to the current position
		return true;														// Return the value of true
	}																	
	else {																// Else
		new_pos = cur_pos;													// Reset new_pos back to the current position
		return false;														// Return the value of false
	}																	// End If
} // End


/************************************************************
* Function Title: Get_Legal_Moves
*
* Summary: Calculates and returns the number of legal moves available at the current position
*
* Inputs: none
* Outputs: legal_moves (int containing the number of legal moves that are available at the current position
************************************************************
* Psuedocode
*
* Begin
*	Declare "legal_moves" as int and set to 0
*	Loop 4 times (using int "direction" as an incrementer)
*		If moving in "direction" is legal
*			Add one to the number of legal_moves
*		End If
*	End Loop
*	Return the value of legal_moves
* End
*************************************************************/
int Get_Legal_Moves(void)
{ // Begin
	int legal_moves = 0;									// Declare "legal_moves" as int and set to 0
	for (int direction = 0; direction < 4; direction++)		// Loop 4 times (using int "direction" as an incrementer)
	{
		if (Move_Is_Legal(direction)) {							// If moving in "direction" is legal					
			legal_moves++;											// Add one to the number of legal_moves
		}														// End If
	}														// End Loop
	return legal_moves;										// Return the value of legal_moves
} // End


/************************************************************
* Function Title: Walk
* 
* Summary: Walks in the specified direction if the "update_grid" parameter is set to true, or performs a "hypothetical walk" 
*	if it is set to false
*
* Inputs: direction (int representing the direction of the move being checked), 
		  update_grid (bool to control whether or not to actually perform the walk)
* Outputs: none
**************************************************************
* Psuedocode
*
* Begin
*	Set the new position equal to the current position
*	Change new_pos based on the direction
*	If direction equals 0
*		"Walk up" by subtracting 1 from new_pos.y
*	End If
*	If direction equals 1
*		"Walk right" by adding 1 to new_pos.x
*	End If
*	If direction equals 2
*		"Walk down" by adding 1 to new_pos.y
*	End If
*	If direction equals 3
*		"Walk left" by subtracting 1 from new_pos.x
*	End If
*	If update_grid is equal to true
*		Set the current position to the updated new position
*		Set the grid element located at cur_pos to the current step character (e.g. 'B')
*		Increment cur_step_char to the next letter in line (e.g. 'B' goes to 'C')
*	End If
* End
*************************************************************/
void Walk (int direction, bool update_grid)
{ // Begin
	new_pos = cur_pos;					 // Set the new position equal to the current position
	switch (direction)					 // Change new_pos based on the direction
	{
		case 0:							 // If direction equals 0
			new_pos.y--;					// "Walk up" by subtracting 1 from new_pos.y
			break;						 // End If	

		case 1:						     // If direction equals 1
			new_pos.x++;					// "Walk right" by adding 1 to new_pos.x
			break;						 // End If

		case 2:							 // If direction equals 2
			new_pos.y++;					 // "Walk down" by adding 1 to new_pos.y
			break;					     // End If	

		case 3:						  	 // If direction equals 3
			new_pos.x--;				  	 // "Walk left" by subtracting 1 from new_pos.x
			break;						 // End If
	}

	if (update_grid)				  	 // If update_grid is equal to true
	{
		cur_pos = new_pos;							 // Set the current position to the updated new position
		grid[cur_pos.x][cur_pos.y] = cur_step_char;	 // Set the grid element located at cur_pos to the current step character (e.g. 'B')
		cur_step_char++;							 // Increment cur_step_char to the next letter in line (e.g. 'B' goes to 'C')
	}									 // End If
} // End