#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * make_buffer - allocate bytes
 * @file: name of the file pointer
 * @byte_size: size of the bytes to allocate
 * Return: A pointer to new buffer allocated
*/

char *make_buffer(char *file, int byte_size)
{
char *alloc;
alloc = malloc(sizeof(char) * byte_size);
if (alloc == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}

return (alloc);
}

/**
 * handle_file - Clean up and close file descriptors
 * @file_desc: File descriptor mostly integer
*/

void handle_file(int file_desc)
{
ssize_t status;
status = close(file_desc);
if (status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
exit(100);
}
}
