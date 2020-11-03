#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Prototypes
double getValue();
void getTime(int&, int&, string&);
void milesDrivenCalc(const double&, int&, double&, string&);
void getFees(const double&, double&, double&, int);
void meals(int, int, int, string, string, double&, double&);
void feeLoop(int, const double, double&, double&, int&);
void hotelFeeLoop(int, const double, double&, double&);
void parkingFeeLoop(int, const double, double&, double&);
void mealComp(double, double, double, double&, double&, double&,
        double&, double&, double& );
void printResult(int, int, int, string, int, int, string, double, 
        double, string, int, double, int, double, double, int, 
        double, double, double, int, double, double, double, double);

ofstream outFile;


int main () 
/* These will more than likely be broken up into other Functions
 I've placed them in int main just so we could start building*/
{
    double inBudget, overBudget;
    // The total number of days spent on the trip.
    // DONE
    outFile.open("Trip Expenses.txt");
    int days;
    cout << "Days: ";
    do
    {
        days = getValue();
        if (days < 1)
            cout << "ERROR: Days need to be greater than 0." << endl;
    } while (days < 1);

    
    /* The time of departure of the trip and 
        the time of arrival back home of the trip */
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
    cout << "Airfare: $";
    airfare = getValue();

    // The amount of any car rentals
    double carRental;
    cout << "Car rental cost: $";
    carRental = getValue();

    /* Miles driven, if a private vehicle was used. Vehicle allowance 
        is $0.58 per mile. */
    // DONE
    double allowanceVeh = 0;
    int milesDriven = 0;
    string privateVeh;
    const double ALLOWANCE_VEHICLE = 0.58;
    milesDrivenCalc(ALLOWANCE_VEHICLE, milesDriven, allowanceVeh, privateVeh);

    /* Parking fees. (The company allows up to $12 per day. Anything
        in excess of this must be paid by the employee.)*/
    // DONE
    int parkingDays;
    double parkingAllowTot, parkingAllowExceed = 0;
    const double ALLOWANCE_PARKING = 12.00;
    cout << "\nHow much were the parking fees? " << endl;
    feeLoop(days, ALLOWANCE_PARKING, parkingAllowExceed, parkingAllowTot, parkingDays);

    /* Taxi fees. (The company allows up to $40 per day for each day
        a taxi was used. Anything in excess of this must be paid by the employee.)*/
    int taxiDays;
    double taxiAllowExceed = 0, taxiAllowTot;
    const double ALLOWANCE_TAXI = 40.00;
    cout << "\nHow much were the taxi fees? " << endl;
    feeLoop(days, ALLOWANCE_TAXI, taxiAllowExceed, taxiAllowTot, taxiDays);

    // Conference or seminar registration fees
    double feeConf;
    cout << "\nConference or seminar registration fees: $";
    feeConf = getValue();

    /* Hotel expenses. (The company allows up to $90 per night for
        lodging. Anything in excess of this amount must be paid by the employee.)*/
    double hotelAllowExceed = 0, hotelAllowTot;
    const double ALLOWANCE_HOTEL = 90.00;
    int hotelDays;
    //getFees(ALLOWANCE_HOTEL, hotelAllowTot, hotelAllowExceed, days);
    cout << "\nHow much were the hotel fees? " << endl;
    feeLoop(days, ALLOWANCE_HOTEL, hotelAllowExceed, hotelAllowTot, hotelDays);

    /* The cost of each meal eaten. of the trip,
        breakfast is allowed as an expense if the time of departure
        is before 7 a.m. Lunch is allowed if the time of departure is
        before noon. Dinner is allowed if the time of departure is before
        6 p.m. of the trip, breakfast is allowed if the
        time of arrival is after 8 a.m. Lunch is allowed if the time of
        arrival is after 1 p.m. Dinner is allowed if the time of arrival
        is after 7 p.m. The program should only ask for the costs of
        allowable meals. (The company allows up to $18 for breakfast,
        $12 for lunch, and $20 for dinner. Anything in excess of this
        must be paid by the employee.)*/
    double allowanceTotal, allowanceExceeded = 0;
    cout << "\n***Meals on Trip***" << endl;
    meals(days, timeOfDepartureHr, timeOfArrivalHr, am_pm_depart, am_pm_arrive, 
            allowanceTotal, allowanceExceeded);
    
    printResult( days,  timeOfDepartureHr,  timeOfDepartureMin,  am_pm_depart, 
         timeOfArrivalHr,  timeOfArrivalMin,  am_pm_arrive,  airfare, 
         carRental,  privateVeh,  milesDriven, allowanceVeh, parkingDays, 
         parkingAllowTot,  parkingAllowExceed,  taxiDays,  taxiAllowTot,
         taxiAllowExceed,  feeConf,  hotelDays,  hotelAllowTot, 
         hotelAllowExceed,  allowanceTotal,  allowanceExceeded);


    outFile.close();
    return 0;
}
/******************************************************************************************/
double getValue()
{
    /* I think we will need to change this since we will be dealing
        int and doubles throughout the program.*/
    // Declare static variable
    static double a;

    // Get input from keyboard
    cin >> a;

    // While not a number nor within range, clear and loop.
    while(a<0 || cin.fail())
    {
        cout << "Error: Invalid value" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> a;
    }
    return a;
}

void getTime(int& a, int& b, string& d)
{
    static char c; /* We can use time as integers having them separated
                    with ':' */
    // Get input from keyboard
    cin >> a >> c >> b >> d;

    // While not withing range of hr and mins, clear and loop.
    while(!((a>0 && a<=12) && (b>=0 && b<=59) && 
        (d=="AM"||d=="am"||d=="PM"||d=="pm")))
    {
        cout << "Please enter a valid time" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> a >> c >> b >> d;
    }
    // Change from lowercase to uppercase for same style.
    if(d=="am")
        d = "AM";
    if(d=="pm")
        d = "PM";
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
void printResult(int days, int timeOfDeparHr, int timeOfDepartMin, string am_pm_depart, 
        int timeOfArriveHr, int timeOfArriveMin, string am_pm_arrive, double airfare, 
        double carRental, string privateVeh, int milesDriven, double allowanceVeh, 
        int parkingDays, double parkingAllow, double parkingExceed, int taxiDays, 
        double taxiAllow, double taxiExceed, double confFees, int hotelDays, 
        double hotelAllow, double hotelExceed, double mealsAllow, double mealsExceed)
{
    // Declare variables
    double totalAllow, totalExceed;
    totalAllow = airfare + carRental + allowanceVeh + parkingAllow + taxiAllow + confFees + hotelAllow + mealsAllow;
    totalExceed = parkingExceed + taxiExceed + hotelExceed + mealsExceed;

    // Output results to Terminal
    cout << "\n\t***** BUSINESS EXPENSE REPORT *****\n\n";
    cout << "Days:\t\t\t" << days << endl;
    cout << "Time of Departure:\t" << setw(2) << setfill('0') << timeOfDeparHr 
            << ':' << setw(2) << setfill('0') << timeOfDepartMin
            << ' ' << am_pm_depart << endl;
    cout << "Time of Arrival:\t" << setw(2) << setfill('0') << timeOfArriveHr << ':' 
            << setw(2) << setfill('0') << timeOfArriveMin << ' '
            << am_pm_arrive << endl;

    cout << "/////////////////////////////////////////" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << setfill(' ') << setw(20) << "ITEMS" << setw(30) << "USED" << setw(25) << "WITHIN ALLOWANCES" << setw(15) << "EXCEEDANCE" << endl;
    cout << "Airfare" << setw(56) << "$" << airfare << endl;
    cout << "Car Rental" << setw(53) << "$" << carRental << endl;
    cout << "Private Vehicle Used:" << setw(28) << privateVeh << endl;
    cout << "\tMiles Driven ($0.58/mile)" << setw(14) << milesDriven << " miles\t" << setw(7) << "$" << allowanceVeh << endl;
    cout << "Parking Fees ($12/day)" << setw(25) << parkingDays << " days\t" << setw(7) << "$" << parkingAllow << "\t" << setw(11) << "$" << parkingExceed << endl;
    cout << "Taxi Fees ($40/day)" << setw(28) << taxiDays << " days\t" << setw(7) << "$" << taxiAllow << "\t" << setw(11) << "$" << taxiExceed << endl;
    cout << "Conference/Seminar Registration Fees: " << setw(25) << "$" << confFees << endl;
    cout << "Hotel Fees ($90/night)" << setw(25) << hotelDays << " nights\t" << setw(7) << "$" << hotelAllow << "\t" << setw(11) << "$" << hotelExceed << endl;
    cout << "Meals" << setw(58) << "$" << mealsAllow << "\t" << setw(11) << "$" << mealsExceed << endl;
    cout << "---------------------------------------" << setw(31) << "---------" << setw(20) << "----------" << endl;
    cout << "Total" << setw(58) << "$" << totalAllow << "\t" << setw(11) << "$" << totalExceed << endl;

    cout << "\n\nThe total amount for this trip was $" << totalExceed + totalAllow << ", of which you will have to pay $" << totalExceed << " for exceeding the budget." << endl;

    // Output results to file.
    outFile << "\n\t***** BUSINESS EXPENSE REPORT *****\n\n";
    outFile << "Days:\t\t\t" << days << endl;
    outFile << "Time of Departure:\t" << setw(2) << setfill('0') << timeOfDeparHr 
            << ':' << setw(2) << setfill('0') << timeOfDepartMin
            << ' ' << am_pm_depart << endl;
    outFile << "Time of Arrival:\t" << setw(2) << setfill('0') << timeOfArriveHr << ':' 
            << setw(2) << setfill('0') << timeOfArriveMin << ' '
            << am_pm_arrive << endl;

    outFile << "/////////////////////////////////////////" << endl;
    outFile << fixed << showpoint << setprecision(2);
    outFile << setfill(' ') << setw(20) << "ITEMS" << setw(30) << "USED" << setw(25) << "WITHIN ALLOWANCES" << setw(15) << "EXCEEDANCE" << endl;
    outFile << "Airfare" << setw(56) << "$" << airfare << endl;
    outFile << "Car Rental" << setw(53) << "$" << carRental << endl;
    outFile << "Private Vehicle Used:" << setw(28) << privateVeh << endl;
    outFile << "\tMiles Driven ($0.58/mile)" << setw(18) << milesDriven << " miles\t" << setw(7) << "$" << allowanceVeh << endl;
    outFile << "Parking Fees ($12/day)" << setw(25) << parkingDays << " days\t" << setw(7) << "$" << parkingAllow << "\t" << setw(11) << "$" << parkingExceed << endl;
    outFile << "Taxi Fees ($40/day)" << setw(28) << taxiDays << " days\t" << setw(7) << "$" << taxiAllow << "\t" << setw(11) << "$" << taxiExceed << endl;
    outFile << "Conference/Seminar Registration Fees: " << setw(25) << "$" << confFees << endl;
    outFile << "Hotel Fees ($90/night)" << setw(25) << hotelDays << " nights\t" << setw(7) << "$" << hotelAllow << "\t" << setw(11) << "$" << hotelExceed << endl;
    outFile << "Meals" << setw(58) << "$" << mealsAllow << "\t" << setw(11) << "$" << mealsExceed << endl;
    outFile << "---------------------------------------" << setw(31) << "---------" << setw(20) << "----------" << endl;
    outFile << "Total" << setw(58) << "$" << totalAllow << "\t" << setw(11) << "$" << totalExceed << endl;

    outFile << "\n\nThe total amount for this trip was $" << totalExceed + totalAllow << ", of which you will have to pay $" << totalExceed << " for exceeding the budget." << endl;
}
/******************************************************************************************/
void milesDrivenCalc(const double& ALLOWANCE_VEHICLE, int& milesDriven, double& allowanceVeh, string& privateVeh)
{
    int choice;
    privateVeh = "No";
    
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
        privateVeh = "Yes";
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
    if (feeExcess < 0)
        feeExcess = 0;
}
/******************************************************************************************/
void meals(int days, int timeOfDepartureHr, int timeOfArrivalHr, string am_pm_depart, 
        string am_pm_arrive, double& allowanceTotal, double& allowanceExceeded)
{
    // Declare variables and initialize to zero.
    double bfast, lnch, dnr, breakfast_total_allowance = 0, lunch_total_allowance = 0, 
    dinner_total_allowance = 0, breakfast_total_exceeded = 0, lunch_total_exceeded = 0,
    dinner_total_exceeded = 0;
    int i;

/******** FIRST DAY ****************************************************************************/
    // Conditions for AM on first day.
    cout << "\nOn day 1" << endl;
    if (am_pm_depart == "am" || am_pm_depart == "AM")
    {
        // Ask for breakfast, lunch and dinner if betweem midnight and before 7am.
        if (timeOfDepartureHr < 7 || timeOfDepartureHr == 12)
        {
            cout << "How much did breakfast cost? $";
            cin >> bfast;
            cout << "How much did lunch cost? $";
            cin >> lnch;
            cout << "How much did dinner cost? $";
            cin >> dnr;
        }
        // Ask for lunch and dinner if between 7am and before noon.
        else if (timeOfDepartureHr >= 7 && timeOfDepartureHr < 12)
        {
            bfast = 0;
            cout << "How much did lunch cost? $";
            cin >> lnch;
            cout << "How much did dinner cost? $";
            cin >> dnr;
        }
    }
    // Conditions for PM on first day.
    if (am_pm_depart == "pm" || am_pm_depart == "PM")
    {
        // Ask for dinner if between 12pm and before 6pm
        if (timeOfDepartureHr < 6 || timeOfDepartureHr == 12)
        {
            bfast = lnch = 0;
            cout << "How much did dinner cost? $";
            cin >> dnr;
        }
    }
    // Call function to calculate allowanaces and exceedance for each meal.
    mealComp(bfast, lnch, dnr, breakfast_total_allowance, breakfast_total_exceeded, 
        lunch_total_allowance, lunch_total_exceeded, dinner_total_allowance,
        dinner_total_exceeded);
    /***********Days inbetween*******************************************/
    // if more than 2 day, ask for all meals in between first and last day.
    for(i = 2; i < days; i++)
    {
        cout << "\nOn day " << i << endl;
        cout << "How much did breakfast cost? $";
        cin >> bfast;
        cout << "How much did lunch cost? $";
        cin >> lnch;
        cout << "How much did dinner cost? $";
        cin >> dnr;

        // Call function to calculate allowanaces and exceedance for each meal.
        mealComp(bfast, lnch, dnr, breakfast_total_allowance, breakfast_total_exceeded, 
        lunch_total_allowance, lunch_total_exceeded, dinner_total_allowance,
        dinner_total_exceeded);
    }
    
/******* LAST DAY *****************************************************************************/
    // Conditions for AM on last day.
    if (days >= 2)
    {
        cout << "\nOn day " << days << endl;
        if (am_pm_arrive == "am" || am_pm_arrive == "AM")
        {
            // Ask for breakfast if between 8am and midnight.
            if (timeOfArrivalHr >= 8 && timeOfArrivalHr < 12)
            {
                cout << "How much did breakfast cost? $";
                cin >> bfast;
                lnch = dnr = 0;
            }
            
        }
        // Conditions for PM on last day.
        if (am_pm_arrive == "pm" || am_pm_arrive == "PM")
        {
            // Ask for breakfast if between 8am and midnight.
            // This condition would all arrival time before 1pm.
            if (timeOfArrivalHr == 12)
            {
                cout << "How much did breakfast cost? $";
                cin >> bfast;
                lnch = dnr = 0;
            }
            // Ask for breakfast and lunch if between 1pm and before 7pm.
            else if (timeOfArrivalHr >= 1 && timeOfArrivalHr < 7)
            {
                cout << "How much did breakfast cost? $";
                cin >> bfast;
                cout << "How much did lunch cost? $";
                cin >> lnch;
                dnr = 0;
            }
            // Ask for breakfast, lunch and dinner if between 7 and before midnight.
            else if (timeOfArrivalHr >= 7 && timeOfArrivalHr < 12)
            {
                cout << "How much did breakfast cost? $";
                cin >> bfast;
                cout << "How much did lunch cost? $";
                cin >> lnch;
                cout << "How much did dinner cost? $";
                cin >> dnr;
            }
        }
    }
    else 
        bfast = lnch = dnr = 0;
    // Call function to calculate allowanaces and exceedance for each meal.
    mealComp(bfast, lnch, dnr, breakfast_total_allowance, breakfast_total_exceeded, 
        lunch_total_allowance, lunch_total_exceeded, dinner_total_allowance,
        dinner_total_exceeded);

    // Calculating totals for allowance and exceedance for the total trip.
    allowanceTotal = breakfast_total_allowance + lunch_total_allowance + dinner_total_allowance;
    allowanceExceeded = breakfast_total_exceeded + lunch_total_exceeded + dinner_total_exceeded;
}

/************ Meal Calc ************************************************/
void mealComp(double bfast, double lnch, double dnr, double& breakfast_total_allowance, 
        double& breakfast_total_exceeded, double& lunch_total_allowance,
        double& lunch_total_exceeded, double& dinner_total_allowance,
        double& dinner_total_exceeded)
{
    // Declare static constants
    static const double B_ALLOW = 18;
    static const double L_ALLOW = 12;
    static const double D_ALLOW = 20;

    // Check if meal exceeds the allowance
    if ((bfast - B_ALLOW) > 0)
    {
        // Add the difference to the exceed amount
        breakfast_total_exceeded += (bfast - B_ALLOW);
        breakfast_total_allowance += B_ALLOW;
    } 
    else // Otherwise, simply add it to the total allowance
        breakfast_total_allowance += bfast;

    // Check if meal exceeds the allowance
    if ((lnch - L_ALLOW) > 0)
    {
        // Add the difference to the exceed amount
        lunch_total_exceeded += (lnch - L_ALLOW); 
        lunch_total_allowance += L_ALLOW;
    }
    else // Otherwise, simply add it to the total allowance
        lunch_total_allowance += lnch;

    // Check if meal exceeds the allowance
    if ((dnr - D_ALLOW) > 0)
    {
        // Add the difference to the exceed amount
        dinner_total_exceeded += (dnr - D_ALLOW); 
        dinner_total_allowance += D_ALLOW;
    }
    else // Otherwise, simply add it to the total allowance
        dinner_total_allowance += dnr;
}
/**************TAXI LOOP***********************************************************/
void feeLoop(int days, const double ALLOWANCE, double& allowExceed, double& allowTot, int& daysUsed)
{
    double fees;
    daysUsed = 0, allowTot = 0;
        for(int i = 1; i <= days; i++)
    {
        cout << "On day " << i << ": ";
        fees = getValue();
        
        if (fees > 0)
            daysUsed++;

        if((fees - ALLOWANCE) > 0)
        {
            allowExceed += (fees - ALLOWANCE);
            allowTot += ALLOWANCE;
        }
        else
            allowTot += fees;
    }
    cout << fees << " " << allowTot << " " << allowExceed << endl;
}
