#include <iostream>
#include "Employee.h"
#include "Professional.h"
#include "Nonprofessional.h"

using namespace std;

// Constructor for the base
 Employee::Employee(std::string name, int employeeID)
         : name(name), employeeID(employeeID) {
     
}

 // Member function to display employee information
 void Employee::displayEmployeeInfo() const {
     cout << " Employee Name: " << name << endl;
     cout << " Employee ID: " << employeeID << endl;
     cout << endl;
 }


// Constructor for Professional class
Professional::Professional(std::string name, int employeeID, double monthlySalary, int vacationDays)
    : Employee(name, employeeID), monthlySalary(monthlySalary), vacationDays(vacationDays) {
}

// Implementations for Professional class
double Professional::calculateWeeklySalary() const {
    // Assuming a month has 4 weeks on average
    return monthlySalary / 4;
}

double Professional::calculateHealthCareContributions() const {
    // Implement logic for health care contributions for professionals
    // You can add specific calculations here
    return 0.0;
}

int Professional::calculateVacationDays() const {
    return vacationDays;
}

// Derived class Nonprofessional

// Constructor for Nonprofessional class
Nonprofessional::Nonprofessional(std::string name, int employeeID, double hourlyRate, double workedHours)
    : Employee(name, employeeID), hourlyRate(hourlyRate), workedHours(workedHours) {
}

// Implementations for Nonprofessional class
double Nonprofessional::calculateWeeklySalary() const {
    return hourlyRate * workedHours;
}

double Nonprofessional::calculateHealthCareContributions() const {
    // Implement logic for health care contributions for nonprofessionals
    // You can add specific calculations here
    return 0.0;
}

int Nonprofessional::calculateVacationDays() const {
    // Assuming 1 hour worked earns 0.01 vacation day
    return static_cast<int>(workedHours * 0.01);
}


int main() {
    
 
    Professional prof("Laiba Khan", 156, 15000.0, 30);
    Nonprofessional nonProf("Donna Cox", 34, 15.0, 15);

    cout << endl;
    cout << " Professional Employee Info:" << std::endl;
    prof.displayEmployeeInfo();

    cout << " Professional Weekly Salary: " << prof.calculateWeeklySalary() << endl;
    cout << " Professional Health Care Contributions: " << prof.calculateHealthCareContributions() << endl;
    cout << " Professional Vacation Days: " << prof.calculateVacationDays() << endl;


    cout << endl; 
    cout << " Nonprofessional Employee Info:" << endl;
    nonProf.displayEmployeeInfo();

    cout << " Nonprofessional Weekly Salary: " << nonProf.calculateWeeklySalary() << endl;
    cout << " Nonprofessional Health Care Contributions: " << nonProf.calculateHealthCareContributions() << std::endl;
    cout << " Nonprofessional Vacation Days: " << nonProf.calculateVacationDays() << endl;

    return 0;
}

