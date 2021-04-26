#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("PID of prog2 is %d\n", getpid());
    printf("The number of arguments recieved are: %d\n", argc);
    printf("The arguments are: \n");
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}