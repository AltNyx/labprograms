#include <stdio.h>

int main()
{
    float percentage;
    char grade;

    printf("Enter the percentage of the student: ");
    scanf("%f", &percentage);

    if (percentage > 90) grade = 'A';
    else if (percentage > 80) grade = 'B';
    else if (percentage > 70) grade = 'C';
    else if (percentage > 60) grade = 'D';
    else grade = 'E';

    switch (grade)
    {
    case 'A': printf("Excellent"); break;
    case 'B': printf("Very Good"); break;
    case 'C': printf("Good"); break;
    case 'D': printf("Above Average"); break;
    case 'E': printf("Satisfactory"); break;
    default: break;
    }

    printf("\nPercentage: %.2f and Grade: %c\n", percentage, grade);
    return 0;
}