#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

FILE *file;
char *filename = "../text.txt";

int main()
{
    char *p = test;
    int place = 0;
    
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);

        // insert string at first place
        // increment pointer
        // if no more string exit
    }

    fclose(file);
}


