# Monthly Budget Tracker - Web Application

## Project Overview

The Monthly Budget Tracker is a full-stack web application that helps users manage their monthly income and expenses efficiently. Built with C++ backend and modern web technologies for the frontend.

## Features

- 📊 Track monthly income and expenses
- 💰 Categorized expense management
- 📈 Real-time balance calculation
- 💾 Data persistence with file handling
- 🎨 Beautiful, modern UI with animations
- 📱 Responsive design

## Technology Stack

### Backend
- **C++**: Core business logic with OOP concepts
  - Inheritance
  - Polymorphism
  - Encapsulation
  - Templates
  - Friend Functions

### Frontend
- **HTML5**: Structure
- **CSS3**: Styling with modern design
- **JavaScript**: Dynamic interactions

## Project Structure

```
Shaza/
├── backend/
│   ├── src/
│   │   ├── main.cpp
│   │   ├── User.h
│   │   ├── Income.h
│   │   ├── Expense.h
│   │   ├── Budget.h
│   │   └── FileHandler.h
│   ├── build/
│   └── Makefile
├── frontend/
│   ├── index.html
│   ├── css/
│   │   └── style.css
│   ├── js/
│   │   └── app.js
│   └── assets/
├── data/
│   └── budgets.json
└── README.md
```

## Installation & Setup

### Prerequisites
- C++ Compiler (g++ or MSVC)
- Web Browser (Chrome, Firefox, Edge)
- Python 3.x (for local server)

### Backend Setup
```bash
cd backend
make
```

### Frontend Setup
```bash
cd frontend
python -m http.server 8000
```

Then open http://localhost:8000 in your browser.

## OOP Concepts Implemented

1. **Inheritance**: User base class inherited by Income and Expense classes
2. **Polymorphism**: Virtual functions for flexible object handling
3. **Encapsulation**: Protected data members with public interfaces
4. **Templates**: Generic functions for data validation
5. **Friend Functions**: Special access for budget calculations

## Future Enhancements

- [ ] Multi-month tracking and comparison
- [ ] Data visualization with charts
- [ ] Export to PDF/Excel
- [ ] Mobile app version
- [ ] Cloud synchronization
- [ ] Budget recommendations using AI

## Contributors

- Shaza Hussain

## License

MIT License
