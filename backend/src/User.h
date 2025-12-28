#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

// Base class demonstrating Encapsulation
class User {
protected:
    string userName;
    string month;
    
public:
    // Constructor
    User() : userName(""), month("") {}
    
    User(string name, string mon) : userName(name), month(mon) {}
    
    // Virtual function for Polymorphism
    virtual void display() {
        cout << "User: " << userName << endl;
        cout << "Month: " << month << endl;
    }
    
    // Getters
    string getUserName() const { return userName; }
    string getMonth() const { return month; }
    
    // Setters
    void setUserName(string name) { userName = name; }
    void setMonth(string mon) { month = mon; }
    
    // Virtual destructor
    virtual ~User() {}
};

#endif
