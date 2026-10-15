
#include <stdio.h>
#include "budget.h"
#include "utilities.h"

#define DEPARTMENT_COUNT 10

static float budgets[DEPARTMENT_COUNT];
static int budgetCount = 0;

void captureBudget(void)
{
    int i;

    budgetCount = DEPARTMENT_COUNT;

    for (i = 0; i < budgetCount; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        budgets[i] = readFloat();
    }

    printf("Department budgets captured successfully.\n");
}

float getTotalBudget(void)
{
    float total = 0.0f;
    int i;

    for (i = 0; i < budgetCount; i++)
        total += budgets[i];

    return total;
}

float getAverageBudget(void)
{
    if (budgetCount == 0)
        return 0.0f;

    return getTotalBudget() / budgetCount;
}

void displayBudget(void)
{
    int i;

    if (budgetCount == 0)
    {
        printf("No department budgets available.\n");
        return;
    }

    printf("\n--- Department Budget Report ---\n");

    for (i = 0; i < budgetCount; i++)
        printf("Department %d: %.2f\n", i + 1, budgets[i]);

    printf("Total budget: %.2f\n", getTotalBudget());
    printf("Average budget: %.2f\n", getAverageBudget());
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}
