/********************************************** 
*  Filename: pmod.c 
*  Description: modifies its own priority, and 
runs a very specific timer
*  Author: Nicholas Bergst *  Date: 11/19/2024 
*  Compile with provided Makefile, run pmod in 
terminal 
***********************************************/ 

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char* argv[])
{
    //sched_setscheduler(getpid(), sched_getscheduler(getpid()), )
    struct timespec Sleeper;
    nice(-10);
    Sleeper.tv_sec = 1;
    Sleeper.tv_nsec = 837272638;
    struct timespec SleepLeft;
    nanosleep(&Sleeper, &SleepLeft);
    // 999999999 
    //1837272638
    printf("Goodbye\n");
    return 0;
}