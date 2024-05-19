#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"

#define MAX_LINES 10
#define MAX_LENGTH 256
FILE *file;
char *filename = "../text.txt";

char lines[MAX_LINES][MAX_LENGTH];
char *test[MAX_LINES];
char line[MAX_LENGTH];
int i = 0;


int main()
{
    // Initialize test pointers to point to the lines buffers
    for (int j = 0; j < MAX_LINES; j++) 
    {
        test[j] = lines[j];
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        return 1;
    }

    
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
        // printf("%d\n", i);
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';
        strcpy(test[i++], line);
        // insert string at first place
        // increment pointer
        // if no more string exit
    }

    fclose(file);
    for (char **p = test; p < test + i; p++) {
        printf("%s\n", *p);
    }
}


