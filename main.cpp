#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Prototypes
double getValue();
void printResults(double);

int main () /* These will more than likely be broken up into other Functions
                I've placed them in int main just so we could start building*/
{
    // The total number of days spent on the trip
    int days;

    /* The time of departure on the first day of the trip and 
        the time of arrival back home on the last day of the trip */
    int timeOfDepartureHr, timeOfDepartureMin, timeOfArrivalHr, timeOfArrivalMin;
    char c; /* We can use time as integers having them separated
                    with ':' */
    cout << "Please enter your destination travel start time (HH:MM): ";
    cin >> timeOfDepartureHr >> c >> timeOfDepartureMin;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // The amount of any round -trip airfare
    double airfare;

    // The amount of any car rentals
    double carRental;

    /* Miles driven, if a private vehicle was used. Vehicle allowance 
        is $0.58 per mile.*/
    int milesDriven;
    const double ALLOWANCE_VEHICLE = 0.58;

    /* Parking fees. (The company allows up to $12 per day. Anything
        in excess of this must be paid by the employee.)*/
    double feeParking;
    const double ALLOWANCE_PARKING = 12.00;

    /* Taxi fees. (The company allows up to $40 per day for each day
        a taxi was used. Anything in excess of this must be paid by the employee.)*/
    double feeTaxi;
    const double ALLOWANCE_TAXI = 40.00;

    // Conference or seminar registration fees
    double feeConf;

    /* Hotel expenses. (The company allows up to $90 per night for
        lodging. Anything in excess of this amount must be paid by the employee.)*/
    double hotel;
    const double ALLOWANCE_HOTEL = 90.00;

    /* The cost of each meal eaten. On the first day of the trip,
        breakfast is allowed as an expense if the time of departure
        is before 7 a.m. Lunch is allowed if the time of departure is
        before noon. Dinner is allowed if the time of departure is before
        6 p.m. On the last day of the trip, breakfast is allowed if the
        time of arrival is after 8 a.m. Lunch is allowed if the time of
        arrival is after 1 p.m. Dinner is allowed if the time of arrival
        is after 7 p.m. The program should only ask for the costs of
        allowable meals. (The company allows up to $18 for breakfast,
        $12 for lunch, and $20 for dinner. Anything in excess of this
        must be paid by the employee.)*/
    bool before7AM, before12PM, before6PM, before8AM, before1pm, before7pm;
    double breakfast, lunch, dinner;
    const double BREAKFAST = 18.00, LUNCH = 12.00, DINNER = 20.00;

    
    return 0;
}

double getValue()
{
    /* I think we will need to change this since we will be dealing
        int and doubles throughout the program.*/
    static double a;
    do
    {
        cin >> a;
        if(a<0)
            cout << "Error: Invalid value" << endl;
    } while(a<0);
    return a;
}


/* The program should perform the necessary calculations to determine
    the total amount spent by the business traveler in each category
    (mileage charges, parking, hotel, meals, etc.) as well as the maximum
    amount allowed in each category. It should then create a nicely
    formatted expense report that includes the amount spent and the
    amount allowed in each category, as well as the total amount spent,
    and total amount allowed for the entire trip. This report should be
    written to a file.
*/
void printResults(double a)
{
    cout << a << endl; // Placeholder
}
