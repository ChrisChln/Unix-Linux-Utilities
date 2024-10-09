# Unix/Linux Utilities: tucp and tuls

## Project Overview
This project implements two simple Unix/Linux utility programs: `tucp` and `tuls`.

- **tucp**: A simplified version of the `cp` command, which copies files and directories.
- **tuls**: A simplified version of the `ls` command, which lists the contents of directories.

Both utilities are written in C and make use of system calls and standard C library functions to interact with the file system.

## Features

### tucp (File Copy Utility)
- Copies one or more files to a target directory.
- Supports copying a file to another file or copying multiple files to a directory.
- Includes error handling for cases like non-existent files or directories.
- Directory copying is supported.

### tuls (Directory Listing Utility)
- Lists the files and directories in the current directory by default.
- Supports listing the contents of a specified directory.
- Handles errors, such as when a directory does not exist or cannot be opened.

### Prerequisites
Make sure you have the following installed on your system:
- GCC (GNU Compiler Collection)

### Compilation
Compile tucp:
- gcc -Wall -Werror -o tucp tucp.c file_utils.c

Compile tuls:
- gcc -Wall -Werror -o tuls tuls.c


- Other detail check:DebuggingGCC.txt


### Project-1-linux-utilities-ChrisChln/
- file_utils.c            # File utilities implementation
- file_utils.h            # Header file for file utilities
- tucp.c                  # tucp main source code
- tuls.c                  # tuls main source code
- README.md               # Project documentation (this file)
- DebuggingGCC.txt        # Detailed debugging guide 




