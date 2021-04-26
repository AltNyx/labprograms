#include<stdio.h>
int main()
{
    FILE * fptr;
    char filename[20], text;
    printf("Enter the file name:");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    while((text = fgetc(fptr)) != EOF)
        printf("%c", text);
    fclose(fptr);
    return 0;
}