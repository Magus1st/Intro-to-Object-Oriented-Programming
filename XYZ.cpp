//XYZ bank atm interface
//Author: David Russell
/*
==================================
==================================
Menu Options: 
    checking the account balance, 
    debiting the account 
    crediting the account 
    exit program.
==================================
==================================
*/
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BankAccount {
    public:
        string accountHolderName;
        string accountNumber;
        double accountBalance;
};
double balanceInquiry(double accountBalance) {
    // Function to check account balance
    cout << "Your current account balance is: $" << accountBalance << endl;
    cin.ignore(); // Clear the input buffer
    cin.get(); // Wait for user input before returning
    return 0;
}
double debitAccount(double accountBalance, double amount) {
    // Function to debit the account
    if (amount > accountBalance) {
        cout << "Insufficient funds. Transaction declined." << endl;
        cin.ignore(); // Clear the input buffer
        cin.get(); // Wait for user input before returning
        return accountBalance; // sets the account balance to the same value, indicating failure
    }
    accountBalance -= amount;
    cout << "Debited $" << amount << ". New balance: $" << accountBalance << endl;
    cin.ignore(); // Clear the input buffer
    cin.get(); // Wait for user input before returning
    return accountBalance; // Indicate success
}
double creditAccount(double accountBalance, double amount) {
    // Function to credit the account
    accountBalance += amount;
    cout << "Credited $" << amount << ". New balance: $" << accountBalance << endl;
    cin.ignore(); // Clear the input buffer
    cin.get(); // Wait for user input before returning
    return accountBalance; // Indicate success
}
void displayMenu(BankAccount account) {
    // Function to display the menu options
    cout << "===============================" << endl;
    cout << "Welcome to XYZ Bank ATM " << account.accountHolderName << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Check Account Balance" << endl;
    cout << "2. Debit Account" << endl;
    cout << "3. Credit Account" << endl;
    cout << "4. Exit" << endl;
    cout << "===============================" << endl;
}


int main(){
    class BankAccount account;
    account.accountHolderName = "David Russell";
    account.accountNumber = "123";
    account.accountBalance = 1000.00;
    int choice=0;
    double creditAmount=0;
    double debitAmount=0;

    
    while (choice != 4) {
        system ("cls");
        displayMenu(account);
        cin >> choice;
        system("cls");
        
        switch (choice) {
        case 1:
            balanceInquiry(account.accountBalance);
            break;
        case 2:
            cout << "Enter amount to debit: ";
            cin >> debitAmount;
            system("cls");
            account.accountBalance = debitAccount(account.accountBalance, debitAmount);
            system("cls");
            break;
        case 3:
            cout << "Enter amount to credit: ";
            cin >> creditAmount;
            system("cls");
            account.accountBalance = creditAccount(account.accountBalance, creditAmount);
            system("cls");
            break;
        case 4:
            cout << "Thank you for using XYZ Bank ATM. Goodbye!" << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before exiting    
            system("cls");
            exit(0);
            
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before returning
    }
    }
    
    

    return 0;
};


