#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT
 * @filename: text file
 * @letters: number of letters
 * Return: w- actual number of bytes read and sent to STDOUT
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t read_file;
ssize_t write_file;
ssize_t file_status;
char *allowed_buffer;

file_status = open(filename, O_RDONLY);
if (file_status != -1)
{
allowed_buffer = malloc(sizeof(char) * letters);
read_file = read(file_status, allowed_buffer, letters);
write_file = write(STDOUT_FILENO, allowed_buffer, read_file);
free(allowed_buffer);
close(file_status);
return (write_file);
}

return (0);

}
