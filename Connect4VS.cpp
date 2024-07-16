
#include <iostream> 
#include <iomanip>

using namespace std;
bool isFull(); 
bool dropdisk();
void gamelook();
bool checkWin();
bool drawchecker();


char connectfour[6][7]; // Global array 

bool isFull(int col) {  
    for (int i = 0; i < 6; i++) 
	{
        if (connectfour[i][col] == '-')
		 {
            return false;
        }
    }
    return true;
}

bool dropdisk(int col, char player) 
{
    for (int i = 5; i >= 0; i--)
	 {
        if (connectfour[i][col] == '-') 
		{
            connectfour[i][col] = player;
            return true;
        }
    }
    return false;
}

void gamelook()  
{
  for (int i = 0; i < 6; i++) 
  {
    
    cout << "|";

    for (int j = 0; j < 7; j++) 
	{
      cout << connectfour[i][j];  
      if (j <= 6) 
	  {  
        cout << "|";
      }
    }
    cout << endl;  
  }
}

//WINNING CHECK
bool checkWin(char player) {
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j <8; ++j) {
      if (connectfour[i][j] == player && connectfour[i][j + 1] == player &&
          connectfour[i][j + 2] == player && connectfour[i][j + 3] == player) {
	 return true;
      }
      if (connectfour[i][j] == player && connectfour[i + 1][j] == player &&
          connectfour[i + 2][j] == player && connectfour[i + 3][j] == player) {
        return true;
    }
    // Downward diagonal from left to right like this  
//      R 
//      	R
//      		R
//      			R
    if (connectfour[i][j] == player && connectfour[i + 1][j + 1] == player &&
          connectfour[i + 2][j + 2] == player && connectfour[i + 3][j + 3] == player) {
        return true;
      }
      // Downward diagonal from right to left like this
//                    R
//                R
//            R
//        R
      if (i + 3 <= 5 && j >= 3 && connectfour[i][j] == player &&
          connectfour[i + 1][j - 1] == player && connectfour[i + 2][j - 2] == player &&
          connectfour[i + 3][j - 3] == player) {
        return true;
	}
  }
}

  return false;
}
   		// START OF MAIN FUNCTION 
int main() {
    cout << setw(10) << " WELCOME TO CONNECT4 GAME! " << endl;
    char player1 = 'R', player2 = 'Y';
    char currentPlayer = player1;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            connectfour[i][j] = '-';
        }
    }

    while (true) 
	{  
        int columnChoice;
        cout << "Drop a " << currentPlayer << " disk at column (0-6): "; 
        cin >> columnChoice;

       
        if (columnChoice < 0 || columnChoice > 6 || isFull(columnChoice) || !dropdisk(columnChoice, currentPlayer)) {
            if (columnChoice < 0 || columnChoice > 6) {
                cout << "INVALID COLUMN! PLEASE SELECT A COLUMN IN RANGE (0-6)" << endl;
            } else if (isFull(columnChoice)) {
                cout << "Column " << columnChoice << " is full. Please choose another column." << endl;
            } else {
                cout << "Column " << columnChoice << " is full. Please choose another column." << endl;
            }
            continue;
        }

        // Display the game
        gamelook();
        
  if (checkWin(currentPlayer)) {
    cout << "Player "<<currentPlayer << " won the game!" << endl;
    break; 
  }
        if (currentPlayer == player1)
            currentPlayer = player2;
        else
            currentPlayer = player1;
    }
    
  
 

    return 0;
}
