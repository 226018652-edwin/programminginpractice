#include <stdio.h>

int main() {
  //DECLARE VARIABLES
    double revenue;
    double expenses;
    double balance;

    //WELCOME MESSAGE
    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    //USER PROMT REVENUE
    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    //USER PROMT EXPENSES
    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    //BALANCE CALCULATION
    balance = revenue - expenses;

    //DISPLAY REVENUE,EXPENCE AND BALANCE
    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance: %.2f\n", balance);

    return 0;
}