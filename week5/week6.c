
#include <stdio.h>
#include <string.h>

int main()
{
    // A. Employee salaries
    float salaries[50];
    float totalSalary = 0;
    float averageSalary;
    float highestSalary, lowestSalary;
    float searchSalary;
    int salaryFound = 0;

    // B. Department budgets
    float budgets[10];
    float totalBudget = 0;
    float averageBudget;
    float temp;

    // C. Vehicle registrations
    char registrations[20][20];
    char searchRegistration[20];
    int registrationFound = 0;

    int i, j;

    // A. CAPTURE EMPLOYEE SALARIES
    printf("===== EMPLOYEE SALARIES =====\n");

    for (i = 0; i < 50; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary += salaries[i];

        if (i == 0)
        {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    // DISPLAY EMPLOYEE SALARIES
    printf("\n--- All Employee Salaries ---\n");

    for (i = 0; i < 50; i++)
    {
        printf("Employee %d: %.2f\n",
               i + 1, salaries[i]);
    }

    printf("\nTotal Salaries: %.2f\n", totalSalary);
    printf("Average Salary: %.2f\n", averageSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);

    // SEARCH FOR A SALARY
    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);

    for (i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary %.2f found for employee %d.\n",
                   searchSalary, i + 1);
            salaryFound = 1;
        }
    }

    if (salaryFound == 0)
    {
        printf("Salary not found.\n");
    }

    // B. CAPTURE DEPARTMENT BUDGETS
    printf("\n===== DEPARTMENT BUDGETS =====\n");

    for (i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);

        totalBudget += budgets[i];
    }

    averageBudget = totalBudget / 10;

    // DISPLAY DEPARTMENT BUDGETS
    printf("\n--- Department Budgets ---\n");

    for (i = 0; i < 10; i++)
    {
        printf("Department %d: %.2f\n",
               i + 1, budgets[i]);
    }

    printf("\nTotal Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", averageBudget);

    // SORT BUDGETS FROM LOWEST TO HIGHEST
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted Lowest to Highest ---\n");

    for (i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    // C. CAPTURE VEHICLE REGISTRATIONS
    printf("\n===== VEHICLE REGISTRATIONS =====\n");

    for (i = 0; i < 20; i++)
    {
        printf("Enter registration number for vehicle %d: ",
               i + 1);
        scanf("%19s", registrations[i]);
    }

    // DISPLAY VEHICLE REGISTRATIONS
    printf("\n--- All Vehicle Registrations ---\n");

    for (i = 0; i < 20; i++)
    {
        printf("Vehicle %d: %s\n",
               i + 1, registrations[i]);
    }

    // SEARCH FOR A REGISTRATION NUMBER
    printf("\nEnter registration number to search for: ");
    scanf("%19s", searchRegistration);

    for (i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i],
                   searchRegistration) == 0)
        {
            printf("Registration %s found for vehicle %d.\n",
                   searchRegistration, i + 1);
            registrationFound = 1;
        }
    }

    if (registrationFound == 0)
    {
        printf("Registration number not found.\n");
    }

    printf("\nMunicipal Information Management System completed.\n");

    return 0;
}
