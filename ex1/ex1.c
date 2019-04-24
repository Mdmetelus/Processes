// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;

    int callFork = fork();
    
    if (callFork < 0)
    {
        printf("Forked Failed \n");
        exit(1);
    }
    else if (callFork == 0)
    {
        printf("This is the Child (pid: %d) \n", (int)getpid());
        x++;
        printf("Child - x is now: %d\n", x);
    
    }
    else
    {
        printf("This is the Parent (pid: %d) of child %d\n", (int)getpid(), callFork);
        x--;
        printf("Parent - x is now: %d\n", x);
    }

    return 0;
}
