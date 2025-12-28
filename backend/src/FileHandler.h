#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Budget.h"
#include <fstream>
#include <sstream>
#include <vector>

class FileHandler {
private:
    string filename;
    
public:
    FileHandler(string fname = "../data/budgets.txt") : filename(fname) {}
    
    // Save budget to file
    bool saveBudget(const Budget& budget) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "Error: Could not open file for writing!" << endl;
            return false;
        }
        
        file << "USER:" << budget.Income::getUserName() << endl;
        file << "MONTH:" << budget.Income::getMonth() << endl;
        file << "SALARY:" << budget.getSalary() << endl;
        file << "FREELANCE:" << budget.getFreelance() << endl;
        file << "INVESTMENTS:" << budget.getInvestments() << endl;
        file << "OTHER_INCOME:" << budget.getOtherIncome() << endl;
        file << "RENT:" << budget.getRent() << endl;
        file << "GROCERIES:" << budget.getGroceries() << endl;
        file << "UTILITIES:" << budget.getUtilities() << endl;
        file << "TRANSPORTATION:" << budget.getTransportation() << endl;
        file << "ENTERTAINMENT:" << budget.getEntertainment() << endl;
        file << "HEALTHCARE:" << budget.getHealthcare() << endl;
        file << "EDUCATION:" << budget.getEducation() << endl;
        file << "SHOPPING:" << budget.getShopping() << endl;
        file << "OTHER_EXPENSES:" << budget.getOtherExpenses() << endl;
        file << "SAVINGS_GOAL:" << budget.getSavingsGoal() << endl;
        file << "---" << endl;
        
        file.close();
        return true;
    }
    
    // Load budgets from file
    vector<Budget> loadBudgets() {
        vector<Budget> budgets;
        ifstream file(filename);
        
        if (!file.is_open()) {
            cerr << "Info: No existing budget file found." << endl;
            return budgets;
        }
        
        string line;
        Budget currentBudget;
        
        while (getline(file, line)) {
            if (line == "---") {
                budgets.push_back(currentBudget);
                currentBudget = Budget();
                continue;
            }
            
            size_t pos = line.find(':');
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1);
                
                if (key == "USER") currentBudget.Income::setUserName(value);
                else if (key == "MONTH") currentBudget.Income::setMonth(value);
                else if (key == "SALARY") currentBudget.setSalary(stod(value));
                else if (key == "FREELANCE") currentBudget.setFreelance(stod(value));
                else if (key == "INVESTMENTS") currentBudget.setInvestments(stod(value));
                else if (key == "OTHER_INCOME") currentBudget.setOtherIncome(stod(value));
                else if (key == "RENT") currentBudget.setRent(stod(value));
                else if (key == "GROCERIES") currentBudget.setGroceries(stod(value));
                else if (key == "UTILITIES") currentBudget.setUtilities(stod(value));
                else if (key == "TRANSPORTATION") currentBudget.setTransportation(stod(value));
                else if (key == "ENTERTAINMENT") currentBudget.setEntertainment(stod(value));
                else if (key == "HEALTHCARE") currentBudget.setHealthcare(stod(value));
                else if (key == "EDUCATION") currentBudget.setEducation(stod(value));
                else if (key == "SHOPPING") currentBudget.setShopping(stod(value));
                else if (key == "OTHER_EXPENSES") currentBudget.setOtherExpenses(stod(value));
                else if (key == "SAVINGS_GOAL") currentBudget.setSavingsGoal(stod(value));
            }
        }
        
        file.close();
        return budgets;
    }
    
    // Export to JSON format
    bool exportToJSON(const Budget& budget, const string& jsonFile) {
        ofstream file(jsonFile);
        if (!file.is_open()) return false;
        
        file << "{\n";
        file << "  \"user\": \"" << budget.Income::getUserName() << "\",\n";
        file << "  \"month\": \"" << budget.Income::getMonth() << "\",\n";
        file << "  \"income\": {\n";
        file << "    \"salary\": " << budget.getSalary() << ",\n";
        file << "    \"freelance\": " << budget.getFreelance() << ",\n";
        file << "    \"investments\": " << budget.getInvestments() << ",\n";
        file << "    \"other\": " << budget.getOtherIncome() << ",\n";
        file << "    \"total\": " << budget.getTotalIncome() << "\n";
        file << "  },\n";
        file << "  \"expenses\": {\n";
        file << "    \"rent\": " << budget.getRent() << ",\n";
        file << "    \"groceries\": " << budget.getGroceries() << ",\n";
        file << "    \"utilities\": " << budget.getUtilities() << ",\n";
        file << "    \"transportation\": " << budget.getTransportation() << ",\n";
        file << "    \"entertainment\": " << budget.getEntertainment() << ",\n";
        file << "    \"healthcare\": " << budget.getHealthcare() << ",\n";
        file << "    \"education\": " << budget.getEducation() << ",\n";
        file << "    \"shopping\": " << budget.getShopping() << ",\n";
        file << "    \"other\": " << budget.getOtherExpenses() << ",\n";
        file << "    \"total\": " << budget.getTotalExpenses() << "\n";
        file << "  },\n";
        file << "  \"summary\": {\n";
        file << "    \"balance\": " << budget.getBalance() << ",\n";
        file << "    \"savings\": " << budget.getSavings() << ",\n";
        file << "    \"savingsGoal\": " << budget.getSavingsGoal() << ",\n";
        file << "    \"savingsPercentage\": " << budget.getSavingsPercentage() << "\n";
        file << "  }\n";
        file << "}\n";
        
        file.close();
        return true;
    }
};

#endif
