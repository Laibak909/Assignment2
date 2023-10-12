#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "Employee.h" // Include the base class header

class Professional : public Employee {
public:
    // Constructor for Professional class
    Professional(std::string name, int employeeID, double monthlySalary, int vacationDays);

    // Implementations for abstract functions from the base class
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;

private:
    double monthlySalary;
    int vacationDays;
};

#endif

