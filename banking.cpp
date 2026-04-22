#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Transaction {
    string type;
    double amount;
};

class Account {
public:
    string owner;
    double balance;
    vector<Transaction> history;

    Account(string name, double initial) : owner(name), balance(initial) {}

    void deposit(double amount) {
        balance += amount;
        history.push_back({"Deposit", amount});
        cout << "Rs." << amount << " deposited successfully!\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        history.push_back({"Withdrawal", amount});
        cout << "Rs." << amount << " withdrawn successfully!\n";
    }

    void transfer(Account &to, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance for transfer!\n";
            return;
        }
        balance -= amount;
        to.balance += amount;
        history.push_back({"Transfer to " + to.owner, amount});
        to.history.push_back({"Transfer from " + owner, amount});
        cout << "Rs." << amount << " transferred to " << to.owner << " successfully!\n";
    }

    void showDetails() {
        cout << "\n====== " << owner << "'s Account ======\n";
        cout << "Current Balance: Rs." << balance << "\n";
        cout << "Transaction History:\n";
        if (history.empty()) {
            cout << "  No transactions yet.\n";
        } else {
            for (auto &t : history)
                cout << "  " << t.type << ": Rs." << t.amount << "\n";
        }
    }
};

int main() {
    Account acc1("Rahul", 10000);
    Account acc2("Priya", 5000);

    int choice;
    do {
        cout << "\n====== Banking System ======\n";
        cout << "1. Deposit\n2. Withdraw\n3. Transfer\n";
        cout << "4. View Rahul's Account\n5. View Priya's Account\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                cout << "Enter deposit amount for Rahul: ";
                cin >> amount;
                acc1.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount for Rahul: ";
                cin >> amount;
                acc1.withdraw(amount);
                break;
            case 3:
                cout << "Enter transfer amount from Rahul to Priya: ";
                cin >> amount;
                acc1.transfer(acc2, amount);
                break;
            case 4:
                acc1.showDetails();
                break;
            case 5:
                acc2.showDetails();
                break;
            case 0:
                cout << "Thank you for using our Banking System!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}