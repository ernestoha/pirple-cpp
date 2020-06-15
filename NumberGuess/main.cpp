#include <iostream>

using namespace std;

int formulaGuess(int highest, int lowest, int attempts)
{
    return lowest + ((highest - lowest) * 0.5);
}

int main()
{
    cout << "Think of a number between 1 and 100." << endl;
    int highest = 100, lowest = 0, attempts = 0;
    char opc;
    do {
        attempts++;
        int guess = formulaGuess(highest, lowest, attempts);
        cout << "I guess " << guess << ". Am I right?" << endl;
        cout << "’q’ to quit, ‘y’ if correct, ‘h’ if too high, ‘l’ if too low. ";
        cin >> opc;
        if(opc == 'y')
        {
            cout << endl << "I guessed it in "<< attempts <<" attempts." << endl;
            break;
        }
        else if (opc == 'h')
        {
            cout << "too high" << endl;
            highest = guess;
            continue;
        }
        else if (opc == 'l')
        {
            cout << "too low" << endl;
            lowest = guess;
            continue;
        }
        else if (opc == 'q')
        {
            cout << endl << "You quit. Bye." << endl;
            break;
        }
        else
        {
            cout << "I didn’t understand that response." << endl;
            attempts--;
            continue;
        }
    } while(true);

    return attempts;
}
