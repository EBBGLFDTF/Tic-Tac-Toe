#include <iostream>
using namespace std;


/** Should print the tic-tac-toe board in a nice grid
 *  format as shown below:
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O'
 *         (the letter oh), or '?'.
 */
void printTTT(char grid[], int dim);

/** 
 * Should check if any player has won the game yet.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Should return 1 if 'X' has won, 2 if 'O' has won, or 0 (zero)
 *   if the game is still undecided.
 * 
 */
int checkForWinner(char grid[], int dim);

/**
 * Should output a prompt indicating which player's turn it is and
 * ask them to enter a number 0-(dim^2-1) representing the desired square
 *  
 *  0 | 1 | 2
 * -----------
 *  3 | 4 | 5
 * -----------
 *  6 | 7 | 8
 *
 *
 * and receive the user input.  If the square is already occupied
 * repeat the prompt and receive input again until the player 
 * chooses a square that is unoccupied.  If the user types in any
 * other value outside of the range [0-(dim^2-1)], return true
 * which will cause main() to quit, otherwise return false.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *  
 * Return value:
 *   Return false if successful at choosing a square, or true if
 *   any square outside the range [0-(dim^2-1)] is chosen
 */
bool getInputAndUpdateGrid(char grid[], int dim, char player);

/** 
 * Should check if there is no possible way any player can win.
 * More specifically, if there does not exist a row, column,
 * or diagonal that can still have 3 of a kind, then the game
 * will be a draw.
 * 
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Return true if no player can win given the current 
 *   game state, false otherwise.
 */
bool checkForDraw(char grid[], int dim);
 

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

void printTTT(char grid[], int dim)
{
    for(int i=0; i < dim; i++) // loops through i columns
    {
        for(int j=0; j < dim; j++) // loops through j rows
        {
            cout << " " << grid[dim*i+j] << " ";
            if(j != dim-1)
            {
                cout << "|";
            }
            if(j == dim-1) 
            {
                cout << endl;
            }
        }
        if(i != dim-1)
		{
		    for(int k=0; k < dim*3+dim-1; k++)
			{
				cout << "-";
			}
            cout << endl;
		}
    }
    
}

int checkForWinner(char grid[], int dim)
{
	int inputRowx=0, inputColx=0, inputRowo=0, inputColo=0, inputDiagx=0, inputDiago=0;
	for(int i=0; i<dim; i++) //shifts down i rows
	{
		inputRowx=0, inputRowo=0;
		for(int j=0; j<dim; j++) //checks each entry in a row
		{
			if(grid[i*dim+j]=='X')
			{
				inputRowx++;
			}
			if(grid[i*dim+j]=='O')
			{
				inputRowo++;
			}
		}
		if(inputRowx==dim)
		{
			return 1;
		}
		if(inputRowo==dim)
		{
			return 2;
		}
	}
	for(int j=0; j<dim; j++) //shift over j columns
	{
		inputColx=0, inputColo=0;
		for(int i=0; i<dim; i++) //checks each entry in a column
		{
			if(grid[i*dim+j]=='X')
			{
				inputColx++;
			}
			if(grid[i*dim+j]=='O')
			{
				inputColo++;
			}
		}
		if(inputColx==dim)
		{
			return 1;
		}
		if(inputColo==dim)
		{
			return 2;
		}
	}
	for(int i=0; i < dim; i++) // checks if either player won with diagonal down-right
	{
		if(grid[i*dim+i]=='X')
		{
			inputDiagx++;
		}
		if(grid[i*dim+i]=='O')
		{
			inputDiago++;
		}
	}
	if(inputDiagx==dim)
	{
		return 1;
	}
	if(inputDiago==dim)
	{
		return 2;
	}
	inputDiagx=0, inputDiago=0;
	for(int i=0; i < dim; i++) // checks if either player won with diagonal up-right
	{
		if(grid[i*dim+dim-1-i]=='X')
		{
			inputDiagx++;
		}
		if(grid[i*dim+dim-1-i]=='O')
		{
			inputDiago++;
		}
	}
	if(inputDiagx==dim)
	{
		return 1;
	}
	if(inputDiago==dim)
	{
		return 2;
	}
	return 0;
}

bool getInputAndUpdateGrid(char grid[], int dim, char player)
{
	int input;
	bool done=false;
	while(!done)
	{
		cout << player << " Player's Turn" << endl << "Enter a number between 0 and " << dim*dim-1 << ":" << endl;
		cin >> input;
		if(input>dim*dim-1 || input<0)
		{
			return true;
		}
		else if(grid[input]!='X' && grid[input]!='O')
		{
			grid[input] = player;
			return false;
		}
	}
    return false;
}

bool checkForDraw(char grid[], int dim)
{
	bool containsX=false, containsO=false;
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++) //checks if each row has at least one X and O
		{
			if(grid[i*dim+j]=='X')
			{
				containsX=true;
			}
			else if(grid[i*dim+j]=='O')
			{
				containsO=true;
			}								
		}
		if(!containsX || !containsO) //checks if the row is still winnable
		{
			return false;
		}
		else
		{
			containsX=false, containsO=false;
		}
	}

	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++) //checks if each column has at least one X and O
		{
			if(grid[j*dim+i]=='X') 
			{
				containsX=true;
			}
			else if(grid[j*dim+i]=='O')
			{
				containsO=true;
			}								
		}
		if(!containsX || !containsO) //checks if the column is still winnable
		{
			return false;
		}
		else
		{
			containsX=false, containsO=false;
		}
	}
	for(int i=0; i < dim; i++) // checks if diagonal down-right has at least one X and O
	{
		if(grid[i*dim+i]=='X')
		{
			containsX=true;
		}
		else if(grid[i*dim+i]=='O')
		{
			containsO=true;
		}
	}
	if(!containsX || !containsO) //checks if the diagonal down-right is still winnable
	{
		return false;
	}
	else
	{
		containsX=false, containsO=false;
	}
	for(int i=0; i < dim; i++) // checks if diagonal up-right is still winnable
	{
		if(grid[i*dim+dim-1-i]=='X')
		{
			containsX=true;
		}
		if(grid[i*dim+dim-1-i]=='O')
		{
			containsO=true;
		}
	}
	if(!containsX || !containsO) //checks if the diagonal down-right is still winnable
	{
		return false;
	}
	else
	{
		containsX=false, containsO=false;
	}
	return true;
}


/******* Change 3 to whatever odd integer you want ********/
/********              for the grid size           ********/
#ifndef TTTDIM
#define TTTDIM 3
#endif
/**********************************************************/

/**********************************************************
         Main is complete. You should not alter it.
 **********************************************************/
int main()
{
  // dim stands for dimension and is the side length of the 
  // tic-tac-toe board i.e. dim x dim (3x3 or 5x5).
  const int dim = TTTDIM;
  const int dim_sq = dim*dim;

  char tttdata[dim_sq];
  for(int i=0; i < dim_sq; i++){
    tttdata[i] = '?';
  }
  bool done = false;
  char player = 'X';
  // Show the initial starting board
  printTTT(tttdata, dim);

  while(!done){

    // Get the current player's input
    bool quit = getInputAndUpdateGrid(tttdata, dim, player);
    if(quit){
      break;
    }

    // Show the updated board
    printTTT(tttdata, dim);

    // Check for winner 
    int winner = checkForWinner(tttdata, dim);
    if(winner == 1){
      cout << "X player wins!" << endl;
      done = true;
    }
    else if(winner == 2){
      cout << "O player wins!" << endl;
      done = true;
    }

    // Check for draw
    if( checkForDraw(tttdata, dim) ){
      cout << "Draw...game over!" << endl;
      done = true;
    }

    // switch players to get ready for next turn
    if( player == 'X') {
      player = 'O';
    }
    else {
      player = 'X';
    }
  }
  return 0;
}
