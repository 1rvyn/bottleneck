#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET_FILE_SIZE_10GB (1ULL << 33) // 10GB in bytes
#define TARGET_FILE_SIZE_1GB (1ULL << 30) // 1GB in bytes
#define TARGET_FILE_SIZE_1MB (1ULL << 20) // 1MB in bytes
#define NUMBERS_PER_LINE 10           // Number of integers per line

int main() {
    FILE *fp = fopen("../input.txt", "w");
    if (!fp) {
        perror("Failed to open file for writing");
        return EXIT_FAILURE;
    }

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    unsigned long long total_bytes_written = 0;
    char line_buffer[256]; // Buffer to hold each line of text

    while (total_bytes_written < TARGET_FILE_SIZE_1GB) {
        int offset = 0;
        for (int i = 0; i < NUMBERS_PER_LINE; i++) {
            int num = rand() % 10000 + 1; // Generate numbers between 1 and 10000
            int bytes = snprintf(line_buffer + offset, sizeof(line_buffer) - offset, "%d ", num);
            if (bytes < 0 || bytes >= (int)(sizeof(line_buffer) - offset)) {
                fprintf(stderr, "Line buffer overflow\n");
                fclose(fp);
                return EXIT_FAILURE;
            }
            offset += bytes;
        }
        // Replace the last space with a newline character
        line_buffer[offset - 1] = '\n';

        size_t bytes_written = fwrite(line_buffer, 1, offset, fp);
        if (bytes_written != (size_t)offset) {
            perror("Failed to write to file");
            fclose(fp);
            return EXIT_FAILURE;
        }

        total_bytes_written += bytes_written;
    }

    fclose(fp);
    printf("Successfully generated 'input.txt' of size approximately 1GB.\n");
    return EXIT_SUCCESS;
}