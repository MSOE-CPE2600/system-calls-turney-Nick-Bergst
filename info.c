/********************************************** 
*  Filename: info.c 
*  Description: prints a handful of system data 
*  Author: Nicholas Bergst *  Date: 11/19/2024 
*  Compile with provided Makefile, run info in 
terminal 
***********************************************/ 

#include <stdio.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[])
{
    struct timespec Now;
    clock_gettime(CLOCK_REALTIME, &Now);
    printf("Current time: %d%ldns\n", (int)Now.tv_sec, Now.tv_nsec);
    struct utsname Syst;
    uname(&Syst);
    printf("Current OS: %s, Rel. %s, Ver. %s\nCurrent Network Name: %s\nCurrent Hardware Type: %s\n", Syst.sysname, Syst.release, Syst.version, Syst.nodename, Syst.machine);
    char Host[65];
    gethostname(Host, 65);
    printf("Current Host Name: %s\n", Host);
    printf("Number of Availible CPUs: %d\n", get_nprocs());
    printf("Size of Page(s): %d\n", getpagesize());
    printf("Physical Memory (Total, Availible): (%ld Bytes, %ld Bytes)\n", sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE), sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE));
    return 0;
}