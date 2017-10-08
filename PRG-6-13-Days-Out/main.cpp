//
//  main.cpp
//  PRG-6-13-Days-Out
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that calculates the average number of days a company's employees are
//  absent. The program should have the following functions:
//
//  * A function called by main that asks the user for the number of employees in the
//    company. This value should be returned as an int. (The function accepts no arguments.)
//  * A function called by  main that accepts one argument: the number of employees in
//    the company. The function should ask the user to enter the number of days each
//    emplopyee missed during the past year. The tota of these days should be return as
//    an int.
//  * A function called by main that takes two arguments: the number of employees in
//    the company and the total number of days absent for all employees during the year.
//
//  Input Validation: Do not accept a number less than 1 for the number of employees. Do
//  not accept a negative number for the days any employee missed.

#include <iostream>
#include <iomanip>

int howManyEmployees(int);
int daysMissed(int);
float calculateAverageDaysMissed(int, int);

using namespace std;

int main()
{
    int intEmployees,
        intDaysMissedTotal;
    
    float fltAverageDaysMissed;
    
    intEmployees = 0; // Initialize to 0
    
    intEmployees = howManyEmployees(intEmployees);
    
    intDaysMissedTotal = daysMissed(intEmployees);
    
    fltAverageDaysMissed = calculateAverageDaysMissed(intEmployees, intDaysMissedTotal);
    
    // Set decimal precision to reasonable amount, fraction of days
    cout << setprecision(1) << fixed << showpoint;
    
    cout << intEmployees << " employees missed "
         << intDaysMissedTotal << " days of work.\n"
         << "That is an average of " << fltAverageDaysMissed << " days per employee.\n";
    
    return 0;
}

int howManyEmployees(int intEmployees)
{
    cout << "How many people are employed at the company?\n";
    cin >> intEmployees;
    // Data validation
    while(!cin || intEmployees <= 0 || intEmployees > 10)
    {
        cout << "Please enter a number between 0 and 10:\n";
        cin.clear();
        cin.ignore();
        cin >> intEmployees;
    }
    
    return intEmployees;
}

int daysMissed(int intEmployees)
{
    int intDaysMissed,
        intDaysMissedTotal;
    
    // Have to initialize at 0 for this to work
    intDaysMissedTotal = 0;
    
    for(int i = 0 ; i < intEmployees ; i++)
    {
        cout << "How many days was this employee absent?\n";
        cin >> intDaysMissed;
        // Data validation
        while(!cin || intDaysMissed < 0 || intDaysMissed > 30)
        {
            cout << "Please enter a valid number between 0 and 30:\n";
            cin.clear();
            cin.ignore();
            cin >> intDaysMissed;
        }
        // Add days this employee missed to running total while loop runs
        intDaysMissedTotal += intDaysMissed;
    }
    
    return intDaysMissedTotal;
}

float calculateAverageDaysMissed(int intEmployees, int intDaysMissedTotal)
{
    float fltAverageDaysMissed;
    
    fltAverageDaysMissed = static_cast<float>(intDaysMissedTotal) /
                           static_cast<float>(intEmployees);
    
    return fltAverageDaysMissed;
}
