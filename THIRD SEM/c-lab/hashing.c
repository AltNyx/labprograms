#include<stdio.h>
#define MAX 100
int F[MAX], HT[MAX], L;
void linear_probe(int k, int key)
{
    L = k % MAX;
    if(HT[L] == 0)
        HT[L] = key;
    else
     linear_probe(k + 1, key);
}

void display()
{
    int i;
    printf("\nHash Table:");
    for(i = 0; i < MAX; i++)
    {
        printf("\nHT[%d]----->%d", i, HT[i]);
    }
}

int main()
{
    FILE *fp;
    int i = 0;
    char buff[1000];
    fp = fopen("lol.txt", "r");
    while(fscanf(fp, "%d", &F[i]) != EOF)
    {
        fscanf(fp, "%[^\n]s", buff);
        i++;
    }
    printf("\nThe number of records in the file are: %d", i);
    for(i = 0; i < MAX; i++)
    {
        L = F[i] % MAX;
        if(HT[L] == 0)
            HT[L] = F[i];
        else
            linear_probe(F[i] + 1, F[i]);
    }
    display();
    return 0;
}