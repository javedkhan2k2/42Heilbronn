#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int read_line(char *buffer, char *line, int *index, ssize_t bytesRead)
{
    int lineIndex = 0;    // Index of the current line
    while(*index < bytesRead && buffer[*index] != '\n')
    {
        line[lineIndex] = buffer[*index];
        lineIndex++;
        *index = *index + 1;

    }
    *index = *index + 1;
    line[lineIndex] = '\0';   // Null-terminate the line
    return (1);
}

int read_dict(int *fd)
{
    ssize_t bytesRead;    // Number of bytes read
    char buffer[1024];    // Buffer to store read data
    char line[1024];      // Buffer to store one line

    *fd = open("numbers.dict", O_RDONLY);
    if (*fd == -1)
    {
        perror("Error opening the file");
        return 1;
    }
    bytesRead = read(*fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("Error reading the file");
        close(*fd);
        return 1;
    }
    int num_of_lines = 0;
    int i=0;
    while(read_line(buffer, line, &i, bytesRead))
    {
        printf("%s\n", line);
        if(i >= bytesRead)
            break;
    }

    // while(i < bytesRead && read_line(buffer, line, &i))
    // {
    //     printf("%s\n", line);
    // }
    return (1);
}

int main(void)
{
    struct words
    {
        int digit;
        char word[20];
        int word_len;
        struct words *next;
    };

    int fd;    // File descriptor
    int res = read_dict(&fd);

    //write(STDOUT_FILENO, buffer, bytesRead);
    //printf("%s", buffer);
    close(fd);
    return (0);
}
