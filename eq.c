#include <stdio.h>
#include <stdlib.h>

double calculate(double* resistors, int count)
{
    double sum = 0;

    for(int i = 0; i < count; i++)
    {
        sum += 1 / resistors[i];
    }

    return (1 / sum);
}

int main(void)
{
    int resistorCount;
    double totalR;
    printf("Enter the number of parallel resistors: ");
    scanf("%d", &resistorCount);
    printf("\n");

    double* resistors = (double *)malloc(resistorCount * sizeof(double));

    for(int i = 0; i < resistorCount; i++)
    {
        printf("Enter resistance #%d (Ohms): ", i + 1);
        scanf("%lf", &resistors[i]);
    }

    totalR = calculate(resistors, resistorCount);
    
    if(totalR < 1000)
    {
        printf("\nThe total resistance is approximately %.2lf Ohms", totalR);
    }
    else
    {
        printf("\nThe total resistance is approximately %.2lf kOhms", totalR / 1000);
    }

    free(resistors);

    resistors = NULL;

    return 0;
}