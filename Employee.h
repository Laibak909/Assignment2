
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include <string>

class Employee {
public:
    // Constructor
    Employee(std::string name, int employeeID);

    // Member function to display employee information
        void displayEmployeeInfo() const;

    // Abstract member functions
    virtual double calculateWeeklySalary() const = 0;
    virtual double calculateHealthCareContributions() const = 0;
    virtual int calculateVacationDays() const = 0;

    // Common data members
    std::string name;
    int employeeID;
};

#endif

