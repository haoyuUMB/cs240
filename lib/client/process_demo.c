//
// Created by haoyu on 11/22/2022.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    // child process go through this with execution results of parent
    printf("parent process id: %d\t", getpid());
//    getchar();
    int pid;
    if ((pid = fork()) > 0)// child process id gets assigned,
        printf("In parent process, and child pid is: %d\n", pid);
    else if (pid == 0) {
        printf("In child process\n");
        exit(11);
    }
    int status;

    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);
        printf("Exit status of the child was %d\n", exit_status);
    }

    return 0;
}