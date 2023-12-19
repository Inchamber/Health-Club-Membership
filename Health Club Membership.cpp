/******************************************************************************
# Author:           Gagandeep Bhatia
# Date:             November 25, 2023
# Description:      This is a Health Club membership program that calculates the users total cost for their membership depending on their age and duration.
# Input:            integer choice, integer choice
# Output:           double charges
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Constants for menu choices
const int ADULT_CHOICE = 1,
CHILD_CHOICE = 2,
SENIOR_CHOICE = 3,
QUIT_CHOICE = 4;

// Constants for membership rates
const double ADULT = 40.0,
CHILD = 20.0,
SENIOR = 30.0;

// Add function prototypes here
void menu();
int Choice(string prompt);
int numMonths(int choice);
double choiceCost(int choice, int months);
void displayCharges(int choice, double charges);

int main() {
    // Variables
    int choice = 0;         // Menu choice
    int months = 0;         // Number of months
    double charges = 0.0;   // Monthly charges

    // Calling functions while the user does not enter 4
    do {
        menu();
        choice = Choice("Enter your choice: ");
        months = numMonths(choice);
        charges = choiceCost(choice, months);
        cout << fixed << showpoint << setprecision(2);
        displayCharges(choice, charges);
    } while (choice != QUIT_CHOICE);

    return 0;
}

// Displaying menu
void menu() {
    cout << "\n\t\tHealth Club Membership Menu\n\n"
        << "1. Standard Adult Membership\n"
        << "2. Child Membership\n"
        << "3. Senior Citizen Membership\n"
        << "4. Quit the Program\n\n";
}

// Inputting and validating choice 
int Choice(string prompt) {
    int choice = 0;
    cout << prompt;
    cin >> choice;
    while (choice < ADULT_CHOICE || choice > QUIT_CHOICE || cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a valid menu choice: ";
        cin >> choice;
    }
    return choice;
}
// Inputting and validating months
int numMonths(int choice) {
    int months = 0;
    if (choice != QUIT_CHOICE) {
        // Get the number of months.
        cout << "For how many months? ";
        cin >> months;

        // Validate the number of months.
        while (months < 0 || months > 60 || cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter months between 0 and 60: ";
            cin >> months;
        }
    }
    return months;
}
// Calculating charges
double choiceCost(int choice, int months) {
    double charges = 0.0;
    switch (choice)
    {
    case ADULT_CHOICE:
        charges = months * ADULT;
        break;
    case CHILD_CHOICE:
        charges = months * CHILD;
        break;
    case SENIOR_CHOICE:
        charges = months * SENIOR;
    }
    return charges;
}

// Displaying charges
void displayCharges(int choice, double charges) {
    if (choice != QUIT_CHOICE) {
        cout << "Your total charges are $" << charges << endl;
        cout << "Thank you for using the Health Club Membership!" << endl;
    }
}