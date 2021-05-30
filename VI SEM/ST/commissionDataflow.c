#include <stdio.h>

float min(float num1, float num2)
{
    return num1 < num2 ? num1 : num2;
}

float max(float num1, float num2)
{
    return num1 > num2 ? num1 : num2;
}

float calculateCommission(float sales)
{
    float comm = 0;
    comm += 0.1 * min(1000, sales);
    comm += 0.15 * min(800, max(0, sales - 1000));
    comm += 0.20 * max(0, sales - 1800);
    return comm;
}

int main()
{
    int locks, stocks, barrels;

    float lockPrice = 45.0;
    float stockPrice = 30.0;
    float barrelPrice = 25.0;

    int locksSold = 0;
    int stocksSold = 0;
    int barrelsSold = 0;

    int tlocks = 0;
    int tstocks = 0;
    int tbarrels = 0;

    while (1)
    {
        printf("Enter the number of locks (Type -1 to exit): ");
        scanf("%d", &locks);
        if (locks == -1)
            break;

        printf("enter the number of stocks and number of barrels: ");
        scanf("%d%d", &stocks, &barrels);
        tlocks += locks;
        tstocks += stocks;
        tbarrels += barrels;
    }

    printf("Total locks: %d\n", tlocks);
    printf("Total stocks: %d\n", tstocks);
    printf("Total barrels: %d\n", tbarrels);

    float lockSales = lockPrice * tlocks;
    float stockSales = stockPrice * tstocks;
    float barrelSales = barrelPrice * tbarrels;
    float totalSales = lockSales + stockSales + barrelSales;

    printf("Total sale: %f\n", totalSales);
    printf("Total commission: %f\n", calculateCommission(totalSales));
    return 0;
}