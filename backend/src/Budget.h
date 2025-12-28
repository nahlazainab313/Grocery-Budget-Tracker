#ifndef BUDGET_H
#define BUDGET_H

#include "Income.h"
#include "Expense.h"
#include <iomanip>

// Multiple Inheritance demonstration
class Budget : public Income, public Expense {
private:
    double savingsGoal;
    
public:
    Budget() : Income(), Expense(), savingsGoal(0) {}
    
    Budget(string name, string mon) : Income(name, mon), 
                                      Expense(name, mon),
                                      savingsGoal(0) {
        // Resolve ambiguity by using Income's constructor
        Income::setUserName(name);
        Income::setMonth(mon);
    }
    
    // Resolve ambiguity for getUserName and getMonth
    string getUserName() const { return Income::getUserName(); }
    string getMonth() const { return Income::getMonth(); }
    void setUserName(string name) { Income::setUserName(name); }
    void setMonth(string mon) { Income::setMonth(mon); }
    
    void setSavingsGoal(double goal) { savingsGoal = goal; }
    double getSavingsGoal() const { return savingsGoal; }
    
    // Calculate remaining balance
    double getBalance() const {
        return getTotalIncome() - getTotalExpenses();
    }
    
    // Calculate actual savings
    double getSavings() const {
        double balance = getBalance();
        return (balance > 0) ? balance : 0;
    }
    
    // Check if savings goal is met
    bool isSavingsGoalMet() const {
        return getSavings() >= savingsGoal;
    }
    
    // Get savings percentage
    double getSavingsPercentage() const {
        double totalIncome = getTotalIncome();
        if (totalIncome == 0) return 0;
        return (getSavings() / totalIncome) * 100;
    }
    
    // Friend function declaration for displaying summary
    friend void displayBudgetSummary(const Budget& budget);
    
    // Display complete budget
    void display() override {
        cout << "\n========================================" << endl;
        cout << "     MONTHLY BUDGET TRACKER" << endl;
        cout << "========================================" << endl;
        Income::display();
        cout << "\n";
        Expense::display();
        cout << "\n--- Budget Summary ---" << endl;
        cout << "Total Income: $" << fixed << setprecision(2) << getTotalIncome() << endl;
        cout << "Total Expenses: $" << getTotalExpenses() << endl;
        cout << "Balance: $" << getBalance() << endl;
        cout << "Savings: $" << getSavings() << endl;
        cout << "Savings Goal: $" << savingsGoal << endl;
        cout << "Savings %: " << setprecision(1) << getSavingsPercentage() << "%" << endl;
        
        if (isSavingsGoalMet()) {
            cout << "\n✓ Congratulations! Savings goal achieved!" << endl;
        } else {
            cout << "\n⚠ Savings goal not yet met. Keep going!" << endl;
        }
        cout << "========================================" << endl;
    }
    
    // Template function for validation
    template<typename T>
    bool validatePositive(T value) {
        return value >= 0;
    }
};

// Friend function implementation
void displayBudgetSummary(const Budget& budget) {
    cout << "\n--- Quick Summary ---" << endl;
    cout << "User: " << budget.Income::getUserName() << endl;
    cout << "Month: " << budget.Income::getMonth() << endl;
    cout << "Income: $" << budget.getTotalIncome() << endl;
    cout << "Expenses: $" << budget.getTotalExpenses() << endl;
    cout << "Balance: $" << budget.getBalance() << endl;
}

#endif
