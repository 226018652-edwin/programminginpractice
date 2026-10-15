
#include <stdio.h>
#include "employees.h"
#include "utilities.h"
#include "config.h"

static float salaries[MAX_EMPLOYEES];
static int employeeIDs[MAX_EMPLOYEES];
static int employeeCount = 0;

void captureSalaries(void)
{
    int i;

    employeeCount = MAX_EMPLOYEES;

    for (i = 0; i < employeeCount; i++)
    {
        printf("Enter employee ID for employee %d: ", i + 1);
        employeeIDs[i] = readInt();

        printf("Enter salary for employee %d: ", i + 1);
        salaries[i] = readFloat();
    }

    printf("Employee records captured successfully.\n");
}

void displaySalaries(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("No employee records available.\n");
        return;
    }

    printf("\n--- Employee Salary Report ---\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("ID: %d | Salary: %.2f\n",
               employeeIDs[i], salaries[i]);
    }

    printf("Total salaries: %.2f\n",
           calculateAverageSalary() * employeeCount);
    printf("Average salary: %.2f\n", calculateAverageSalary());
    printf("Highest salary: %.2f\n", getHighestSalary());
    printf("Lowest salary: %.2f\n", getLowestSalary());
}

float calculateAverageSalary(void)
{
    float total = 0.0f;
    int i;

    if (employeeCount == 0)
        return 0.0f;

    for (i = 0; i < employeeCount; i++)
        total += salaries[i];

    return total / employeeCount;
}

float getHighestSalary(void)
{
    float highest;
    int i;

    if (employeeCount == 0)
        return 0.0f;

    highest = salaries[0];

    for (i = 1; i < employeeCount; i++)
    {
        if (salaries[i] > highest)
            highest = salaries[i];
    }

    return highest;
}

float getLowestSalary(void)
{
    float lowest;
    int i;

    if (employeeCount == 0)
        return 0.0f;

    lowest = salaries[0];

    for (i = 1; i < employeeCount; i++)
    {
        if (salaries[i] < lowest)
            lowest = salaries[i];
    }

    return lowest;
}

int searchEmployee(int id)
{
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
            return i;
    }

    return -1;
}
