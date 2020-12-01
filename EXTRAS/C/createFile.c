#include<stdio.h>
int main()
{
    FILE * fptr;
    char text[50];
    int i;
    fptr = fopen("new.txt", "a");
    printf("Enter a string:");
    scanf("%s", text);
    for(i = 0; text[i] != '\0'; i++)
        fputc(text[i], fptr);
    fclose(fptr);
    return 0;
}