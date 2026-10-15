
#include <stdio.h>

#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;
    int employeeID;
    int position;
    float amount;
    float revenue;
    float expenses;
    float balance;

    displayWelcome();

    do
    {
        printf("\n==================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("==================================\n");
        printf("1. Capture employee records\n");
        printf("2. Display employee salaries\n");
        printf("3. Search employee by ID\n");
        printf("4. Capture department budgets\n");
        printf("5. Display department budgets\n");
        printf("6. Calculate VAT\n");
        printf("7. Calculate budget balance\n");
        printf("8. Display full report\n");
        printf("9. Exit\n");
        printf("Enter choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                captureSalaries();
                break;

            case 2:
                displaySalaries();
                break;

            case 3:
                printf("Enter employee ID: ");
                employeeID = readInt();

                position = searchEmployee(employeeID);

                if (position >= 0)
                    printf("Employee found at position %d.\n",
                           position);
                else
                    printf("Employee not found.\n");
                break;

            case 4:
                captureBudget();
                break;

            case 5:
                displayBudget();
                break;

            case 6:
                printf("Enter amount: ");
                amount = readFloat();

                printf("VAT at 15%%: %.2f\n",
                       calculateVAT(amount));
                break;

            case 7:
                printf("Enter revenue: ");
                revenue = readFloat();

                printf("Enter expenses: ");
                expenses = readFloat();

                balance = calculateBudget(revenue, expenses);

                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                    printf("Status: SURPLUS\n");
                else if (balance < 0)
                    printf("Status: DEFICIT\n");
                else
                    printf("Status: BALANCED\n");
                break;

            case 8:
                displayFullReport();
                break;

            case 9:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}
