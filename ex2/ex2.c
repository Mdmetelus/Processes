// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "w");
    int callFork = fork();


    char parent_str[] = "Parent.\n";
    char child_str[] = "Child.\n";

    if (callFork < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (callFork == 0) {
        fwrite(child_str, 1, sizeof(child_str), fp);
    } else {
        fwrite(parent_str, 1, sizeof(parent_str), fp);
    }

        return 0;
}
