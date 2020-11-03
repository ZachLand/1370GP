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
void meals(int, int, int, string, string, double&, double&);
void mealComp(double, double, double, double&, double&, double&,
        double&, double&, double& );
void printResults(int, int, int, string, int, int, string, double, 
        double, int, double, double, double, double, double, double, double, double);

int main () 
/* These will more than likely be broken up into other Functions
 I've placed them in int main just so we could start building*/
{
    double inBudget, overBudget;
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
    double allowanceTotal, allowanceExceeded;
    meals(days, timeOfDepartureHr, timeOfArrivalHr, am_pm_depart, am_pm_arrive, allowanceTotal, allowanceExceeded);
    

    printResults(days, timeOfDepartureHr, timeOfDepartureMin, am_pm_depart, 
        timeOfArrivalHr, timeOfArrivalMin, am_pm_arrive, airfare, 
        carRental, milesDriven, allowanceVeh, feeParking, feeTaxi, feeConf, feeHotel, 
        feeParkingExcess, allowanceTotal, allowanceExceeded);

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
    while(!((a>0 && a<=12) && (b>=0 && b<=59) && 
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
        double fc, double h, double fpe, double allowanceTotal, double allowanceExceeded)
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
    cout << "allowancetotal = $" << allowanceTotal << endl;
    cout << "allowanceExceeded = $" << allowanceExceeded << endl;
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
    
    if(choice == 1)
    {
        cout << "Enter miles driven: ";
        milesDriven = getValue();
        allowanceVeh = milesDriven * ALLOWANCE_VEHICLE;
    }
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
void meals(int days, int timeOfDepartureHr, int timeOfArrivalHr, string am_pm_depart, string am_pm_arrive, double& allowanceTotal, double& allowanceExceeded)
{
    double bfast1, lnch1, dnr1, bfast2, lnch2, dnr2, bfastT, lnchT, dnrT, oweb1, oweb2,
    oweb, owel1, owel2, owel, owed1, owed2, owed, bfast, lnch, dnr, bfastTemp, lnchTemp, dnrTemp,
    breakfast_total_allowance = 0, lunch_total_allowance = 0, dinner_total_allowance = 0,
    breakfast_total_exceeded = 0, lunch_total_exceeded = 0, dinner_total_exceeded = 0;
    int i;

/******** FIRST DAY ****************************************************************************/
    if (am_pm_depart == "am" || am_pm_depart == "AM")
    {
        if (timeOfDepartureHr < 7)
        {
        cout << "How much did breakfast cost on the first day? $";
        cin >> bfast;
        cout << "How much did lunch cost on the first day? $";
        cin >> lnch;
        cout << "How much did dinner cost on the first day? $";
        cin >> dnr;
        }
        else if (timeOfDepartureHr >= 7 && timeOfDepartureHr < 12)
        {
        cout << "How much did lunch cost on the first day? $";
        cin >> lnch;
        cout << "How much did dinner cost on the first day? $";
        cin >> dnr;
        }
    }
    if (am_pm_depart == "pm" || am_pm_depart == "PM")
    {
        if (timeOfDepartureHr < 6)
        {
            cout << "How much did dinner cost on the first day? $";
            cin >> dnr;
        }
        else
        cout << "Time of departure was too late for any meals on the first day!";
    }
    mealComp(bfast, lnch, dnr, breakfast_total_allowance, breakfast_total_exceeded, 
        lunch_total_allowance, lunch_total_exceeded, dinner_total_allowance,
        dinner_total_exceeded);
    /***********Days inbetween*******************************************/
    for(i = 2; i < days; i++)
    {
        cout << "On day " << i << endl;
        cout << "How much did breakfast cost? $";
        cin >> bfast;
        cout << "How much did lunch cost? $";
        cin >> lnch;
        cout << "How much did dinner cost? $";
        cin >> dnr;

        mealComp(bfast, lnch, dnr, breakfast_total_allowance, breakfast_total_exceeded, 
        lunch_total_allowance, lunch_total_exceeded, dinner_total_allowance,
        dinner_total_exceeded);
    }
    
/******* LAST DAY *****************************************************************************/
    if (am_pm_arrive == "am" || am_pm_arrive == "AM")
    {
        if (timeOfArrivalHr > 7)
        {
            cout << "How much did dinner cost on the last day? $";
            cin >> dnr2;
        }
        
    }
    if (am_pm_arrive == "pm" || am_pm_arrive == "PM")
    {
        if (timeOfArrivalHr < 1)
        {
            cout << "How much did dinner cost on the last day? $";
            cin >> dnr;
        }
        else if (timeOfArrivalHr > 0 && timeOfArrivalHr < 7)
        {
            cout << "How much did lunch cost on the last day? $";
            cin >> lnch;
            cout << "How much did dinner cost on the first day? $";
            cin >> dnr;
        }
        else if (timeOfArrivalHr > 6)
        {
            cout << "How much did breakfast cost on the first day? $";
            cin >> bfast;
            cout << "How much did lunch cost on the first day? $";
            cin >> lnch;
            cout << "How much did dinner cost on the first day? $";
            cin >> dnr;
        }
        else
        cout << "Time of arrival was too early for any meals on the last day!";
    }
    mealComp(bfast, lnch, dnr, breakfast_total_allowance, breakfast_total_exceeded, 
        lunch_total_allowance, lunch_total_exceeded, dinner_total_allowance,
        dinner_total_exceeded);

    allowanceTotal = breakfast_total_allowance + lunch_total_allowance + dinner_total_allowance;
    allowanceExceeded = breakfast_total_exceeded + lunch_total_exceeded + dinner_total_exceeded;
}

/************ Meal Calc ************************************************/
void mealComp(double bfast, double lnch, double dnr, double& breakfast_total_allowance, 
        double& breakfast_total_exceeded, double& lunch_total_allowance,
        double& lunch_total_exceeded, double& dinner_total_allowance,
        double& dinner_total_exceeded)
{
    static const double B_ALLOW = 18;
    static const double L_ALLOW = 12;
    static const double D_ALLOW = 20;

    if ((bfast - B_ALLOW) > 0)
    {
        breakfast_total_exceeded += (bfast - B_ALLOW);
        breakfast_total_allowance += B_ALLOW;
    }
    else   
        breakfast_total_allowance += bfast;
    if ((lnch - L_ALLOW) > 0)
    {
        breakfast_total_exceeded += (lnch - L_ALLOW); 
        breakfast_total_allowance += L_ALLOW;
    }
    else   
        breakfast_total_allowance += lnch;
    if ((dnr - D_ALLOW) > 0)
    {
        breakfast_total_exceeded += (dnr - D_ALLOW); 
        breakfast_total_allowance += D_ALLOW;
    }
    else   
        breakfast_total_allowance += dnr;
}