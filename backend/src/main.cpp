#include <iostream>
#include <limits>
#include <string>
#include "Budget.h"
#include "FileHandler.h"

using namespace std;

// Template function for input validation
template<typename T>
T getValidatedInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input! Please enter a positive number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void displayMenu() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║   MONTHLY BUDGET TRACKER - MENU        ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;
    cout << "║ 1. Enter User Details                  ║" << endl;
    cout << "║ 2. Enter Income Details                ║" << endl;
    cout << "║ 3. Enter Expense Details               ║" << endl;
    cout << "║ 4. Set Savings Goal                    ║" << endl;
    cout << "║ 5. View Budget Summary                 ║" << endl;
    cout << "║ 6. View Expense Breakdown              ║" << endl;
    cout << "║ 7. Save Budget to File                 ║" << endl;
    cout << "║ 8. Export to JSON                      ║" << endl;
    cout << "║ 9. Load Previous Budgets               ║" << endl;
    cout << "║ 0. Exit                                ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
}

void enterUserDetails(Budget& budget) {
    cout << "\n--- Enter User Details ---" << endl;
    string name = getStringInput("Enter your name: ");
    string month = getStringInput("Enter month (e.g., January 2024): ");
    
    budget.Income::setUserName(name);
    budget.Income::setMonth(month);
    cout << "✓ User details saved!" << endl;
}

void enterIncomeDetails(Budget& budget) {
    cout << "\n--- Enter Income Details ---" << endl;
    
    double salary = getValidatedInput<double>("Enter salary: $");
    budget.setSalary(salary);
    
    double freelance = getValidatedInput<double>("Enter freelance income: $");
    budget.setFreelance(freelance);
    
    double investments = getValidatedInput<double>("Enter investment returns: $");
    budget.setInvestments(investments);
    
    double other = getValidatedInput<double>("Enter other income: $");
    budget.setOtherIncome(other);
    
    cout << "\n✓ Income details saved!" << endl;
    cout << "Total Income: $" << budget.getTotalIncome() << endl;
}

void enterExpenseDetails(Budget& budget) {
    cout << "\n--- Enter Expense Details ---" << endl;
    
    double rent = getValidatedInput<double>("Enter rent/mortgage: $");
    budget.setRent(rent);
    
    double groceries = getValidatedInput<double>("Enter groceries: $");
    budget.setGroceries(groceries);
    
    double utilities = getValidatedInput<double>("Enter utilities (electricity, water, etc.): $");
    budget.setUtilities(utilities);
    
    double transport = getValidatedInput<double>("Enter transportation: $");
    budget.setTransportation(transport);
    
    double entertainment = getValidatedInput<double>("Enter entertainment: $");
    budget.setEntertainment(entertainment);
    
    double healthcare = getValidatedInput<double>("Enter healthcare: $");
    budget.setHealthcare(healthcare);
    
    double education = getValidatedInput<double>("Enter education: $");
    budget.setEducation(education);
    
    double shopping = getValidatedInput<double>("Enter shopping: $");
    budget.setShopping(shopping);
    
    double other = getValidatedInput<double>("Enter other expenses: $");
    budget.setOtherExpenses(other);
    
    cout << "\n✓ Expense details saved!" << endl;
    cout << "Total Expenses: $" << budget.getTotalExpenses() << endl;
}

void setSavingsGoal(Budget& budget) {
    cout << "\n--- Set Savings Goal ---" << endl;
    double goal = getValidatedInput<double>("Enter your savings goal for this month: $");
    budget.setSavingsGoal(goal);
    cout << "✓ Savings goal set to $" << goal << endl;
}

void viewExpenseBreakdown(const Budget& budget) {
    cout << "\n--- Expense Breakdown ---" << endl;
    
    auto breakdown = budget.getExpenseBreakdown();
    double total = budget.getTotalExpenses();
    
    if (total == 0) {
        cout << "No expenses recorded yet." << endl;
        return;
    }
    
    cout << left << setw(20) << "Category" << setw(12) << "Amount" << "Percentage" << endl;
    cout << string(45, '-') << endl;
    
    for (const auto& pair : breakdown) {
        if (pair.second > 0) {
            double percentage = (pair.second / total) * 100;
            cout << left << setw(20) << pair.first 
                 << "$" << setw(11) << fixed << setprecision(2) << pair.second
                 << setprecision(1) << percentage << "%" << endl;
        }
    }
    
    cout << string(45, '-') << endl;
    cout << left << setw(20) << "TOTAL" 
         << "$" << fixed << setprecision(2) << total << endl;
}

void loadPreviousBudgets() {
    FileHandler fileHandler;
    vector<Budget> budgets = fileHandler.loadBudgets();
    
    if (budgets.empty()) {
        cout << "\nNo previous budgets found." << endl;
        return;
    }
    
    cout << "\n--- Previous Budgets ---" << endl;
    for (size_t i = 0; i < budgets.size(); i++) {
        cout << "\n[Budget #" << (i + 1) << "]" << endl;
        displayBudgetSummary(budgets[i]);
    }
}

int main() {
    Budget myBudget;
    FileHandler fileHandler;
    int choice;
    
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║                                               ║" << endl;
    cout << "║      MONTHLY BUDGET TRACKER APPLICATION       ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "║         Manage Your Finances Smartly          ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;
    
    do {
        displayMenu();
        cout << "\nEnter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                enterUserDetails(myBudget);
                break;
                
            case 2:
                enterIncomeDetails(myBudget);
                break;
                
            case 3:
                enterExpenseDetails(myBudget);
                break;
                
            case 4:
                setSavingsGoal(myBudget);
                break;
                
            case 5:
                myBudget.display();
                break;
                
            case 6:
                viewExpenseBreakdown(myBudget);
                break;
                
            case 7:
                if (fileHandler.saveBudget(myBudget)) {
                    cout << "\n✓ Budget saved successfully!" << endl;
                } else {
                    cout << "\n✗ Error saving budget!" << endl;
                }
                break;
                
            case 8: {
                string jsonFile = "../data/budget_" + myBudget.Income::getMonth() + ".json";
                if (fileHandler.exportToJSON(myBudget, jsonFile)) {
                    cout << "\n✓ Budget exported to JSON successfully!" << endl;
                    cout << "File: " << jsonFile << endl;
                } else {
                    cout << "\n✗ Error exporting to JSON!" << endl;
                }
                break;
            }
                
            case 9:
                loadPreviousBudgets();
                break;
                
            case 0:
                cout << "\n╔═══════════════════════════════════════════╗" << endl;
                cout << "║  Thank you for using Budget Tracker!      ║" << endl;
                cout << "║  Keep tracking, keep saving! 💰           ║" << endl;
                cout << "╚═══════════════════════════════════════════╝" << endl;
                break;
                
            default:
                cout << "\n✗ Invalid choice! Please select 0-9." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
