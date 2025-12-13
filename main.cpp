#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to store grocery item details
struct Item {
    string name;
    float price;
};

int main() {
    float budget;
    int n;

    // Ask for monthly grocery budget
    cout << "Enter your monthly grocery budget: ";
    cin >> budget;

    // Ask for number of grocery items
    cout << "How many grocery items do you want to add? ";
    cin >> n;

    // Create vector to store items
    vector<Item> items(n);

    cin.ignore(); // Clear input buffer

    // Input item names and prices
    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of item " << i + 1 << ": ";
        getline(cin, items[i].name);

        cout << "Enter price of " << items[i].name << ": ";
        cin >> items[i].price;

        cin.ignore(); // Clear buffer for next input
    }

    // Calculate total grocery cost
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += items[i].price;
    }

    // Display grocery summary
    cout << "\n----------- GROCERY SUMMARY -----------\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << items[i].name << " - Rs. " << items[i].price << endl;
    }

    cout << "\nTotal Expenditure: Rs. " << total << endl;
    cout << "Your Budget: Rs. " << budget << endl;

    // Budget check and warning
    if (total > budget) {
        cout << "\n⚠ Warning: You exceeded your budget by Rs. "
             << total - budget << "!" << endl;
    } else {
        cout << "\n✔ You are within your budget. Remaining amount: Rs. "
             << budget - total << endl;
    }

    cout << "---------------------------------------\n";

    return 0;
}