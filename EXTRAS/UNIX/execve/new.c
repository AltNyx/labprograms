#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv, char **envn)
{
    for (int i = 0; envn[i] != NULL; i++)
    {
        printf("%s\n", envn[i]);
    }
    printf("PID of new is %d\n", getpid());
}