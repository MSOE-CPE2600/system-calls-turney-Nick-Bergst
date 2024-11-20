/********************************************** 
*  Filename: finfo.c 
*  Description: prints a handful of file data 
*  Author: Nicholas Bergst *  Date: 11/19/2024 
*  Compile with provided Makefile, run finfo in 
terminal with a file name as a command line
argument
***********************************************/ 

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc > 1) {
        struct stat cFil;
        stat(argv[0], &cFil);
        switch(cFil.st_mode & S_IFMT) {
            case S_IFSOCK:
                printf("File Type: Socket");
                break;
            case S_IFLNK:
                printf("File Type: Symbolic Link");
                break;
            case S_IFREG:
                printf("File Type: Regular File");
                break;
            case S_IFBLK:
                printf("File Type: Block Device");
                break;
            case S_IFDIR:
                printf("File Type: Directory");
                break;
            case S_IFCHR:
                printf("File Type: Character Device");
                break;
            case S_IFIFO:
                printf("File Type: FIFO");
                break;
            default:
                printf("ERROR");
                exit(0);
        }
        printf("\nFile Permissions: ");

        if (cFil.st_mode & S_ISUID) {
            printf("Set User ID, ");
        }
        if (cFil.st_mode & S_ISGID) {
            printf("Set Group ID, ");
        }
        if (cFil.st_mode & S_ISVTX) {
            printf("Can Only Be Deleted Or Renamed By Owner Via A Privleged Process, ");
        }

        if (cFil.st_mode & S_IRWXU) {
            printf("Owner May Read, Write and Execute, ");
        } else {
            if (cFil.st_mode & S_IRUSR) {
                printf("Owner May Read, ");
            }
            if (cFil.st_mode & S_IWUSR) {
                printf("Owner May Write, ");
            }
            if (cFil.st_mode & S_IXUSR) {
                printf("Owner May Execute, ");
            }
        } 
        
        if (cFil.st_mode & S_IRWXG) {
            printf("Group May Read, Write and Execute, ");
        } else {
            if (cFil.st_mode & S_IRGRP) {
                printf("Group May Read, ");
            }
            if (cFil.st_mode & S_IWGRP) {
                printf("Group May Write, ");
            }
            if (cFil.st_mode & S_IXGRP) {
                printf("Group May Execute, ");
            }
        } 
        
        if (cFil.st_mode & S_IRWXO) {
            printf("Others Not In Group May Read, Write and Execute, ");
        } else {
            if (cFil.st_mode & S_IROTH) {
                printf("Others Not In Group May Read, ");
            }
            if (cFil.st_mode & S_IWOTH) {
                printf("Others Not In Group May Write, ");
            }
            if (cFil.st_mode & S_IXOTH) {
                printf("Others Not In Group May Execute, ");
            }
        } 
        
        printf("this file.\nFile Size (Bytes): %ld\n", cFil.st_size);
        //printf("File Last Modified: %s\n", cFil);
    } else {
        printf("Please input file name at command line!\n");
    }
    return 0;
}