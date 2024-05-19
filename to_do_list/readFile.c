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
int count = 0;


int main()
{
    read_strings();
    
    for (char **p = test; p < test + count; p++) {
        printf("%s\n", *p);
    }
}

int read_strings()
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
            strcpy(test[count++], line);
            // insert string at first place
            // increment pointer
            // if no more string exit
        }

        fclose(file);
        SIZE = sizeof(test) / sizeof(test[0]);
    }


