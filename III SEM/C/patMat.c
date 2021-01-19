#include<stdio.h>
void read_string(char main_str[100], char pat[20], char rep[20])
{
    printf("Enter the main string:");
    gets(main_str);
    printf("Enter the pattern string:");
    gets(pat);
    printf("Enter the replace string:");
    gets(rep);
}
void pat_mat(char main_str[100], char pat[20], char rep[20])
{
    int i, j, k, z = 0;
    int patLen = 0, count = 0;
    char fin_str[100];
    for(i = 0; pat[i] != '\0'; i++)
        patLen++;
    for(i = 0; main_str[i] != '\0'; i++)
    {
        j = 0;
        while((main_str[i+j] == pat[j]) && (j < patLen))
            j++;
        if(pat[j] == '\0')
        {
            count++;
            for(k = 0; rep[k] != '\0'; k++, z++)
            {
                fin_str[z] = rep[k];
            }
            i = i + patLen - 1;
        }
        else
        {
            fin_str[z] = main_str[i];
            z++;
        }
    }
    if(count == 0)
        printf("No pattern found!\n");
    else
    {
        fin_str[z] = '\0';
        printf("The number of occurences of the pattern is:%d\n", count);
        printf("The final string is:\n%s\n", fin_str);
    }
}
int main()
{
    char main_str[100], pat[20], rep[20];
    read_string(main_str, pat, rep);
    pat_mat(main_str, pat, rep);
    return 0;
}































































