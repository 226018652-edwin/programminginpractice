
#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void displayFullReport(void)
{
    printf("\n====================================\n");
    printf(" MUNICIPAL FINANCIAL SUMMARY REPORT\n");
    printf("====================================\n");

    printf("\nEMPLOYEE SUMMARY\n");
    printf("Average salary: %.2f\n",
           calculateAverageSalary());
    printf("Highest salary: %.2f\n",
           getHighestSalary());
    printf("Lowest salary: %.2f\n",
           getLowestSalary());

    printf("\nBUDGET SUMMARY\n");
    printf("Total department budget: %.2f\n",
           getTotalBudget());
    printf("Average department budget: %.2f\n",
           getAverageBudget());

    printf("====================================\n");
}
