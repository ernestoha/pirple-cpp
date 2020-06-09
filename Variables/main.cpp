#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    const int MINUTES_PER_HOUR = 60;
    int numHours = 1;

    //MINUTES_PER_HOUR++;

    cout << "There are " << MINUTES_PER_HOUR * numHours << " minutes in " << numHours << " hour" << ((numHours==1) ? "" : "s" ) << endl;

    numHours++;

    return 1;
}
