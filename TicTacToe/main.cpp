#include <iostream>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
//char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char board[9] = {'1','2','3','4','5','6','7','8','9'};
char lastPlayer = PLAYER_O;
char currentPlayer = PLAYER_X;

void displayBoard()
{
    cout << endl << "current board state: " << endl;
    for (int y=0; y < 9; y++) // y < 3
    {
        if (y>=0 && y<=2){
            cout << ((y>0)? "|" : "    ") << board[y] << ((y>1) ? "\n" : "");
        }
        if (y>=3 && y<=5){
            cout << ((y>3)? "|" : "    ") << board[y] << ((y>4) ? "\n" : "");
        }
        if (y>=6 && y<=8){
            cout << ((y>6)? "|" : "    ") << board[y] << ((y>7) ? "\n" : "");
        }
    }
}

bool checkForEndGame(int turnNumber, char player)
{
    bool retVal = false;
    if (board[0]==board[1] && board[0]==board[2]){ //012
        cout << "Winner " << player << "!! ** top row **";
        retVal = true;
    }
    if (board[3]==board[4] && board[3]==board[5]){ //345
        cout << "Winner " << player << "!! ** middle row **";
        retVal = true;
    }
    if (board[6]==board[7] && board[6]==board[8]){ //678
        cout << "Winner " << player << "!! ** bottom row **";
        retVal = true;
    }
    if (board[0]==board[3] && board[0]==board[6]){ //036
        cout << "Winner " << player << "!! ** first col **";
        retVal = true;
    }
    if (board[1]==board[4] && board[1]==board[7]){ //147
        cout << "Winner " << player << "!! ** second col **";
        retVal = true;
    }
    if (board[2]==board[5] && board[2]==board[8]){ //258
        cout << "Winner " << player << "!! ** third col **";
        retVal = true;
    }
    if (board[0]==board[4] && board[0]==board[8]){ //048
        cout << "Winner " << player << "!! ** upward diagonal **";
        retVal = true;
    }
    if (board[2]==board[4] && board[2]==board[6]){ //246
        cout << "Winner " << player << "!! ** backward diagonal **";
        retVal = true;
    }
    if ((turnNumber==9) && (!retVal))
    {
        cout << "** Draw. Nobody Wins. **";
        retVal = true;
    }
    return retVal;
}

void getPlayerChoice(char player)
{
        while(true){
            int chosenSquare;
            cout << "Player " << player <<", enter a number between 1 and 9: ";
            cin >> chosenSquare;
            chosenSquare--;
            if (!(chosenSquare>=0 && chosenSquare<=8)){
                cout << "Not a valid choice. Try Again." << endl;
            } else {
                if (board[chosenSquare] == PLAYER_X || board[chosenSquare] == PLAYER_O){
                    cout << "That square is not available. Try again." << endl;
                } else {
                    board[chosenSquare] = player;
                    std::swap(currentPlayer,lastPlayer);
                    break;
                }
            }
        }
}   

int main()
{
    for (int x=0; x<=9; x++)
    {
        displayBoard();
        bool isGameOver = checkForEndGame(x, lastPlayer);
        if (isGameOver)
            break;
        getPlayerChoice(currentPlayer);
    }
    cout << "\n\n" << "press any key to continue" << endl;
    return 0;
}
