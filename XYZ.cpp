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
    private:
        double accountBalance = 0; // Private member variable to store the account balance


    public:
        string accountHolderName; // Public member variable to store the account holder's name
        string accountNumber; // Public member variable to store the account number

        
        void setBalance() 
        {
            
            // Function to set the account balance
            cout << "Enter initial account balance: ";
            cin >> accountBalance;
            system("cls"); // Clear the console screen
            if (accountBalance < 1000) {
                accountBalance = 0; // Set balance to 0 if it's less than 1000
                cout << "The initial balance was invalid." << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls"); // Clear the console screen
            }
            
            cout << "Initial balance set to: $" << accountBalance << endl;
            cout << "\n\nPress enter to continue" << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before returning
            system("cls"); // Clear the console screen
            
            
            cout << "Your account balance is: $" << accountBalance << endl;
            cout << "\n\nPress enter to continue" << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before returning
            system("cls"); // Clear the console screen
        }
        double getBalance() {
            // Function to check account balance
            cout << "Your current account balance is: $" << accountBalance << endl;
            cout << "\n\nPress enter to continue" << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before returning
            system("cls"); // Clear the console screen
            return 0;
        }
        bool withdraw(double amount) {
            // Function to debit the account
            if (amount > accountBalance || amount <= 0) { // Check for insufficient funds or invalid amount
                cout << "Insufficient funds. Transaction declined." << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls");
                return false; // sets the account balance to the same value, indicating failure
            }
            accountBalance -= amount; // Deduct the amount from the account balance
            cout << "Debited $" << amount << ". New balance: $" << accountBalance << endl;
            cout << "\n\nPress enter to continue" << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before returning
            system("cls");
            return true; // Indicate success
        }
        double deposit(double amount) {// Function to credit the account
            if (amount <= 0) {
                cout << "Invalid amount. Transaction declined." << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls");
                return -1; // Return an error code
            }
            accountBalance += amount; // Add the amount to the account balance
            cout << "Credited $" << amount << ". New balance: $" << accountBalance << endl;
            cout << "\n\nPress enter to continue" << endl;
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for user input before returning
            system("cls"); // Clear the console screen
            return accountBalance; // Indicate success
        }
        void displayMenu() {
            // Function to display the menu options
            cout << "===============================" << endl;
            cout << "Welcome to XYZ Bank ATM " << accountHolderName << endl;
            cout << "Please select an option:" << endl;
            cout << "1. Check Account Balance" << endl;
            cout << "2. Debit Account" << endl;
            cout << "3. Credit Account" << endl;
            cout << "4. Exit" << endl;
            cout << "===============================" << endl;
        }
        
};






int main(){
    system("cls");
    class BankAccount account;
    account.accountHolderName = "David Russell";
    // account.accountNumber = "123";
    account.setBalance(); // Set initial balance
    int choice=0;
    double creditAmount=0;
    double debitAmount=0;

    
    while (choice != 4) { // Loop until the user chooses to exit
        system ("cls");
        account.displayMenu(); // Display the menu options
        cin >> choice; // Get the user's choice
        system("cls"); // Clear the console screen
        
        switch (choice) { // Handle the user's choice
            case 1:
                account.getBalance(); // Display the account balance
                break;
            case 2:
                cout << "Enter amount to debit: "; // Prompt the user to enter the amount to debit
                cin >> debitAmount;
                system("cls"); // Clear the console screen
                account.withdraw(debitAmount); // Attempt to debit the account
                system("cls"); // Clear the console screen
                break;
            case 3:
                cout << "Enter amount to credit: ";
                cin >> creditAmount;
                system("cls"); // Clear the console screen
                account.deposit(creditAmount); // Attempt to credit the account
                system("cls"); // Clear the console screen
                break;
            case 4:
                cout << "Thank you for using XYZ Bank ATM. Goodbye!" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before exiting    
                system("cls"); // Clear the console screen
                exit(0); // Exit the program
                
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
        }
    }
    
    

    return 0;
};


