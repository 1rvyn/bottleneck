#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    clock_t start = clock();
    int infile = open("../input.txt", O_RDONLY);
    if (infile < 0) {
        perror("Error opening input file");
        return 1;
    }

    int outfile = open("stream_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0) {
        perror("Error creating output file");
        close(infile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(infile, buffer, BUFFER_SIZE)) > 0) {
        if (write(outfile, buffer, bytesRead) != bytesRead) {
            perror("Error writing to output file");
            close(infile);
            close(outfile);
            return 1;
        }
    }

    if (bytesRead < 0) {
        perror("Error reading input file");
    }

    close(infile);
    close(outfile);
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Stream I/O Time taken: %f seconds\n", duration);
    return 0;
} 