#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_buffer - creates a buffer and returns it
 * @buffer_size: size of the buffer
 * @file : Filename
 * Return : char  A pointer to the buffer created
*/
char *new_buffer(int buffer_size, char *file)
{
char *buffer = (char *) malloc(buffer_size);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
free(buffer);
exit(99);
}

}

/**
 * handle_close - Handler to close file descriptors
 * @f: File descriptor object
*/
void handle_close(ssize_t f)
{
ssize_t status;
status = close(f);
if (status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f);
exit(100);
}
}

/**
 * copy_func - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */

int copy_func(int argc, char *argv[])
{
ssize_t copy_from, copy_to, write_handler, read_handler;
char *buffer = new_buffer(1024, argv[2]);


if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
copy_from = open(argv[1], O_RDONLY);
if (copy_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
copy_to = open(argv[2], O_TRUNC | O_CREAT | O_WRONLY, 0664);
if (copy_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
exit(99);
}
while ((read_handler = read(copy_from, buffer, sizeof(buffer))) > 0)
{
write_handler = write(copy_to, buffer, 1024);
if (write_handler != read_handler)
{
dprintf(STDERR_FILENO, "Error writing to target file. %d\n", write_handler);
close(write_handler);
close(read_handler);
return (1);
}
}
free(buffer);
handle_close(write_handler);
handle_close(read_handler);
return (0);
}
