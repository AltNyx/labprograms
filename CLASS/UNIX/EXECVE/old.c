#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
    for (int i = 0; env[i] != NULL; i++)
    {
        printf("%s\n", env[i]);
    }
    printf("PID of old is %d\n", getpid());

    char *envp[] = {"PATH=/bin",
                    NULL};

    char *args[] = {
        "arg1",
        "arg2",
        "arg3",
        NULL};

    int status = execve("./new", args, envp);
    perror("execv");
    printf("%d\n", status);
    printf("This will be printed only if there's an error!\n");
    return 0;
}