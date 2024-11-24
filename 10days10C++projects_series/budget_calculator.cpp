#include <iostream>
#include <vector>
using namespace std;

class budget_calculator {
private:
    string date;
    int expense;
    string wexpense;

public:
    budget_calculator(string date, string wexpense, int expense);
    ~budget_calculator();
    static int totalexpense;

    void getdate() {
        cout << "Enter today's date (dd:mm:yy): ";
        cin >> date;
    }

    void displaydate() {
        cout << date << endl;
    }

    void getwexpense() {
        cout << "What expense? ";
        cin >> wexpense;
    }

    void displaywexpense() {
        cout << wexpense << ": ";
    }

    void getexpense() {
        cout << "Enter the amount spent: ";
        cin >> expense;
        totalexpense += expense;
    }

    void displayexpense() {
        cout << expense << endl;
    }

    void display() {
        cout << "Date: " << date << " - Expense: " << wexpense << " : " << expense << endl;
    }
};

int budget_calculator::totalexpense = 0;

budget_calculator::budget_calculator(string date, string wexpense, int expense)
    : date(date), wexpense(wexpense), expense(expense) {
    totalexpense += expense;
}

budget_calculator::~budget_calculator() {
}

int main() {
    cout << "***************WELCOME**************" << endl;
    cout << "****DAILY EXPENSE CALCULATOR****" << endl;

    vector<budget_calculator> expenses;
    int choice;

    do {
        cout << "Please enter the numerical value associated with the entry you wish to access (1 to add expense, 0 to quit): ";
        cin >> choice;

        if (choice == 1) {
            budget_calculator obj("", "", 0);
            obj.getdate();
            obj.getwexpense();
            obj.getexpense();
            expenses.push_back(obj);
        } else if (choice != 0) {
            cout << "Invalid choice. Please enter 1 to add expense or 0 to quit." << endl;
        }
    } while (choice != 0);

    cout << "***************EXPENSE SUMMARY**************" << endl;
    for (size_t i = 0; i < expenses.size(); ++i) { 
        expenses[i].display(); 
    } 
    cout << "Total Expense: " << budget_calculator::totalexpense << endl;

    return 0;
}



