#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Prototypes
double getValue();
int getTime(int&, int&, string&);
void milesDrivenCalc(const double&, int&, double&);
void getFees(const double&, double&, double&, int);
void meals(int&, int&, string&);
void printResults(int, int, int, string, int, int, string, double, double, int, 
        double, double, double, double, double, double);

int main () 
/* These will more than likely be broken up into other Functions
 I've placed them in int main just so we could start building*/
{
    // The total number of days spent on the trip.
    // DONE
    int days;
    cout << "days: ";
    days = getValue();

    /* The time of departure on the first day of the trip and 
        the time of arrival back home on the last day of the trip */
    // DONE
    int timeOfDepartureHr, timeOfDepartureMin, timeOfArrivalHr, timeOfArrivalMin;
    string am_pm_depart, am_pm_arrive;

    cout << "Please enter your departure time (HH:MM AM/PM): ";
    getTime(timeOfDepartureHr, timeOfDepartureMin, am_pm_depart);
    cout << "Please enter your arrival time (HH:MM AM/PM): ";
    getTime(timeOfArrivalHr, timeOfArrivalMin, am_pm_arrive);

    // The amount of any round -trip airfare
    // DONE
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
    // DONE
    double allowanceVeh;
    int milesDriven;
    const double ALLOWANCE_VEHICLE = 0.58;
    milesDrivenCalc(ALLOWANCE_VEHICLE, milesDriven, allowanceVeh);

    /* Parking fees. (The company allows up to $12 per day. Anything
        in excess of this must be paid by the employee.)*/
    // DONE
    double feeParking, feeParkingExcess;
    const double ALLOWANCE_PARKING = 12.00;
    cout << "Parking Fees: $";
    getFees(ALLOWANCE_PARKING, feeParking, feeParkingExcess, days);

    /* Taxi fees. (The company allows up to $40 per day for each day
        a taxi was used. Anything in excess of this must be paid by the employee.)*/
    double feeTaxi, feeTaxiExcess;
    const double ALLOWANCE_TAXI = 40.00;
    cout << "Taxi Fees: $";
    getFees(ALLOWANCE_TAXI, feeTaxi, feeTaxiExcess, days);

    // Conference or seminar registration fees
    double feeConf;
    cout << "feeConf: $";
    feeConf = getValue();

    /* Hotel expenses. (The company allows up to $90 per night for
        lodging. Anything in excess of this amount must be paid by the employee.)*/
    double feeHotel, feeHotelExcess;
    const double ALLOWANCE_HOTEL = 90.00;
    cout << "hotel: $";
    getFees(ALLOWANCE_HOTEL, feeHotel, feeHotelExcess, days);

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
        timeOfArrivalHr, timeOfArrivalMin, am_pm_arrive, airfare, 
        carRental, milesDriven, allowanceVeh, feeParking, feeTaxi, feeConf, feeHotel, 
        feeParkingExcess);

    return 0;
}
/******************************************************************************************/
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
    }
    if(d=="am")
        d = "AM";
    if(d=="pm")
        d = "PM";
    return 0;
}
/******************************************************************************************/

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
        string ArAmPm, double air, double rent, int z, double av, double fp, double ft, 
        double fc, double h, double fpe)
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
    cout << "airfair = $" << air << endl;
    cout << "carRental = $" << rent << endl;
    cout << "milesDriven = " << z << endl;
    cout << "allowanceVeh = $" << av << endl;
    cout << "feeParking = $" << fp << endl;
    cout << "Parking allowance = $" << 20 * 12 << endl;
    cout << "Was Parking Allowance Exceeded? ";
    if(fpe<=0)
        cout << "No" << endl;
    else
        cout << "Yes\nfeeParkingExcess = $" << fpe << endl;    
    cout << "feeTaxi = $" << ft << endl;
    cout << "feeConf = $" << fc << endl;
    cout << "hotel: $" << h << endl;
}
/******************************************************************************************/
void milesDrivenCalc(const double& ALLOWANCE_VEHICLE, int& milesDriven, double& allowanceVeh)
{
    int choice;
    
    cout << "Was a private vehicle used? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;
        // Input Validity 
        while(choice != 1 && choice != 2)
        {
            cout << "ERROR: Please enter valid option: ";
            cin >> choice;
        }
    cout << "Enter miles driven: ";
    milesDriven = getValue();

    if(choice == 1)
    allowanceVeh = milesDriven * ALLOWANCE_VEHICLE;
}
/******************************************************************************************/
void getFees(const double& ALLOWANCE, double& fee, double& feeExcess, int days)
{
/* Parking fees. (The company allows up to $12 per day. Anything
        in excess of this must be paid by the employee.)*/
    fee = getValue();
    // Calculates the amount the user then has to pay.
    feeExcess = fee - (days * ALLOWANCE);
}
/******************************************************************************************/
void meals(int& timeOfDepartureHr, int& timeOfArrivalHr, string& d)
{
    const int B_ALLOW = 18;
    const int L_ALLOW = 12;
    const int D_ALLOW = 20;

    double bfast1, lnch1, dnr1, bfast2, lnch2, dnr2, bfast, lnch, dnr,
    oweb1, owel1, owed1, oweb2, owel2, owed2;
/******** FIRST DAY ****************************************************************************/
    if (d == "am" || d == "AM")
    {
        if (timeOfDepartureHr < 7)
        {
        cout << "How much did breakfast cost in the first day? $";
        cin >> bfast1;
        cout << "How much did lunch cost in the first day? $";
        cin >> lnch1;
        cout << "How much did dinner cost in the first day? $";
        cin >> dnr1;
        }
        else if (timeOfDepartureHr < 12)
        {
        cout << "How much did lunch cost in the first day? $";
        cin >> lnch1;
        cout << "How much did dinner cost in the first day? $";
        cin >> dnr1;
        }
    }
    if (d == "pm" || d == "PM")
    {
        if (timeOfDepartureHr < 6)
        {
            cout << "How much did dinner cost in the first day? $";
            cin >> dnr1;
        }
        else
        cout << "Time of departure was too late for any meals on the first day!";
    }
/******* LAST DAY *****************************************************************************/
    if (d == "am" || d == "AM")
    {
        if (timeOfArrivalHr > 8)
        {
        cout << "How much did breakfast cost in the first day? $";
        cin >> bfast2;
        cout << "How much did lunch cost in the first day? $";
        cin >> lnch2;
        cout << "How much did dinner cost in the first day? $";
        cin >> dnr2;
        }
    }
    if (d == "pm" || d == "PM")
    {
        if (timeOfArrivalHr > 1)
        {
            cout << "How much did lunch cost in the last day? $";
            cin >> lnch2;
            cout << "How much did dinner cost in the first day? $";
            cin >> dnr2;
        }
        else if (timeOfArrivalHr > 7)
        {
            cout << "How much did dinner cost in the last day? $";
            cin >> dnr2;
        }
        else
        cout << "Time of arrival was too early for any meals on the last day!";
    }
    bfast = bfast1 + bfast2;
    lnch = lnch1 + lnch2;
    dnr = dnr1 + dnr2;
/****************************BREAKFAST CALCULATIONS**********************************************/
    oweb1 = bfast1 - B_ALLOW;
    if(oweb1 < 0)
    {
    oweb1 = 0;
    cout << "You owe nothing for breakfast on the first day!" << endl;
    }
    else
    {
    cout << "You owe $" << oweb1 << " for breakfast on the first day!" << endl;
    }

    oweb2 = bfast2 - B_ALLOW;
    if(oweb2 < 0)
    {
    oweb2 = 0;
    cout << "You owe nothing for breakfast on the last day!" << endl;
    }
    else
    {
    cout << "You owe $" << oweb2 << " for breakfast on the last day!" << endl;
    }
/******************************LUNCH CALCULATIONS ***********************************************/
    owel1 = lnch1 - L_ALLOW;
    if(owel1 < 0)
    {
    owel1 = 0;
    cout << "You owe nothing for lunch on the first day!" << endl;
    }
    else
    {
    cout << "You owe $" << owel1 << " for lunch on the first day!" << endl;
    }

    owel2 = lnch2 - L_ALLOW;
    if(owel2 < 0)
    {
    owel2 = 0;
    cout << "You owe nothing for lunch on the last day!" << endl;
    }
    else
    {
    cout << "You owe $" << owel2 << " for lunch on the last day!" << endl;
    }
/********************************DINNER CALCULATIONS **********************************************/
    owed1 = dnr1 - D_ALLOW;
    if(owed1 < 0)
    {
    owed1 = 0;
    cout << "you owe nothing for dinner on the first day!" << endl;
    }
    else
    {
    cout << "You owe $" << owed1 << " for dinner on the first day!" << endl;
    }

    owed2 = dnr2 - D_ALLOW;
    if(owed2 < 0)
    {
    owed2 = 0;
    cout << "you owe nothing for dinner on the last day!" << endl;
    }
    else
    {
    cout << "You owe $" << owed2 << " for dinner on the last day!" << endl;
    }
    

}