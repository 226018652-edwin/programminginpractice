
#include <stdio.h>

// Function declarations
void displayWelcome();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu();
int searchEmployee(int id, int ids[], int size);

int main()
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int employeeID;
    int position;

    float amount;
    float vat;
    float basic, housing, transport, grossSalary;
    float revenue, expenses, balance;

    // Display welcome message
    displayWelcome();

    do
    {
        displayMenu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Calculate VAT
                printf("Enter amount: ");
                scanf("%f", &amount);

                vat = calculateVAT(amount);

                printf("VAT: %.2f\n", vat);
                break;

            case 2:
                // Calculate gross salary
                printf("Enter basic salary: ");
                scanf("%f", &basic);

                printf("Enter housing allowance: ");
                scanf("%f", &housing);

                printf("Enter transport allowance: ");
                scanf("%f", &transport);

                grossSalary = calculateSalary(
                    basic, housing, transport
                );

                printf("Gross salary: %.2f\n", grossSalary);
                break;

            case 3:
                // Calculate budget balance
                printf("Enter revenue: ");
                scanf("%f", &revenue);

                printf("Enter expenses: ");
                scanf("%f", &expenses);

                balance = calculateBudget(revenue, expenses);

                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                {
                    printf("Status: SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("Status: DEFICIT\n");
                }
                else
                {
                    printf("Status: BALANCED\n");
                }
                break;

            case 4:
                // Search for an employee
                printf("Enter employee ID: ");
                scanf("%d", &employeeID);

                position = searchEmployee(
                    employeeID,
                    employeeIDs,
                    5
                );

                if (position != -1)
                {
                    printf("Employee found at position %d.\n",
                           position);
                }
                else
                {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Task 1: Display welcome message
void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

// Task 2: Calculate VAT at 15 percent
float calculateVAT(float amount)
{
    return amount * 0.15;
}

// Task 3: Calculate gross salary
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

// Task 4: Calculate budget balance
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

// Task 5: Display reusable menu
void displayMenu()
{
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
}

// Task 6: Search for an employee ID
int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}
