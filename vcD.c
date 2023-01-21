#include <stdio.h>
#include <stdlib.h>

double calculateVD(double *resistors, int count, int vFind)
{
    double v, sum = 0, vS;

    printf("Enter the voltage source (Volts): ");
    scanf("%lf", &vS);

    for (int i = 0; i < count; i++)
    {
        sum += resistors[i];
    }

    v = vS * (resistors[vFind] / sum);

    return v;
}

double calculateCD(double *resistors, int count, int cFind)
{
    double c, sum = 0, cS;

    printf("Enter the current source (Amps): ");
    scanf("%lf", &cS);

    for (int i = 0; i < count; i++)
    {
        sum += 1 / resistors[i];
    }

    c = cS * ((1 / resistors[cFind]) / sum);

    return c;
}

int main(void)
{
    int resistorCount, chooseR, choice;
    double result;

    printf("Enter 1 for voltage divider, 2 for current divider: ");
    scanf("%d", &choice);
    printf("Enter the number of resistors: ");
    scanf("%d", &resistorCount);
    printf("\n");

    double *resistors = (double *)malloc(resistorCount * sizeof(double));

    for (int i = 0; i < resistorCount; i++)
    {
        printf("Enter resistance #%d (Ohms): ", i + 1);
        scanf("%lf", &resistors[i]);
    }

    printf("\nEnter the specified resistor: ");
    scanf("%d", &chooseR);

    if (choice == 1)
    {
        result = calculateVD(resistors, resistorCount, chooseR - 1);

        printf("\nThe voltage drop over resistor #%d is %.2lf Volts", chooseR, result);
    }
    else
    {
        result = calculateCD(resistors, resistorCount, chooseR - 1);

        printf("\nThe current over resistor #%d is %.2lf Amps", chooseR, result);
    }

    free(resistors);

    resistors = NULL;

    return 0;
}