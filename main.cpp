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
            
            cout << "Initial balance is: $" << accountBalance << endl;
            cout << "\n\nPress enter to continue" << endl;
            cin.get(); // Wait for user input before returning
            system("cls"); // Clear the console screen
            
            
        }
        double getBalance() {// Function to check account balance
            return accountBalance; // Return the current account balance
        }
        bool withdraw(double amount) {
            // Function to withdraw from the account
            if (amount > accountBalance) { // Check for insufficient funds or invalid amount
                cout << "Debit amount exceeded account balance." << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls");
                return false; // sets the account balance to the same value, indicating failure
            }
            else if (amount <= 0) {
                cout << "Invalid amount. Transaction declined." << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls");
                return false; // Return an error code
            }
            else {
                accountBalance -= amount; // Deduct the amount from the account balance
                cout << "Withdrew $" << amount << ". New balance: $" << accountBalance << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls");
                return true; // Indicate success
            }
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
            else {
                accountBalance += amount; // Add the amount to the account balance
                cout << "Deposited $" << amount << ". New balance: $" << accountBalance << endl;
                cout << "\n\nPress enter to continue" << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls"); // Clear the console screen
                return accountBalance; // Indicate success
            }
        }
        void displayMenu() {
            // Function to display the menu options
            cout << "===============================" << endl;
            cout << "Welcome to XYZ Bank ATM " << accountHolderName << endl;
            cout << "Please select an option:" << endl;
            cout << "1. Account Balance" << endl;
            cout << "2. Withdraw " << endl;
            cout << "3. Deposit" << endl;
            cout << "4. Exit" << endl;
            cout << "===============================" << endl;
        }
        
};






int main(){
    system("cls");
    class BankAccount account; // Create an instance of the BankAccount class
    account.accountHolderName = "David Russell"; // Set the account holder's name
    // account.accountNumber = "123";
    account.setBalance(); // Set initial balance
    int choice=0; // Variable to store the user's menu choice
    double creditAmount=0; // Variable to store the amount to credit
    double debitAmount=0; // Variable to store the amount to debit
    double balance=0; // Variable to store the account balance

    
    while (choice != 4) { // Loop until the user chooses to exit
        system ("cls");
        account.displayMenu(); // Display the menu options
        cin >> choice; // Get the user's choice
        system("cls"); // Clear the console screen
        
        switch (choice) { // Handle the user's choice
            case 1:
                balance = account.getBalance(); // Display the account balance
                cout << "Your account balance is: $" << balance << endl;
                cin.ignore(); // Clear the input buffer
                cin.get(); // Wait for user input before returning
                system("cls"); // Clear the console screen
                break;
            case 2:
                cout << "Enter amount to withdraw: "; // Prompt the user to enter the amount to withdraw
                cin >> debitAmount;
                system("cls"); // Clear the console screen
                account.withdraw(debitAmount); // Attempt to withdraw from the account
                system("cls"); // Clear the console screen
                break;
            case 3:
                cout << "Enter amount to deposit: ";
                cin >> creditAmount;
                system("cls"); // Clear the console screen
                account.deposit(creditAmount); // Attempt to deposit into the account
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


