#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int main() {
    clock_t start = clock();
    FILE* infile = fopen("../input.txt", "r");
    if (infile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* outfile = fopen("buffered_output.txt", "w");
    if (outfile == NULL) {
        printf("Error creating output file\n");
        fclose(infile);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), infile) != NULL) {
        fputs(line, outfile);
    }

    fclose(infile);
    fclose(outfile);
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Buffered I/O Time taken: %f seconds\n", duration);
    return 0;
} 