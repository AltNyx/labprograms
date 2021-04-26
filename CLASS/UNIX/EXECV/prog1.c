#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("PID of prog1 is %d\n", getpid());

    char *args[] = {
        "arg1",
        "arg2",
        "arg3",
        NULL};

    int status = execv("./prog2", args);
    perror("execv");
    printf("%d\n", status);
    printf("This will be printed only if there's an error!\n");
    return 0;
}