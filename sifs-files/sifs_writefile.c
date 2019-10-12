#include <stdio.h>
#include <stdlib.h>
#include "sifs.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *find__name(const char *pathname)
{
    char *directory_name;
    if ((directory_name = strrchr(pathname, '/')) != NULL)
    {
        directory_name++; // move one char past '/'
    }
    else
    {
        directory_name = malloc(32);
        strcpy(directory_name, pathname);
    }
    return directory_name;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("\nIncorrect number of arguments\n");
        return 1;
    }

    
    FILE *fp = fopen(argv[3], "r");
    struct stat buf;
    stat(argv[3], &buf);
    int size = buf.st_size;
    char buffer[size]; //change - use stat to determine size 
    fread(buffer, size, 1, fp);
    SIFS_writefile(argv[1], argv[2], buffer, size);

    return 0;
}