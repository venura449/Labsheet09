#include <stdio.h>
#include <stdlib.h>

// Function to update account balance based on transaction
void updateBalance(char transactionType, float transactionAmount, float *balance) {
    if (transactionType == 'D') {
        *balance += transactionAmount;
    } else if (transactionType == 'W') {
        *balance -= transactionAmount;
    }
}

int main() {
    // Step (ii): Input account details and write to account.txt
    FILE *accountFile = fopen("account.txt", "w");
    if (accountFile == NULL) {
        printf("Error opening account.txt for writing.\n");
        return 1;
    }

    for (int i = 1; i <= 4; i++) {
        int accountNo;
        char nic[20];
        char customerName[50];
        float balance;

        printf("Enter Account Number for customer %d: ", i);
        scanf("%d", &accountNo);
        printf("Enter NIC No. for customer %d: ", i);
        scanf("%s", nic);
        printf("Enter Customer Name for customer %d: ", i);
        scanf("%s", customerName);
        printf("Enter Account Balance for customer %d: ", i);
        scanf("%f", &balance);

        fprintf(accountFile, "%d %s %s %.2f\n", accountNo, nic, customerName, balance);
    }

    fclose(accountFile);

    // Step (iii): Input account number from the user
    int accountNumber;
    printf("Enter the Account Number to check balance: ");
    scanf("%d", &accountNumber);

    // Step (iv): Read transaction details from transaction.txt and perform them
    FILE *transactionFile = fopen("transaction.txt", "r");
    if (transactionFile == NULL) {
        printf("Error opening transaction.txt for reading.\n");
        return 1;
    }

    float accountBalance = 0;
    char transactionType;
    float transactionAmount;

    while (fscanf(transactionFile, " %c %f", &transactionType, &transactionAmount) == 2) {
        if (transactionType == 'D' || transactionType == 'W') {
            if (accountNumber == accountBalance) {
                updateBalance(transactionType, transactionAmount, &accountBalance);
            }
        }
    }

    fclose(transactionFile);

    // Step (v): Display updated balance
    printf("Updated balance for Account Number %d: %.2f\n", accountNumber, accountBalance);

    return 0;
}
