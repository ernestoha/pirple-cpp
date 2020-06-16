#include <iostream>

using namespace std;

int main()
{
    const char PLAYER_X = 'X';
    const char PLAYER_O = 'O';
    char lastPlayer = PLAYER_O;
    char currentPlayer = PLAYER_X;
    //char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char board[9] = {'1','2','3','4','5','6','7','8','9'};

    //cout << setiosflags(ios::fixed);
    for (int x=0; x<=9; x++)
    {
        cout << endl << "current board state: " << endl;
        for (int y = 0; y < 9; y++) // y < 3
            {
                /*cout << "    ";
                for (int x = 0; x < 3; x++)
                {
                    cout << ((x>0)? "|" : "") << board[y][x];
                }
                cout << endl << "    " << "-+-+-" << endl;
                */
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
        //--------
            if (board[0]==board[1] && board[0]==board[2]){ //012
                cout << "Winner " << lastPlayer << "!! ** top row **";
                break;
            }
            if (board[3]==board[4] && board[3]==board[5]){ //345
                cout << "Winner " << lastPlayer << "!! ** middle row **";
                break;
            }
            if (board[6]==board[7] && board[6]==board[8]){ //678
                cout << "Winner " << lastPlayer << "!! ** bottom row **";
                break;
            }
            if (board[0]==board[3] && board[0]==board[6]){ //036
                cout << "Winner " << lastPlayer << "!! ** first col **";
                break;
            }
            if (board[1]==board[4] && board[1]==board[7]){ //147
                cout << "Winner " << lastPlayer << "!! ** second col **";
                break;
            }
            if (board[2]==board[5] && board[2]==board[8]){ //258
                cout << "Winner " << lastPlayer << "!! ** third col **";
                break;
            }
            if (board[0]==board[4] && board[0]==board[8]){ //048
                cout << "Winner " << lastPlayer << "!! ** upward diagonal **";
                break;
            }
            if (board[2]==board[4] && board[2]==board[6]){ //246
                cout << "Winner " << lastPlayer << "!! ** backward diagonal **";
                break;
            }
        //--------
            if (x==9){
                cout << "** Draw. Nobody Wins. **";
                break;
            }

            while(true){
                int chosenSquare;
                cout << "Player " << currentPlayer <<", enter a number between 1 and 9: ";
                cin >> chosenSquare;
                chosenSquare--;
                if (!(chosenSquare>=0 && chosenSquare<=8)){
                    cout << "Not a valid choice. Try Again." << endl;
                } else {
                    if (board[chosenSquare] == PLAYER_X || board[chosenSquare] == PLAYER_O){
                        cout << "That square is not available. Try again." << endl;
                    } else {
                        board[chosenSquare] = currentPlayer;
                        std::swap(currentPlayer,lastPlayer);
                        break;
                    }
                }
            }

    }
    cout << "\n\n" << "press any key to continue";
    return 0;
}
