#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <libgen.h>
#include "file_utils.h"

void handle_copy(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;

    // Check source file status
    if (stat(src, &src_stat) != 0) {
        perror("Failed to get source file status");
        exit(EXIT_FAILURE);
    }

    // Check if source is a directory
    if (S_ISDIR(src_stat.st_mode)) {
        copy_directory(src, dest); // If source is a directory, call copy_directory
    } else {
        // Check if destination is a directory
        if (stat(dest, &dest_stat) == 0 && S_ISDIR(dest_stat.st_mode)) {
            char new_dest[1024];
            snprintf(new_dest, sizeof(new_dest), "%s/%s", dest, basename((char *)src));
            copy_file(src, new_dest); // Copy file to the directory
        } else {
            copy_file(src, dest); // Copy file to the destination path (file or directory)
        }
    }

    printf("File copied successfully from %s to %s\n", src, dest);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source file(s)> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Destination path
    const char *dest = argv[argc - 1];

    // Check if destination is a directory
    // struct stat dest_stat;
    // if (stat(dest, &dest_stat) != 0 || !S_ISDIR(dest_stat.st_mode)) {
    //     fprintf(stderr, "Error: Destination must be a directory.\n");
    //     exit(EXIT_FAILURE);
    // }

    // Handle each source file
    for (int i = 1; i < argc - 1; i++) {
        handle_copy(argv[i], dest);
    }

    return 0;
}
