#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: - 1 if function fails else 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
ssize_t openDescriptor, writeDescriptor;
int fileLength = 0;
if (text_content == NULL || filename == NULL)
{
return (-1);
}
while (text_content[fileLength] != NULL)
{
fileLength++;
}

openDescriptor = open(filename, O_WRONLY | O_APPEND);
writeDescriptor = write(openDescriptor, text_content, fileLength);
if (openDescriptor == -1 || writeDescriptor == -1)
return (-1);

close(0);
return (1);
}
