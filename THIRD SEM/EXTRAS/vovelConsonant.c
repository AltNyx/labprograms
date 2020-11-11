// Vovel or consonant
#include<stdio.h>
void checkCharacter(char c)
{
    if(c <= 90 && c >= 65)
        c += 32;  //concverting char to small if character is in caps
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("%c is a vovel", c);
    else
        printf("%c is a consonant", c);
}

int main()
{
    int c;
    printf("Enter a character:");
    scanf("%c", &c);
    checkCharacter(c);
    return 0;
}
