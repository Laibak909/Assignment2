# Assignment2
# Project 1
"Single_Linked_List"
-----------------------------------------------------------------------------------------------------------------------------------------
//Single_Linked_Lish.h

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

template <typename Item_Type>
class Single_Linked_List {
public:
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    bool pop_front();
    bool pop_back();
    Item_Type front();
    Item_Type back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
};

end of .h file
---------------------------------------------------------------------------------------------------------------------------------------

//Single_Linked_List.cpp

#include "Single_Linked_List.h"
#include <iostream>

using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (num_items == 0) {
        tail = nullptr;
    }
    return true;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        return false;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
    return true;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() {
    if (!empty()) {
        return head->data;
    }
    // Handle empty list (you may choose to throw an exception here).
    return Item_Type();
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() {
    if (!empty()) {
        return tail->data;
    }
    // Handle empty list (you may choose to throw an exception here).
    return Item_Type();
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items;
    }
    Node* new_node = new Node(item);
    if (index == 0) {
        new_node->next = head;
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (index == num_items) {
            tail = new_node;
        }
    }
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        if (index == num_items - 1) {
            tail = current;
        }
        num_items--;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // Item not found, return the size of the list.
}



int main() 
{
    Single_Linked_List<int> list;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    cout << endl;
    cout << "  List: ";

    for (Single_Linked_List<int>::Node* current = list.head; current != nullptr; current = current->next) {
        cout << ":::: " << current->data << " --> ";
    }
    cout << "None";
    cout << endl << endl;

    cout << "  *  Front: " << list.front();
    cout << endl << endl;
    cout << "  *  Back: " << list.back() ;
    cout << endl << endl;

    list.insert(2, 100);
    cout << "  Inserted 100 at index 2: " << endl;  
    cout << endl << "  List: ";
    for (Single_Linked_List<int>::Node* current = list.head; current != nullptr; current = current->next) {
        cout << ":::: " << current->data << " --> ";
    }
    cout << "None";
    cout << endl << endl;

    cout << "  Removed item at index 1: " <<  list.remove(1);
    cout << endl;
    for (Single_Linked_List<int>::Node* current = list.head; current != nullptr; current = current->next) {
        cout << "  :::: " << current->data << " -> ";
    }
    cout << "None";
    cout << endl;

    cout << endl;
    cout << "    *  Index of 2: " << list.find(2);
    cout << endl;
    cout << endl;
    cout << "    *  Index of 4: " << list.find(4);
    cout << endl;

    return 0;
}

end of .cpp file
-------------------------------------------------------------------------------------------------------------------------------------

To run this code open the header file and cpp file in the visual studio. Make sure to add the header file in the cpp. Run the programe and it will give the output :


![Screenshot (8)](https://github.com/Laibak909/Assignment2/assets/113943791/f13fa729-d92d-4338-b5a3-3ad97f150d0f)
---------------------------------------------------------------------------------------------------------------------------------------

# Project 2
"Employee"
--------------------------------------------------------------------------------------------------------------------------------------
//Employee.h

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

// Professional.h

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


//Nonprofessional.h

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

//Employee.cpp

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
----------------------------------------------------------------------------------------------------------------------------------------
To run this programe open it in the visual studio. Add Employee.h in Professional.h and Nonprofessional.h. since we have 3 classes add all the classes in the Employee.cpp file. Run the programe and get the output:

![Screenshot (9)](https://github.com/Laibak909/Assignment2/assets/113943791/7c247ee6-3b53-479f-b0b4-ee08c6913b4e)




