#include <stdio.h>
#include <stdlib.h>
#define BASIC_PAY 15.0      // BASIC_PAY payrate
#define OVERTIME_PAY 22.5   // OVERTIME_PAY payrate in excess of 40 hours
#define RATE1 0.15      // taxrate of the first $300
#define RATE2 0.25       // taxrate of the next $150
#define RATE3 0.30      // taxrate of the rest



void printSalaryInfo (int workHours);


int main()
{
    short int workHours = 0.0;

    while(1)
    {
        printf ("Enter hours worked this week (-1 to exit): ");
        scanf ("%hd", &workHours);
        if (workHours == -1)
        {
            printf("\nSee you Aagain\n\n");
            break;
        }

        printSalaryInfo(workHours);

    }

    return 0;
}

void printSalaryInfo (int workHours)
{
    float grossPay, taxes, netPay;

    if(workHours <=40)
        grossPay = workHours * BASIC_PAY;
    else
        grossPay = (40 * BASIC_PAY) + ((workHours - 40) * OVERTIME_PAY);


    if (grossPay <= 300.0)
    {
        taxes = grossPay * RATE1;
        netPay = grossPay - taxes;
    }
    else if (grossPay > 300 && grossPay <= 450)
    {
        taxes = (300 * RATE1) + (150 * RATE2);
        netPay = grossPay - taxes;
    }
    else
    {
        taxes = (300 * RATE1) + (150 * RATE2) + ((grossPay - 450) * RATE3);
        netPay = grossPay - taxes;
    }

    printf("\n--------- Salary Information ---------------\n\n");
    printf("GROSS PAY: %.2f\nTAXES: %10.2f\nNET PAY: %8.2f\n", grossPay, taxes, netPay);
    printf("\n---------------------------------------------\n\n");
}

