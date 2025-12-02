#include <stdio.h>
#include <stdlib.h>

void loadBalance(int *balance) {
    FILE *fp = fopen("balance.txt", "r");

    if (fp == NULL) {
        *balance = 0;  
        return;
    }

    fscanf(fp, "%d", balance);
    fclose(fp);
}

void saveBalance(int balance) {
    FILE *fp = fopen("balance.txt", "w");
    fprintf(fp, "%d", balance);
    fclose(fp);
}

int main() {
    int pin, choice, amount;
    int balance;

    loadBalance(&balance);

    printf("Enter your ATM PIN: ");
    scanf("%d", &pin);

    if (pin != 1234) {
        printf("Wrong PIN! Access Denied.\n");
        return 0;
    }

    while (1) {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your Balance: %d\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                balance += amount;
                saveBalance(balance);
                printf("Deposited Successfully!\n");
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                if (amount > balance) {
                    printf("Insufficient Balance!\n");
                } else {
                    balance -= amount;
                    saveBalance(balance);
                    printf("Withdrawn Successfully!\n");
                }
                break;

            case 4:
                printf("Thank You for using ATM!\n");
                saveBalance(balance);
                exit(0);

            default:
                printf("Invalid Choice. Try again.\n");
        }
    }

    return 0;
}
