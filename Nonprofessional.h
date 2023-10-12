#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H

#include "Employee.h" // Include the base class header

class Nonprofessional : public Employee {
public:
    // Constructor for Nonprofessional class
    Nonprofessional(std::string name, int employeeID, double hourlyRate, double workedHours);

    // Implementations for abstract functions from the base class
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;

private:
    double hourlyRate;
    double workedHours;
};

#endif

