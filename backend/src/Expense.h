#ifndef EXPENSE_H
#define EXPENSE_H

#include "User.h"
#include <map>

// Derived class demonstrating Inheritance
class Expense : public User {
protected:
    double rent;
    double groceries;
    double utilities;
    double transportation;
    double entertainment;
    double healthcare;
    double education;
    double shopping;
    double otherExpenses;
    
public:
    Expense() : User(), rent(0), groceries(0), utilities(0), 
                transportation(0), entertainment(0), healthcare(0),
                education(0), shopping(0), otherExpenses(0) {}
    
    Expense(string name, string mon) : User(name, mon),
                                       rent(0), groceries(0), utilities(0),
                                       transportation(0), entertainment(0),
                                       healthcare(0), education(0),
                                       shopping(0), otherExpenses(0) {}
    
    // Setters
    void setRent(double r) { rent = r; }
    void setGroceries(double g) { groceries = g; }
    void setUtilities(double u) { utilities = u; }
    void setTransportation(double t) { transportation = t; }
    void setEntertainment(double e) { entertainment = e; }
    void setHealthcare(double h) { healthcare = h; }
    void setEducation(double ed) { education = ed; }
    void setShopping(double s) { shopping = s; }
    void setOtherExpenses(double o) { otherExpenses = o; }
    
    // Getters
    double getRent() const { return rent; }
    double getGroceries() const { return groceries; }
    double getUtilities() const { return utilities; }
    double getTransportation() const { return transportation; }
    double getEntertainment() const { return entertainment; }
    double getHealthcare() const { return healthcare; }
    double getEducation() const { return education; }
    double getShopping() const { return shopping; }
    double getOtherExpenses() const { return otherExpenses; }
    
    // Calculate total expenses
    double getTotalExpenses() const {
        return rent + groceries + utilities + transportation + 
               entertainment + healthcare + education + shopping + otherExpenses;
    }
    
    // Get expense breakdown as map
    map<string, double> getExpenseBreakdown() const {
        map<string, double> breakdown;
        breakdown["Rent"] = rent;
        breakdown["Groceries"] = groceries;
        breakdown["Utilities"] = utilities;
        breakdown["Transportation"] = transportation;
        breakdown["Entertainment"] = entertainment;
        breakdown["Healthcare"] = healthcare;
        breakdown["Education"] = education;
        breakdown["Shopping"] = shopping;
        breakdown["Other"] = otherExpenses;
        return breakdown;
    }
    
    // Override display function - Polymorphism
    void display() override {
        User::display();
        cout << "\n--- Expense Details ---" << endl;
        cout << "Rent: $" << rent << endl;
        cout << "Groceries: $" << groceries << endl;
        cout << "Utilities: $" << utilities << endl;
        cout << "Transportation: $" << transportation << endl;
        cout << "Entertainment: $" << entertainment << endl;
        cout << "Healthcare: $" << healthcare << endl;
        cout << "Education: $" << education << endl;
        cout << "Shopping: $" << shopping << endl;
        cout << "Other: $" << otherExpenses << endl;
        cout << "Total Expenses: $" << getTotalExpenses() << endl;
    }
};

#endif
