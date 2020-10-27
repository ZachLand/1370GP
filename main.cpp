#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Prototypes
double getValue();
int getTime(int&, int&, string&);
void printResults(int, int, int, string, int, int, string, double, double, int, 
        double, double, double, double);

int main () /* These will more than likely be broken up into other Functions
                I've placed them in int main just so we could start building*/
{
    // The total number of days spent on the trip.
    int days;
    cout << "days: ";
    days = getValue();

    /* The time of departure on the first day of the trip and 
        the time of arrival back home on the last day of the trip */
    int timeOfDepartureHr, timeOfDepartureMin, timeOfArrivalHr, timeOfArrivalMin;
    string am_pm_depart, am_pm_arrive;

    cout << "Please enter your departure time (HH:MM AM/PM): ";
    getTime(timeOfDepartureHr, timeOfDepartureMin, am_pm_depart);
    cout << "Please enter your arrival time (HH:MM AM/PM): ";
    getTime(timeOfArrivalHr, timeOfArrivalMin, am_pm_arrive);

    // The amount of any round -trip airfare
    double airfare;
    cout << "airfare: $";
    airfare = getValue();

    // The amount of any car rentals
    double carRental;
    cout << "carRental: $";
    carRental = getValue();

    /* Miles driven, if a private vehicle was used. Vehicle allowance 
        is $0.58 per mile. Question will be: Do we want the miles to
        be an integer or floating point? AND if floating point,
        should be have this number round up so that they are charged
        for the mile as a whole? I know companies do this a lot.*/
    int milesDriven;
    const double ALLOWANCE_VEHICLE = 0.58;
    cout << "milesDriven: ";
    milesDriven = getValue();


    /* Parking fees. (The company allows up to $12 per day. Anything
        in excess of this must be paid by the employee.)*/
    double feeParking;
    const double ALLOWANCE_PARKING = 12.00;
    cout << "feeParking: $";
    feeParking = getValue();

    /* Taxi fees. (The company allows up to $40 per day for each day
        a taxi was used. Anything in excess of this must be paid by the employee.)*/
    double feeTaxi;
    const double ALLOWANCE_TAXI = 40.00;
    cout << "feeTaxi: $";
    feeTaxi = getValue();

    // Conference or seminar registration fees
    double feeConf;
    cout << "feeConf: $";
    feeConf = getValue();

    /* Hotel expenses. (The company allows up to $90 per night for
        lodging. Anything in excess of this amount must be paid by the employee.)*/
    double hotel;
    const double ALLOWANCE_HOTEL = 90.00;
    cout << "hotel: $";
    hotel = getValue();

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
    

    printResults(days, timeOfDepartureHr, timeOfDepartureMin, am_pm_depart, 
        timeOfArrivalHr, timeOfArrivalMin, am_pm_depart, airfare, 
        carRental, milesDriven, feeParking, feeTaxi, feeConf, hotel);

    return 0;
}

double getValue()
{
    /* I think we will need to change this since we will be dealing
        int and doubles throughout the program.*/
    static double a;
    cin >> a;
    while(a<0 || cin.fail())
    {
        cout << "Error: Invalid value" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> a;
    }
    return a;
}

int getTime(int& a, int& b, string& d)
{
    static char c; /* We can use time as integers having them separated
                    with ':' */
    cin >> a >> c >> b >> d;
    while(!((a>0 && a<=12) && (b>0 && b<=59) && 
        (d=="AM"||d=="am"||d=="PM"||d=="pm")))
    {
        cout << "Please enter a valid time" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> a >> c >> b >> d;
    } ;
    return 0;
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
void printResults(int days, int DeHr, int DeMin, string DAmPm, int ArHr, int ArMin, 
        string ArAmPm, double q, double w, int z, double fp, double ft, 
        double fc, double h)
{
    /* This is how we will output for time. And for the time being, will
        be a test for our outputs while troubleshooting.*/ 
    cout << endl;
    cout << "days: " << days << endl;
    cout << setw(2) << setfill('0') << DeHr 
            << ':' << setw(2) << setfill('0') << DeMin
            << ' ' << DAmPm << endl;
    cout << setw(2) << setfill('0') << ArHr << ':' 
            << setw(2) << setfill('0') << ArMin << ' '
            << ArAmPm << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "airfair = $" << q << endl;
    cout << "carRental = $" << w << endl;
    cout << "milesDriven = " << z << endl;
    cout << "feeParking = $" << fp << endl;
    cout << "feeTaxi = $" << ft << endl;
    cout << "feeConf = $" << fc << endl;
    cout << "hotel: $" << h << endl;
}