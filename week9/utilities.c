
#include <stdio.h>
#include "utilities.h"
#include "config.h"

int readInt(void)
{
    int value;

    while (scanf("%d", &value) != 1)
    {
        int ch;

        printf("Invalid input. Enter a whole number: ");

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }

    return value;
}

float readFloat(void)
{
    float value;

    while (scanf("%f", &value) != 1)
    {
        int ch;

        printf("Invalid input. Enter a number: ");

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }

    return value;
}

float calculateVAT(float amount)
{
    return amount * VAT_RATE;
}

void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}
