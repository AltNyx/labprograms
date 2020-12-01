#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("PID of program is %d\n", getpid());

    char *args[] = {"arg1", "arg2", "arg3", NULL};

    int val = execvp("hello", args);
    perror("exec");
    printf("%d\n", val);
    printf("I will be printed only if there was an error!\n");
    return 0;
}