#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a, b, c;
    float x1, x2;

    cout << "Enter a value for a: ";
    cin >> a;
    cout << "Enter a value for b: ";
    cin >> b;
    cout << "Enter a value for c: ";
    cin >> c;

    x1 = (-b + sqrt(pow(b, 2) - 4*a*c)) / (2*a);
    x2 = (-b - sqrt(pow(b, 2) - 4*a*c)) / (2*a);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    return 0;
}
