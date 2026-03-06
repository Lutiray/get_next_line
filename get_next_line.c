#include "get_next_line.h"
// #include <fcntl.h>   // open
// #include <stdio.h>   // printf, perror
// #include <unistd.h>  // close
// #include <stdlib.h>  // free

char *read_to_stash(int fd, char *stash)
{
    char *buffer;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    if (stash == NULL)
    {
        stash = malloc(1 * sizeof(char));
        if (!stash)
        {
            free(buffer);
            return (NULL);
        }
        stash[0] = '\0';
    }
    stash = read_loop(fd, stash, buffer);
    free(buffer);
    return (stash);
}

char *extract_line(char *stash)
{
    char *pos;
    
    if (stash == NULL || stash[0] == '\0')
    {
        return (NULL);
    }
    pos = ft_strchr(stash, '\n');
    if (pos)
        return (ft_substr(stash, 0, pos - stash + 1));
    return (ft_substr(stash, 0, ft_strlen(stash)));
}

char *trim_stash(char *stash)
{
    char *pos;
    char *new_stash;
    int start;

    pos = ft_strchr(stash, '\n');
    if (pos == NULL)
    {
        free(stash);
        return (NULL);
    }
    start = pos - stash + 1;
    if (stash[start] == '\0')
    {
        free(stash);
        return (NULL);
    }
    new_stash = ft_substr(stash, start, ft_strlen(stash) - start);
    free(stash);
    return (new_stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_to_stash(fd, stash);
    if (stash == NULL)
        return (NULL);
    line = (extract_line(stash));
    if (line == NULL)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = trim_stash(stash);
    return(line);
}

// int main(int argc, char **argv)
// {
//     int     fd;
//     char    *line;
//     int     i;

//     if (argc == 2)
//     {
//         fd = open(argv[1], O_RDONLY);
//         if (fd < 0)
//         {
//             perror("open");
//             return (1);
//         }
//     }
//     else
//     {
//         fd = 0; // stdin
//         printf("Reading from stdin (Ctrl+D to stop):\n");
//     }

//     i = 1;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%02d: %s", i, line);
//         free(line);
//         i++;
//     }

//     if (argc == 2)
//         close(fd);

//     return (0);
// }