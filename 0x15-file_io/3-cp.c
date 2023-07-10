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



/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 */
int main(int argc, char *argv[])

{
int maxBytes = 1024;
ssize_t  toFile, fromFile, r, w;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = make_buffer(argv[2], maxBytes);
fromFile = open(argv[1], O_RDONLY);
r = read(fromFile, buffer, maxBytes);
toFile = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (fromFile == -1 || r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
w = write(toFile, buffer, r);
if (toFile == -1 || w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

r = read(fromFile, buffer, maxBytes);
toFile = open(argv[2], O_WRONLY | O_APPEND);

} while (r > 0);

free(buffer);
handle_file(fromFile);
handle_file(toFile);

return (0);
}

