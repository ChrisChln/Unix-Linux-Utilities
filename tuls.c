#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

void print_directory_contents(const char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Directory entries
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                printf("-> %s\n", entry->d_name);
            }
        } else {
            // File entries
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2) {
        // Print contents of the specified directory
        print_directory_contents(argv[1]);
    }

    // Print contents of the current directory
    print_directory_contents(".");

    return 0;
}
