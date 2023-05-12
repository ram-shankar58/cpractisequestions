/*
ATM machine allows user to withdrawa money from their bank account. Each user has an account number, PIN and balance. 
Represent this in C using structures. A user wants to withdraw some amount from his account. Her's a scenario to be implemenented

Prompt the user to enter the account number and PIN

Use the entered account number to lock up the user's account details from a database or a file

Verify that the entered pin numnber matches the PIN stored in the account details

Prompt the user to enther the amount they want to withdraw
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a bank account
struct BankAccount {
    int accountNumber;
    int PIN;
    float balance;
};

// Function to prompt the user to enter their account details
void getAccountDetails(struct BankAccount *account) {
    printf("Enter your account number: ");
    scanf("%d", &(account->accountNumber));
    printf("Enter your PIN: ");
    scanf("%d", &(account->PIN));
    printf("Enter your balance: ");
    scanf("%f", &(account->balance));
}

// Function to verify the entered PIN
int verifyPIN(struct BankAccount *account) {
    int enteredPIN;
    printf("Enter your PIN again to verify: ");
    scanf("%d", &enteredPIN);
    if (account->PIN != enteredPIN) {
        printf("Incorrect PIN. Exiting...\n");
        return 0;
    }
    return 1;
}

// Function to process a withdrawal from the account
void processWithdrawal(struct BankAccount *account, float amount) {
    // Check if the user has enough balance to withdraw the requested amount
    if (amount <= account->balance) {
        // Withdraw the amount and update the account balance
        account->balance -= amount;
        printf("Withdrawal successful. Your new balance is %.2f\n", account->balance);
    } else {
        printf("Insufficient balance. Your current balance is %.2f\n", account->balance);
    }
}

// Function to find the account details based on the account number
struct BankAccount* findAccount(struct BankAccount *accounts, int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return &(accounts[i]);
        }
    }
    return NULL;
}

// Function to prompt the user to enter the account number and PIN
void getAccountCredentials(int *accountNumber, int *PIN) {
    printf("Enter your account number: ");
    scanf("%d", accountNumber);
    printf("Enter your PIN: ");
    scanf("%d", PIN);
}

// Function to prompt the user to enter the amount they want to withdraw
float getWithdrawalAmount() {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    return amount;
}

// Function to prompt the user to perform another transaction
int promptForAnotherTransaction() {
    int choice;
    printf("Do you want to perform another transaction? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
    return choice;
}

// Function pointer type for menu options
typedef void (*MenuOption)(struct BankAccount*, int, int*);

// Function to display the main menu and return the user's choice
int showMainMenu() {
    int choice;
    printf("\nMain Menu\n");
    printf("1. Withdraw\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to perform the withdraw operation
void withdraw(struct BankAccount *accounts, int numAccounts, int *currentIndex) {
    // Prompt the user to enter their account credentials
    int accountNumber, PIN;
    getAccountCredentials(&accountNumber, &PIN);

    // Find the account with the given account number
    struct BankAccount *account = findAccount(accounts, numAccounts, accountNumber);
    if (account == NULL) {
        printf("Account not found. Exiting...\n");
        return NULL
}

// Verify the entered PIN
if (!verifyPIN(account)) {
    return;
}

// Prompt the user to enter the withdrawal amount
float amount = getWithdrawalAmount();

// Process the withdrawal
processWithdrawal(account, amount);

// Prompt the user to perform another transaction
int anotherTransaction = promptForAnotherTransaction();
if (anotherTransaction) {
    // Move to the next account in the array
    (*currentIndex)++;
} else {
    // Exit the program
    *currentIndex = numAccounts;
}
// Array of function pointers for menu options
MenuOption menuOptions[] = {withdraw,NULL}; // Placeholder for exit option

// Main function to run the program
int main() {
int numAccounts;
printf("Enter the number of bank accounts: ");
scanf("%d", &numAccounts);

// Allocate memory for the bank account array
struct BankAccount *accounts = (struct BankAccount*)malloc(numAccounts * sizeof(struct BankAccount));

// Prompt the user to enter the details for each account
for (int i = 0; i < numAccounts; i++) {
    printf("\nEnter details for account %d:\n", i+1);
    getAccountDetails(&(accounts[i]));
}

// Add the exit option to the menu options
menuOptions[1] = NULL;

int currentIndex = 0;
while (currentIndex < numAccounts) {
    // Show the main menu and get the user's choice
    int choice = showMainMenu();

    // Invoke the selected menu option
    menuOptions[choice-1](accounts, numAccounts, &currentIndex);
}

// Free the memory allocated for the bank account array
free(accounts);

return 0;

