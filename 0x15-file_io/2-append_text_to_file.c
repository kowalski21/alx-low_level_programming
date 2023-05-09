#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int file_desc = 0;
int write_handler = 0;
int text_length = 0;

if (filename == NULL)
{
return  (-1);
}

file_desc = open(filename, O_APPEND | O_WRONLY);
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
