/* C Program to Create bank account system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void displayAccount();
Account* findAccount(int accNo, FILE *fp);

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK ACCOUNT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Create a new account
void createAccount() {
    FILE *fp = fopen("accounts.dat", "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Account acc;
    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter account holder name: ");
    getchar(); // clear newline
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // remove newline
    printf("Enter initial deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

// Deposit money into an account
void depositMoney() {
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid deposit amount.\n");
                fclose(fp);
                return;
            }
            acc.balance += amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Deposit successful! New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
    fclose(fp);
}

// Withdraw money from an account
void withdrawMoney() {
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid withdrawal amount.\n");
                fclose(fp);
                return;
            }
            if (amount > acc.balance) {
                printf("Insufficient balance.\n");
                fclose(fp);
                return;
            }
            acc.balance -= amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Withdrawal successful! New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
    fclose(fp);
}

// Display account details
void displayAccount() {
    FILE *fp = fopen("accounts.dat", "rb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int accNo;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
    fclose(fp);
}
