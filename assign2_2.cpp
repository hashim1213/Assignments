#include <iostream>
#include <string>
#include <simplecpp>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    float balance;

public:
    BankAccount(int accountNumber, string accountHolder, float balance) {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposit: " << amount << " added to the balance." << endl;
        displayAccountDetails();
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal: " << amount << " deducted from the balance." << endl;
            displayAccountDetails();
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount account(123456, "John Doe", 1000.0);

        // Perform operations on the account
        int choice;
        float amount;

        do {
            cout << "Choose an operation:" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Display Account Details" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the amount to deposit: ";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 2:
                    cout << "Enter the amount to withdraw: ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 3:
                    account.displayAccountDetails();
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }

            cout << endl;
        } while (choice != 4);

        // Print the account information
        account.displayAccountDetails();

        return 0;
    }
