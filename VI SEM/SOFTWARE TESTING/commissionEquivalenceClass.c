#include <stdio.h>
#include <stdbool.h>

int main()
{
    int locks, stocks, barrels;
    bool check1, check2, check3;
    float commission;

    float lockPrice = 45.0;
    float stockPrice = 30.0;
    float barrelPrice = 25.0;

    int locksSold = 0;
    int stocksSold = 0;
    int barrelsSold = 0;

    int tlocks = 0;
    int tstocks = 0;
    int tbarrels = 0;

    int maxLocks = 70;
    int maxStocks = 80;
    int maxBarrels = 90;

    while (1)
    {
        printf("Enter the number of locks (Type -1 to exit): ");
        scanf("%d", &locks);
        if (locks == -1)
            break;

        printf("Enter the number of stocks and number of barrels: ");
        scanf("%d%d", &stocks, &barrels);
        tlocks += locks;
        tstocks += stocks;
        tbarrels += barrels;

        check1 = (locks <= 0 || tlocks > maxLocks);
        check2 = (stocks <= 0 || tstocks > maxStocks);
        check3 = (barrels <= 0 || tbarrels > maxBarrels);

        if (check1)
        {
            printf("Total locks not in range [1, %d]\n", maxLocks);
            tlocks -= locks;
        }

        if (check2)
        {
            printf("Total stocks not in range [1, %d]\n", maxStocks);
            tstocks -= stocks;
        }

        if (check3)
        {
            printf("Total barrels not in range [1, %d]\n", maxBarrels);
            tbarrels -= barrels;
        }

        printf("Locks sold: %d\n", tlocks);
        printf("Stocks sold: %d\n", tstocks);
        printf("Barrels sold: %d\n", tbarrels);
    }

    printf("Total locks sold: %d\n", tlocks);
    printf("Total stocks sold: %d\n", tstocks);
    printf("Total barrels sold: %d\n", tbarrels);

    float lockSales = lockPrice * tlocks;
    float stockSales = stockPrice * tstocks;
    float barrelSales = barrelPrice * tbarrels;
    float totalSales = lockSales + stockSales + barrelSales;

    if (totalSales > 1800.0)
    {
        commission = (0.10 * 1000.0) + (0.15 * 800) + (0.20 * (totalSales - 1800));
    }
    else if (totalSales > 1000.0)
    {
        commission = (0.10 * 1000) + (0.15 * (totalSales - 1000));
    }
    else
    {
        commission = 0.10 * totalSales;
    }

    printf("Total sales: %f\n", totalSales);
    printf("Total commission: %f\n", commission);
    return 0;
}