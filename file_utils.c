#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void copy_file(const char *src, const char *dest) {
    int src_fd, dest_fd;
    ssize_t n_read;
    char buffer[BUFFER_SIZE];

    // Open Sourcefile
    src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    // Open/create target file
    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Failed to open destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    // Read the source file and write to the target file
    while ((n_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, n_read) != n_read) {
            perror("Failed to write to destination file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (n_read == -1) {
        perror("Failed to read from source file");
    }

    // close file
    close(src_fd);
    close(dest_fd);
}
