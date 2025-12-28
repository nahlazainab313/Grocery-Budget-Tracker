#ifndef INCOME_H
#define INCOME_H

#include "User.h"

// Derived class demonstrating Inheritance
class Income : public User {
protected:
    double salary;
    double freelance;
    double investments;
    double otherIncome;
    
public:
    Income() : User(), salary(0), freelance(0), investments(0), otherIncome(0) {}
    
    Income(string name, string mon) : User(name, mon), 
                                      salary(0), freelance(0), 
                                      investments(0), otherIncome(0) {}
    
    // Setters
    void setSalary(double sal) { salary = sal; }
    void setFreelance(double free) { freelance = free; }
    void setInvestments(double inv) { investments = inv; }
    void setOtherIncome(double other) { otherIncome = other; }
    
    // Getters
    double getSalary() const { return salary; }
    double getFreelance() const { return freelance; }
    double getInvestments() const { return investments; }
    double getOtherIncome() const { return otherIncome; }
    
    // Calculate total income
    double getTotalIncome() const {
        return salary + freelance + investments + otherIncome;
    }
    
    // Override display function - Polymorphism
    void display() override {
        User::display();
        cout << "\n--- Income Details ---" << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Freelance: $" << freelance << endl;
        cout << "Investments: $" << investments << endl;
        cout << "Other Income: $" << otherIncome << endl;
        cout << "Total Income: $" << getTotalIncome() << endl;
    }
};

#endif
