#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int SPACE_W = 60;
    float price1;// = 1.222F;
    float price2;// = 34.233;
    float price3;// = 45.1;
    float total;

    cout << "Please enter a price ";
    cin >> price1;
    cout << "Please enter a price ";
    cin >> price2;
    cout << "Please enter a price ";
    cin >> price3;

    total = price1 + price2 + price3;
    cout << string(80, '-') << endl;
    //printf("%.2f\n", price2);
    cout << setiosflags(ios::fixed);
    cout << setw(SPACE_W) << "Price 1 is " << setprecision(2) << price1 << endl;
    cout << setw(SPACE_W) << "Price 2 is " << setprecision(2) << price2  << endl;
    cout << setw(SPACE_W) << "Price 3 is " << setprecision(2) << price3 << endl;
    cout << setw(SPACE_W) << "Total is " << setprecision(2) << total << endl;

    return 0;
}
