#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it.
 * @filename: a pointer to the name of the file
 * @letters: the number of letters to read and print
 * Return: 0 if filename is null else return the number of
 *         letters it could read or print
*/


ssize_t read_textfile(const char *filename, size_t letters)
{
char *myBuffer;
ssize_t openDescriptor;
ssize_t readDescriptor;
ssize_t writeDescriptor;

myBuffer = malloc(sizeof(char) * letters);
if (filename == NULL || myBuffer == NULL)
{
return (0);
}

openDescriptor = open(filename, O_RDONLY);
if (openDescriptor == -1)
{
free(myBuffer);
return (0);
}
readDescriptor = read(openDescriptor, myBuffer, letters);
if (readDescriptor == -1)
{
free(myBuffer);
return (0);
}
writeDescriptor = write(STDOUT_FILENO, myBuffer, readDescriptor);
if (writeDescriptor == -1 || writeDescriptor != readDescriptor)
{
free(myBuffer);
return (0);
}
free(myBuffer);
close(openDescriptor);
return (writeDescriptor);
}
