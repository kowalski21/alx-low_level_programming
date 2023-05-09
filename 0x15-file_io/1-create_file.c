#include "main.h"
/**
 * create_file - creates a file
 * @filename:  filename pointer
 * @text_content: string to write
 * Return: If the function fails - -1.
 *         Otherwise - 1.
*/

int create_file(const char *filename, char *text_content)
{
int file_desc = 0;
int write_handler = 0;
int text_length = 0;

if (filename == NULL)
{
return  (-1);
}

file_desc = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
if (file_desc == -1)
{
return (-1);
}
while (text_content[text_length] != '\0')
{
text_length++;
}

write_handler = write(file_desc, text_content, text_length);
if (write_handler == -1)
{
return (-1);
}
close(file_desc);
return (1);

}
