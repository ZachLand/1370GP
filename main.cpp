#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Prototypes
double getValue();
void test2(double);

int main ()
{
    // This is the main code /
    return 0;
}

double getValue()
{
    static double a;
    do
    {
        cin >> a;
        if(a<0)
            cout << "Error: Invalid value" << endl;
    } while(a<0);
    return a;
}

void test2(double a)
{
    cout << a << endl;
}
