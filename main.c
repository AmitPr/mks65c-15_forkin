#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
    srand(time(NULL));
    printf("Parent PID: %d\n", getpid());
    int c, c1, status;
    c = fork();
    if (c)
    {
        //Still in parent code
        rand();
        c1 = fork();
        if (c1 == 0)
        {
            //Child 1
            int r = (rand() % 9) + 2;
            printf("Child 1 PID: %d %d\n", getpid(), r);
            sleep(r);
            printf("Child 1 Done.\n");
            return r;
        }
        wait(&status);
        printf("[Parent]: Child exited, Time: %d\nParent Exiting.\n", WEXITSTATUS(status));
    }
    else
    {
        //Child 0 code
        int r = (rand() % 9) + 2;
        printf("Child 0 PID: %d %d\n", getpid(), r);
        sleep(r);
        printf("Child 0 Done.\n");
        return r;
    }
}