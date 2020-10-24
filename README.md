# 1370 Group Project 11-01-2020

This is where we will share our group project for the 1370 class.
VSC gave me some trouble with setting up the repository for syncing and updating, but I think we should be good now. 
If you want, you can also try to clone it, but I will see if you need any permissions. I doubt you do since I've made it public.
_________________________

# Group Project (100 points):

## Travel Expenses

### This program should be designed and written by a team of students. Here are some suggestions:

    • One student should design function main, which will call the other functions in the program. The rest of the functions should be designed by other team members.

    • Analyze the program requirements so each student is given about the same workload.

    • Decide on the function names, parameters, and return types in advance.

    • Use stubs and drivers to test and debug the program.

    • The program can be implemented either as a multifile program, or all the functions can be cut and pasted into the main file.

### Here is the assignment. Write a program that calculates and displays the total travel expenses of a businessperson on a trip. The program should have functions that ask for and return the following:

    • The total number of days spent on the trip

    • The time of departure on the first day of the trip and the time of arrival back home on the last day of the trip

    • The amount of any round -trip airfare

    • The amount of any car rentals

    • Miles driven, if a private vehicle was used. Vehicle allowance is $0.58 per mile.

    • Parking fees. (The company allows up to $12 per day. Anything in excess of this must be paid by the employee.)

    • Taxi fees. (The company allows up to $40 per day for each day a taxi was used. Anything in excess of this must be paid by the employee.)

    • Conference or seminar registration fees

    • Hotel expenses. (The company allows up to $90 per night for lodging. Anything in excess of this amount must be paid by the employee.)

    • The cost of each meal eaten. On the first day of the trip, breakfast is allowed as an expense if the time of departure is before 7 a.m. Lunch is allowed if the time of departure is before noon. Dinner is allowed if the time of departure is before 6 p.m. On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m. Lunch is allowed if the time of arrival is after 1 p.m. Dinner is allowed if the time of arrival is after 7 p.m. The program should only ask for the costs of allowable meals. (The company allows up to $18 for breakfast, $12 for lunch, and $20 for dinner. Anything in excess of this must be paid by the employee.)

The program should perform the necessary calculations to determine the total amount spent by the business traveler in each category (mileage charges, parking, hotel, meals, etc.) as well as the maximum amount allowed in each category. It should then create a nicely formatted expense report that includes the amount spent and the amount allowed in each category, as well as the total amount spent, and total amount allowed for the entire trip. This report should be written to a file.

<I>Input Validation: The program should not accept negative numbers for any dollar amount or for miles driven in a private vehicle. It should also ensure that the number of days is at least 1 and that the time of departure and the time of arrival are valid.
