// ===================================
// MONTHLY BUDGET TRACKER - JAVASCRIPT
// Application Logic & Interactivity
// ===================================

// Budget Data Object
let budgetData = {
    user: {
        name: '',
        month: ''
    },
    income: {
        salary: 0,
        freelance: 0,
        investments: 0,
        other: 0
    },
    expenses: {
        rent: 0,
        groceries: 0,
        utilities: 0,
        transportation: 0,
        entertainment: 0,
        healthcare: 0,
        education: 0,
        shopping: 0,
        other: 0
    },
    savingsGoal: 0
};

// Chart instance
let expenseChart = null;

// === Utility Functions ===

function formatCurrency(amount) {
    return new Intl.NumberFormat('en-IN', {
        style: 'currency',
        currency: 'INR',
        maximumFractionDigits: 2
    }).format(amount);
}

function showToast(message, duration = 3000) {
    const toast = document.getElementById('toast');
    const toastMessage = document.getElementById('toastMessage');

    toastMessage.textContent = message;
    toast.classList.add('show');

    setTimeout(() => {
        toast.classList.remove('show');
    }, duration);
}

function saveToLocalStorage() {
    localStorage.setItem('budgetData', JSON.stringify(budgetData));
    showToast('✓ Data saved successfully!');
}

function loadFromLocalStorage() {
    const saved = localStorage.getItem('budgetData');
    if (saved) {
        budgetData = JSON.parse(saved);
        populateFields();
        calculateTotals();
        showToast('✓ Previous data loaded!');
    }
}

function populateFields() {
    // User details
    document.getElementById('userName').value = budgetData.user.name;
    document.getElementById('userMonth').value = budgetData.user.month;

    // Income fields
    document.getElementById('salary').value = budgetData.income.salary || '';
    document.getElementById('freelance').value = budgetData.income.freelance || '';
    document.getElementById('investments').value = budgetData.income.investments || '';
    document.getElementById('otherIncome').value = budgetData.income.other || '';

    // Expense fields
    document.getElementById('rent').value = budgetData.expenses.rent || '';
    document.getElementById('groceries').value = budgetData.expenses.groceries || '';
    document.getElementById('utilities').value = budgetData.expenses.utilities || '';
    document.getElementById('transportation').value = budgetData.expenses.transportation || '';
    document.getElementById('entertainment').value = budgetData.expenses.entertainment || '';
    document.getElementById('healthcare').value = budgetData.expenses.healthcare || '';
    document.getElementById('education').value = budgetData.expenses.education || '';
    document.getElementById('shopping').value = budgetData.expenses.shopping || '';
    document.getElementById('otherExpenses').value = budgetData.expenses.other || '';

    // Savings goal
    document.getElementById('savingsGoal').value = budgetData.savingsGoal || '';
}

// === Calculation Functions ===

function calculateTotalIncome() {
    return Object.values(budgetData.income).reduce((sum, val) => sum + val, 0);
}

function calculateTotalExpenses() {
    return Object.values(budgetData.expenses).reduce((sum, val) => sum + val, 0);
}

function calculateBalance() {
    return calculateTotalIncome() - calculateTotalExpenses();
}

function calculateSavings() {
    const balance = calculateBalance();
    return balance > 0 ? balance : 0;
}

function calculateSavingsPercentage() {
    const totalIncome = calculateTotalIncome();
    if (totalIncome === 0) return 0;
    return (calculateSavings() / totalIncome) * 100;
}

function updateDisplay() {
    const totalIncome = calculateTotalIncome();
    const totalExpenses = calculateTotalExpenses();
    const balance = calculateBalance();
    const savings = calculateSavings();
    const savingsPercentage = calculateSavingsPercentage();

    // Update overview cards
    document.getElementById('totalIncome').textContent = formatCurrency(totalIncome);
    document.getElementById('totalExpenses').textContent = formatCurrency(totalExpenses);
    document.getElementById('balance').textContent = formatCurrency(balance);
    document.getElementById('savings').textContent = formatCurrency(savings);
    document.getElementById('savingsPercentage').textContent =
        `${savingsPercentage.toFixed(1)}% of income`;

    // Update savings progress
    updateSavingsProgress();

    // Update chart
    updateExpenseChart();
}

function calculateTotals() {
    updateDisplay();
}

function updateSavingsProgress() {
    const savings = calculateSavings();
    const goal = budgetData.savingsGoal;

    if (goal === 0) {
        document.getElementById('progressFill').style.width = '0%';
        document.getElementById('progressText').textContent = 'Set a savings goal to track progress';
        return;
    }

    const percentage = Math.min((savings / goal) * 100, 100);
    document.getElementById('progressFill').style.width = `${percentage}%`;

    if (percentage >= 100) {
        document.getElementById('progressText').textContent =
            `🎉 Goal achieved! ${formatCurrency(savings)} / ${formatCurrency(goal)}`;
    } else {
        document.getElementById('progressText').textContent =
            `${percentage.toFixed(1)}% of goal achieved (${formatCurrency(savings)} / ${formatCurrency(goal)})`;
    }
}

// === Chart Functions ===

function initializeChart() {
    const ctx = document.getElementById('expenseChart').getContext('2d');

    expenseChart = new Chart(ctx, {
        type: 'doughnut',
        data: {
            labels: [],
            datasets: [{
                data: [],
                backgroundColor: [
                    '#667eea',
                    '#764ba2',
                    '#f093fb',
                    '#4facfe',
                    '#43e97b',
                    '#fa709a',
                    '#fee140',
                    '#30cfd0',
                    '#a8edea'
                ],
                borderWidth: 0
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: true,
            plugins: {
                legend: {
                    position: 'bottom',
                    labels: {
                        color: '#cbd5e1',
                        padding: 15,
                        font: {
                            size: 12,
                            family: 'Inter'
                        }
                    }
                },
                tooltip: {
                    backgroundColor: 'rgba(30, 41, 59, 0.9)',
                    titleColor: '#f1f5f9',
                    bodyColor: '#cbd5e1',
                    borderColor: 'rgba(255, 255, 255, 0.1)',
                    borderWidth: 1,
                    padding: 12,
                    displayColors: true,
                    callbacks: {
                        label: function (context) {
                            const label = context.label || '';
                            const value = formatCurrency(context.parsed);
                            const total = context.dataset.data.reduce((a, b) => a + b, 0);
                            const percentage = ((context.parsed / total) * 100).toFixed(1);
                            return `${label}: ${value} (${percentage}%)`;
                        }
                    }
                }
            }
        }
    });
}

function updateExpenseChart() {
    if (!expenseChart) return;

    const expenses = budgetData.expenses;
    const labels = [];
    const data = [];

    // Filter out zero values
    Object.entries(expenses).forEach(([key, value]) => {
        if (value > 0) {
            const labelMap = {
                rent: 'Rent/Mortgage',
                groceries: 'Groceries',
                utilities: 'Utilities',
                transportation: 'Transportation',
                entertainment: 'Entertainment',
                healthcare: 'Healthcare',
                education: 'Education',
                shopping: 'Shopping',
                other: 'Other'
            };
            labels.push(labelMap[key]);
            data.push(value);
        }
    });

    if (data.length === 0) {
        labels.push('No expenses recorded');
        data.push(1);
    }

    expenseChart.data.labels = labels;
    expenseChart.data.datasets[0].data = data;
    expenseChart.update();
}

// === Event Handlers ===

function saveUserDetails() {
    budgetData.user.name = document.getElementById('userName').value.trim();
    budgetData.user.month = document.getElementById('userMonth').value.trim();

    if (!budgetData.user.name || !budgetData.user.month) {
        showToast('⚠ Please enter both name and month');
        return;
    }

    saveToLocalStorage();
    showToast('✓ User details saved!');
}

function saveIncome() {
    budgetData.income.salary = parseFloat(document.getElementById('salary').value) || 0;
    budgetData.income.freelance = parseFloat(document.getElementById('freelance').value) || 0;
    budgetData.income.investments = parseFloat(document.getElementById('investments').value) || 0;
    budgetData.income.other = parseFloat(document.getElementById('otherIncome').value) || 0;

    calculateTotals();
    saveToLocalStorage();
    showToast('✓ Income details saved!');
}

function saveExpenses() {
    budgetData.expenses.rent = parseFloat(document.getElementById('rent').value) || 0;
    budgetData.expenses.groceries = parseFloat(document.getElementById('groceries').value) || 0;
    budgetData.expenses.utilities = parseFloat(document.getElementById('utilities').value) || 0;
    budgetData.expenses.transportation = parseFloat(document.getElementById('transportation').value) || 0;
    budgetData.expenses.entertainment = parseFloat(document.getElementById('entertainment').value) || 0;
    budgetData.expenses.healthcare = parseFloat(document.getElementById('healthcare').value) || 0;
    budgetData.expenses.education = parseFloat(document.getElementById('education').value) || 0;
    budgetData.expenses.shopping = parseFloat(document.getElementById('shopping').value) || 0;
    budgetData.expenses.other = parseFloat(document.getElementById('otherExpenses').value) || 0;

    calculateTotals();
    saveToLocalStorage();
    showToast('✓ Expense details saved!');
}

function saveSavingsGoal() {
    const goal = parseFloat(document.getElementById('savingsGoal').value) || 0;

    if (goal < 0) {
        showToast('⚠ Savings goal must be positive');
        return;
    }

    budgetData.savingsGoal = goal;
    updateSavingsProgress();
    saveToLocalStorage();
    showToast('✓ Savings goal set!');
}

function exportToJSON() {
    const dataStr = JSON.stringify(budgetData, null, 2);
    const dataBlob = new Blob([dataStr], { type: 'application/json' });
    const url = URL.createObjectURL(dataBlob);

    const link = document.createElement('a');
    link.href = url;
    link.download = `budget_${budgetData.user.month || 'export'}.json`;
    link.click();

    URL.revokeObjectURL(url);
    showToast('✓ Budget exported to JSON!');
}

function saveBudget() {
    saveToLocalStorage();

    // Also create a downloadable text file
    const summary = generateBudgetSummary();
    const blob = new Blob([summary], { type: 'text/plain' });
    const url = URL.createObjectURL(blob);

    const link = document.createElement('a');
    link.href = url;
    link.download = `budget_summary_${budgetData.user.month || 'export'}.txt`;
    link.click();

    URL.revokeObjectURL(url);
    showToast('✓ Budget saved and downloaded!');
}

function generateBudgetSummary() {
    const totalIncome = calculateTotalIncome();
    const totalExpenses = calculateTotalExpenses();
    const balance = calculateBalance();
    const savings = calculateSavings();
    const savingsPercentage = calculateSavingsPercentage();

    return `
========================================
    MONTHLY BUDGET TRACKER SUMMARY
========================================

User: ${budgetData.user.name}
Month: ${budgetData.user.month}

--- INCOME DETAILS ---
Salary:        ${formatCurrency(budgetData.income.salary)}
Freelance:     ${formatCurrency(budgetData.income.freelance)}
Investments:   ${formatCurrency(budgetData.income.investments)}
Other Income:  ${formatCurrency(budgetData.income.other)}
-----------------------------------------
Total Income:  ${formatCurrency(totalIncome)}

--- EXPENSE DETAILS ---
Rent/Mortgage:   ${formatCurrency(budgetData.expenses.rent)}
Groceries:       ${formatCurrency(budgetData.expenses.groceries)}
Utilities:       ${formatCurrency(budgetData.expenses.utilities)}
Transportation:  ${formatCurrency(budgetData.expenses.transportation)}
Entertainment:   ${formatCurrency(budgetData.expenses.entertainment)}
Healthcare:      ${formatCurrency(budgetData.expenses.healthcare)}
Education:       ${formatCurrency(budgetData.expenses.education)}
Shopping:        ${formatCurrency(budgetData.expenses.shopping)}
Other:           ${formatCurrency(budgetData.expenses.other)}
-----------------------------------------
Total Expenses:  ${formatCurrency(totalExpenses)}

--- BUDGET SUMMARY ---
Total Income:      ${formatCurrency(totalIncome)}
Total Expenses:    ${formatCurrency(totalExpenses)}
Balance:           ${formatCurrency(balance)}
Savings:           ${formatCurrency(savings)}
Savings Goal:      ${formatCurrency(budgetData.savingsGoal)}
Savings %:         ${savingsPercentage.toFixed(1)}%

${savings >= budgetData.savingsGoal && budgetData.savingsGoal > 0
            ? '✓ Congratulations! Savings goal achieved!'
            : '⚠ Keep working towards your savings goal!'}

========================================
Generated on: ${new Date().toLocaleString()}
========================================
    `.trim();
}

function resetAll() {
    if (!confirm('Are you sure you want to reset all data? This cannot be undone.')) {
        return;
    }

    budgetData = {
        user: { name: '', month: '' },
        income: { salary: 0, freelance: 0, investments: 0, other: 0 },
        expenses: {
            rent: 0, groceries: 0, utilities: 0, transportation: 0,
            entertainment: 0, healthcare: 0, education: 0, shopping: 0, other: 0
        },
        savingsGoal: 0
    };

    localStorage.removeItem('budgetData');
    populateFields();
    calculateTotals();
    showToast('✓ All data reset!');
}

// === Smooth Scrolling ===

function setupSmoothScrolling() {
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function (e) {
            e.preventDefault();
            const target = document.querySelector(this.getAttribute('href'));
            if (target) {
                target.scrollIntoView({
                    behavior: 'smooth',
                    block: 'start'
                });
            }
        });
    });
}

// === Active Navigation ===

function setupActiveNavigation() {
    const sections = document.querySelectorAll('section[id]');
    const navLinks = document.querySelectorAll('.nav-link');

    window.addEventListener('scroll', () => {
        let current = '';

        sections.forEach(section => {
            const sectionTop = section.offsetTop;
            const sectionHeight = section.clientHeight;
            if (pageYOffset >= sectionTop - 200) {
                current = section.getAttribute('id');
            }
        });

        navLinks.forEach(link => {
            link.classList.remove('active');
            if (link.getAttribute('href') === `#${current}`) {
                link.classList.add('active');
            }
        });
    });
}

// === Real-time Calculation ===

function setupRealtimeCalculation() {
    // Income inputs
    const incomeInputs = ['salary', 'freelance', 'investments', 'otherIncome'];
    incomeInputs.forEach(id => {
        document.getElementById(id).addEventListener('input', () => {
            budgetData.income[id === 'otherIncome' ? 'other' : id] =
                parseFloat(document.getElementById(id).value) || 0;
            calculateTotals();
        });
    });

    // Expense inputs
    const expenseInputs = [
        'rent', 'groceries', 'utilities', 'transportation',
        'entertainment', 'healthcare', 'education', 'shopping', 'otherExpenses'
    ];
    expenseInputs.forEach(id => {
        document.getElementById(id).addEventListener('input', () => {
            budgetData.expenses[id === 'otherExpenses' ? 'other' : id] =
                parseFloat(document.getElementById(id).value) || 0;
            calculateTotals();
        });
    });

    // Savings goal
    document.getElementById('savingsGoal').addEventListener('input', () => {
        budgetData.savingsGoal = parseFloat(document.getElementById('savingsGoal').value) || 0;
        updateSavingsProgress();
    });
}

// === Event Listeners ===

function setupEventListeners() {
    // User details
    document.getElementById('saveUserBtn').addEventListener('click', saveUserDetails);

    // Income
    document.getElementById('saveIncomeBtn').addEventListener('click', saveIncome);

    // Expenses
    document.getElementById('saveExpenseBtn').addEventListener('click', saveExpenses);

    // Savings goal
    document.getElementById('saveSavingsGoalBtn').addEventListener('click', saveSavingsGoal);

    // Actions
    document.getElementById('exportJSONBtn').addEventListener('click', exportToJSON);
    document.getElementById('saveBudgetBtn').addEventListener('click', saveBudget);
    document.getElementById('resetBtn').addEventListener('click', resetAll);

    // Hero buttons
    document.getElementById('getStartedBtn').addEventListener('click', () => {
        document.getElementById('dashboard').scrollIntoView({ behavior: 'smooth' });
    });

    document.getElementById('startTrackingBtn').addEventListener('click', () => {
        document.getElementById('dashboard').scrollIntoView({ behavior: 'smooth' });
    });

    document.getElementById('learnMoreBtn').addEventListener('click', () => {
        document.getElementById('features').scrollIntoView({ behavior: 'smooth' });
    });
}

// === Initialization ===

document.addEventListener('DOMContentLoaded', () => {
    console.log('🚀 Monthly Budget Tracker initialized!');

    // Initialize chart
    initializeChart();

    // Load saved data
    loadFromLocalStorage();

    // Setup event listeners
    setupEventListeners();

    // Setup smooth scrolling
    setupSmoothScrolling();

    // Setup active navigation
    setupActiveNavigation();

    // Setup real-time calculation
    setupRealtimeCalculation();

    // Initial calculation
    calculateTotals();

    console.log('✓ All systems ready!');
});

// === Auto-save on page unload ===

window.addEventListener('beforeunload', () => {
    saveToLocalStorage();
});
