#include "main.h"

/**
 * create_file - A function to create a file
 * @filename: name of the file pointer
 * @text_content: a pointer to null terminated string
 * Return: 1 else -1 if it fails
*/

int create_file(const char *filename, char *text_content)
{
ssize_t openDescriptor, writeDescriptor;
int fileLength = 0;
if (text_content == NULL || filename == NULL)
{
return (-1);
}
while (text_content[fileLength] != '\0')
{
fileLength++;
}

openDescriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
writeDescriptor = write(openDescriptor, text_content, fileLength);
if (openDescriptor == -1 || writeDescriptor == -1)
return (-1);

close(0);
return (1);
}
