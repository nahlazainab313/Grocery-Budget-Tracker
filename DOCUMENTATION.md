# Monthly Budget Tracker - Project Documentation

## Table of Contents
1. [Abstract](#abstract)
2. [Introduction](#introduction)
3. [Problem Statement](#problem-statement)
4. [System Design](#system-design)
5. [Implementation](#implementation)
6. [Features](#features)
7. [OOP Concepts](#oop-concepts)
8. [Technology Stack](#technology-stack)
9. [Installation Guide](#installation-guide)
10. [User Guide](#user-guide)
11. [Code Structure](#code-structure)
12. [Advantages](#advantages)
13. [Limitations](#limitations)
14. [Future Enhancements](#future-enhancements)
15. [Conclusion](#conclusion)
16. [References](#references)

---

## 1. Abstract

The Monthly Budget Tracker is a comprehensive C++ based web application developed to help users manage their monthly income and expenses efficiently. With increasing daily expenses, it becomes important to track spending and savings in a systematic way. This project allows users to enter income details, record expenses under various categories, calculate total expenses, and determine remaining balance and savings.

The system is implemented using **Object-Oriented Programming (OOP)** concepts to ensure modularity, security, and ease of understanding. The application features both a C++ console backend and a modern web-based frontend, demonstrating the practical application of OOP principles in real-world scenarios.

**Key Features:**
- Multi-category income and expense tracking
- Real-time budget calculations
- Visual analytics with charts
- Data persistence with file handling
- Modern, responsive web interface
- Export functionality (JSON, TXT)

---

## 2. Introduction

Personal financial management plays a vital role in maintaining a balanced lifestyle. Many individuals fail to track their expenses properly, which leads to overspending and poor savings habits. Manual methods such as notebooks or spreadsheets are often inaccurate and time-consuming.

The Monthly Budget Tracker application is designed to overcome these issues by providing a simple and user-friendly system. Using C++ for the backend logic and modern web technologies for the frontend, the project demonstrates how real-life financial problems can be solved effectively by applying object-oriented concepts such as:

- **Inheritance**
- **Polymorphism**
- **Encapsulation**
- **Templates**
- **Friend Functions**

This dual-interface approach (console + web) showcases the versatility of C++ and its integration with web technologies.

---

## 3. Problem Statement

Traditional expense tracking methods are inefficient, error-prone, and difficult to maintain. Procedural programming approaches lack flexibility and reusability when handling complex data such as income and multiple expense categories.

**Challenges Addressed:**
1. **Data Organization**: Efficiently managing multiple income sources and expense categories
2. **Calculation Accuracy**: Ensuring precise financial calculations
3. **Data Persistence**: Storing budget data for future reference
4. **User Experience**: Providing an intuitive interface for data entry and visualization
5. **Scalability**: Designing a system that can be easily extended

**Solution:**
Design a C++ program that can:
- Store user details securely
- Track monthly income and categorized expenses
- Calculate total expenditure and savings accurately
- Provide a clear financial summary
- Export data in multiple formats
- Offer both console and web interfaces

---

## 4. System Design

The system is designed using **Object-Oriented Programming** principles to ensure structured development.

### 4.1 Class Hierarchy

```
User (Base Class)
├── Income (Derived Class)
├── Expense (Derived Class)
└── Budget (Multiple Inheritance from Income & Expense)
```

### 4.2 Inheritance

- **Base Class**: `User` stores common information (user name, month)
- **Derived Classes**: `Income` and `Expense` inherit from `User`
- **Multiple Inheritance**: `Budget` class combines both `Income` and `Expense`

### 4.3 Polymorphism

Polymorphism allows objects of derived classes to be accessed using base class references. The `display()` function is overridden in each derived class to provide specific implementations.

### 4.4 Encapsulation

Data members such as income and expense values are declared as **protected members**. They are accessed only through public member functions, ensuring data security and controlled access.

### 4.5 Friend Function

The `displayBudgetSummary()` friend function has special access to private members of the `Budget` class, allowing efficient summary generation.

### 4.6 Templates

Template functions are used for input validation, providing type-safe and reusable code.

---

## 5. Implementation

### Backend (C++)

The backend is implemented in C++ with the following components:

1. **User.h**: Base class with user information
2. **Income.h**: Income tracking with multiple sources
3. **Expense.h**: Expense tracking with 9 categories
4. **Budget.h**: Comprehensive budget management
5. **FileHandler.h**: Data persistence and export
6. **main.cpp**: Console application with menu system

### Frontend (Web)

The frontend is built with modern web technologies:

1. **index.html**: Semantic HTML5 structure
2. **style.css**: Premium dark theme with animations
3. **app.js**: Interactive JavaScript with Chart.js

---

## 6. Features

### Core Features
✅ User profile management (name, month)
✅ Multi-source income tracking (salary, freelance, investments, other)
✅ Categorized expense tracking (9 categories)
✅ Real-time balance calculation
✅ Savings goal setting and tracking
✅ Progress visualization

### Advanced Features
✅ Visual expense breakdown (pie chart)
✅ Data persistence (localStorage + file system)
✅ Export to JSON format
✅ Export to text summary
✅ Responsive design
✅ Dark theme with glassmorphism
✅ Smooth animations and transitions
✅ Toast notifications

---

## 7. OOP Concepts

### 7.1 Inheritance
```cpp
class Income : public User {
    // Inherits userName and month from User
    // Adds income-specific data and methods
};
```

### 7.2 Polymorphism
```cpp
virtual void display() {
    // Base implementation
}

void display() override {
    // Derived class specific implementation
}
```

### 7.3 Encapsulation
```cpp
protected:
    double salary;
    
public:
    void setSalary(double sal) { salary = sal; }
    double getSalary() const { return salary; }
```

### 7.4 Multiple Inheritance
```cpp
class Budget : public Income, public Expense {
    // Combines functionality from both classes
};
```

### 7.5 Templates
```cpp
template<typename T>
bool validatePositive(T value) {
    return value >= 0;
}
```

### 7.6 Friend Functions
```cpp
friend void displayBudgetSummary(const Budget& budget);
```

---

## 8. Technology Stack

### Backend
- **Language**: C++17
- **Compiler**: g++ (MinGW/MSVC)
- **Build System**: Make
- **Libraries**: Standard Template Library (STL)

### Frontend
- **HTML5**: Semantic structure
- **CSS3**: Modern styling with custom properties
- **JavaScript (ES6+)**: Application logic
- **Chart.js**: Data visualization
- **Font Awesome**: Icons
- **Google Fonts**: Typography (Inter, Outfit)

### Data Storage
- **File System**: Text files for C++ backend
- **localStorage**: Browser-based persistence
- **JSON**: Export format

---

## 9. Installation Guide

### Prerequisites
- C++ Compiler (g++, MSVC, or Clang)
- Web Browser (Chrome, Firefox, Edge)
- Python 3.x (for local server) or any HTTP server

### Backend Setup

#### Windows
```bash
cd backend
mingw32-make
cd build
budget_tracker.exe
```

#### Linux/Mac
```bash
cd backend
make
cd build
./budget_tracker
```

### Frontend Setup

#### Option 1: Python HTTP Server
```bash
cd frontend
python -m http.server 8000
```
Then open `http://localhost:8000`

#### Option 2: Node.js HTTP Server
```bash
cd frontend
npx http-server -p 8000
```

#### Option 3: VS Code Live Server
1. Install Live Server extension
2. Right-click on `index.html`
3. Select "Open with Live Server"

---

## 10. User Guide

### Console Application

1. **Start the Application**
   ```bash
   cd backend/build
   ./budget_tracker
   ```

2. **Main Menu Options**
   - `1`: Enter user details (name, month)
   - `2`: Enter income details
   - `3`: Enter expense details
   - `4`: Set savings goal
   - `5`: View complete budget summary
   - `6`: View expense breakdown
   - `7`: Save budget to file
   - `8`: Export to JSON
   - `9`: Load previous budgets
   - `0`: Exit

### Web Application

1. **Open the Application**
   - Navigate to `http://localhost:8000`

2. **Enter User Details**
   - Fill in your name and month
   - Click "Save Details"

3. **Add Income**
   - Enter income from various sources
   - Click "Save Income" or let it auto-calculate

4. **Add Expenses**
   - Enter expenses in different categories
   - Click "Save Expenses" or let it auto-calculate

5. **Set Savings Goal**
   - Enter your monthly savings target
   - Track progress with the visual progress bar

6. **View Analytics**
   - Check the pie chart for expense breakdown
   - Monitor your budget overview cards

7. **Export Data**
   - Click "Export to JSON" for JSON format
   - Click "Save Budget" for text summary

---

## 11. Code Structure

```
Shaza/
├── README.md                 # Project overview
├── DOCUMENTATION.md          # This file
├── backend/
│   ├── src/
│   │   ├── main.cpp         # Console application
│   │   ├── User.h           # Base class
│   │   ├── Income.h         # Income management
│   │   ├── Expense.h        # Expense management
│   │   ├── Budget.h         # Budget calculations
│   │   └── FileHandler.h    # File I/O operations
│   ├── build/               # Compiled executables
│   └── Makefile             # Build configuration
├── frontend/
│   ├── index.html           # Main HTML file
│   ├── css/
│   │   └── style.css        # Styling
│   ├── js/
│   │   └── app.js           # Application logic
│   └── assets/              # Images, icons
└── data/
    ├── budgets.txt          # Saved budgets (text)
    └── *.json               # Exported JSON files
```

---

## 12. Advantages

### Technical Advantages
✅ **Modular Design**: Easy to maintain and extend
✅ **Type Safety**: C++ strong typing prevents errors
✅ **Performance**: Efficient C++ backend
✅ **Reusability**: OOP principles enable code reuse
✅ **Scalability**: Easy to add new features

### User Advantages
✅ **Simple Interface**: Both console and web options
✅ **Accurate Calculations**: Automated financial math
✅ **Visual Analytics**: Charts for better understanding
✅ **Data Persistence**: Never lose your budget data
✅ **Export Options**: Multiple export formats
✅ **Real-time Updates**: Instant calculation feedback
✅ **Responsive Design**: Works on all devices

### Educational Advantages
✅ **Demonstrates OOP**: Practical application of concepts
✅ **Best Practices**: Clean code and documentation
✅ **Full-Stack**: Backend and frontend integration

---

## 13. Limitations

### Current Limitations
⚠️ **Single Month**: Tracks only one month at a time
⚠️ **No Authentication**: No user login system
⚠️ **Local Storage**: No cloud synchronization
⚠️ **Limited Reports**: Basic reporting features
⚠️ **No Budgeting**: No predictive budgeting
⚠️ **Console Backend**: Web frontend uses localStorage only

### Technical Limitations
⚠️ **No Database**: File-based storage only
⚠️ **No API**: No RESTful API for integration
⚠️ **Single User**: No multi-user support

---

## 14. Future Enhancements

### Short-term Enhancements
🔮 **Multi-month Tracking**: Track and compare multiple months
🔮 **Data Visualization**: More chart types (bar, line, area)
🔮 **PDF Export**: Generate PDF reports
🔮 **Budget Alerts**: Notifications for overspending
🔮 **Category Customization**: Add custom expense categories

### Long-term Enhancements
🔮 **Database Integration**: MySQL/PostgreSQL backend
🔮 **RESTful API**: C++ backend API server
🔮 **User Authentication**: Secure login system
🔮 **Cloud Sync**: Cross-device synchronization
🔮 **Mobile App**: React Native/Flutter app
🔮 **AI Recommendations**: Smart budgeting suggestions
🔮 **Recurring Transactions**: Auto-add monthly expenses
🔮 **Bill Reminders**: Payment due date notifications
🔮 **Investment Tracking**: Portfolio management
🔮 **Tax Calculations**: Tax estimation features

### Advanced Features
🔮 **Machine Learning**: Expense prediction
🔮 **OCR Integration**: Receipt scanning
🔮 **Bank Integration**: Automatic transaction import
🔮 **Multi-currency**: Support for multiple currencies
🔮 **Collaborative Budgets**: Family/shared budgets

---

## 15. Conclusion

The Monthly Budget Tracker project successfully demonstrates the application of **Object-Oriented Programming** concepts in C++. It provides a structured and efficient solution for managing monthly finances.

### Key Achievements
✅ Implemented all major OOP concepts (inheritance, polymorphism, encapsulation, templates, friend functions)
✅ Created both console and web interfaces
✅ Achieved data persistence with file handling
✅ Developed a modern, responsive UI
✅ Provided comprehensive documentation

### Learning Outcomes
This project showcases:
- Practical application of C++ OOP principles
- Integration of C++ with web technologies
- Modern web development practices
- Software design and architecture
- User experience considerations

### Impact
By implementing inheritance, encapsulation, polymorphism, templates, and friend functions, the project achieves **clarity**, **flexibility**, and **reliability**. This system can be further enhanced to meet real-world financial management needs.

---

## 16. References

### Books
1. Bjarne Stroustrup, *The C++ Programming Language* (4th Edition)
2. Stanley Lippman, *C++ Primer* (5th Edition)
3. Scott Meyers, *Effective C++* (3rd Edition)

### Online Resources
1. [cplusplus.com](https://cplusplus.com) – C++ Reference Documentation
2. [GeeksforGeeks](https://geeksforgeeks.org) – Object-Oriented Programming in C++
3. [MDN Web Docs](https://developer.mozilla.org) – Web Development
4. [Chart.js Documentation](https://chartjs.org) – Data Visualization

### Tools & Libraries
1. GCC/MinGW – C++ Compiler
2. Chart.js – JavaScript charting library
3. Font Awesome – Icon library
4. Google Fonts – Web typography

---

## Appendix

### A. Compilation Commands

**Windows (MinGW)**
```bash
g++ -std=c++17 -Wall -Wextra -I./src src/main.cpp -o build/budget_tracker.exe
```

**Linux/Mac**
```bash
g++ -std=c++17 -Wall -Wextra -I./src src/main.cpp -o build/budget_tracker
```

### B. Sample Budget Data

```json
{
  "user": {
    "name": "John Doe",
    "month": "December 2024"
  },
  "income": {
    "salary": 5000,
    "freelance": 1200,
    "investments": 300,
    "other": 150
  },
  "expenses": {
    "rent": 1500,
    "groceries": 600,
    "utilities": 200,
    "transportation": 300,
    "entertainment": 150,
    "healthcare": 100,
    "education": 200,
    "shopping": 250,
    "other": 100
  },
  "savingsGoal": 2000
}
```

### C. Color Palette

- Primary: `#6366f1` (Indigo)
- Secondary: `#8b5cf6` (Purple)
- Success: `#10b981` (Green)
- Warning: `#f59e0b` (Amber)
- Danger: `#ef4444` (Red)
- Background: `#0f172a` (Dark Blue)

---

**Project Developed By**: Shaza Hussain  
**Date**: December 2024  
**Version**: 1.0.0  
**License**: MIT License
