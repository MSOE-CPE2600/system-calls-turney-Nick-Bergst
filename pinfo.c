/********************************************** 
*  Filename: pinfo.c 
*  Description: prints a handful of process data 
*  Author: Nicholas Bergst *  Date: 11/19/2024 
*  Compile with provided Makefile, run pinfo in 
terminal with a process id as a command line 
argument
***********************************************/ 

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t myPid;
    if (argc > 1) {
        sscanf(argv[1], "%d", &myPid);
    } else {
        myPid = getpid();
        printf("Process ID: %d\n", myPid);
    }
    switch(sched_getscheduler(myPid)) {
        case SCHED_OTHER:
            printf("Scheduler: SCHED_OTHER");
            break;
        case SCHED_BATCH:
            printf("Scheduler: SCHED_BATCH");
            break;
        case SCHED_FIFO:
            printf("Scheduler: SCHED_FIFO");
            break;
        case SCHED_RR:
            printf("Scheduler: SCHED_RR");
            break;
        default:
            printf("ERROR");
            exit(0);
    }
    printf("\n");
    printf("Priority: %d\n", getpriority(PRIO_PROCESS, myPid));
    return 0;
}