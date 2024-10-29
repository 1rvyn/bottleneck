#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int main() {
    clock_t start = clock();
    FILE* file = fopen("../input.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        fputs(line, stdout);
    }

    fclose(file);
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", duration);

    return 0;
}