#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    size_t count;
    count = 0;

    if (!str)
        return(0);
    while (str[count] != '\0')
        count++;
    return (count);
}

char *ft_strchr(const char *str, int c)
{
    size_t i;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i])
    {
        if (str[i] == (char)c)
            return ((char*)(str + i));
        i++;
    }
    if ((char)c == '\0')
        return ((char*)(str + i));
    return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t len)
{
    size_t i;
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    i = 0;
    while (i < len)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

char *ft_strdup(const char *str)
{
    size_t len;
    char *result;

    if (!str)
        return (NULL);
    len = ft_strlen(str);
    result = (char*)malloc(len + 1);
    if (!result)
        return (NULL);
    ft_memcpy(result, str, len);
    result[len] = '\0';
    return (result);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t s1_len;
    size_t s2_len;

    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = malloc(s1_len + s2_len + 1);
    if (!str)
        return (NULL);
    ft_memcpy(str, s1, s1_len);
    ft_memcpy(str + s1_len, s2, s2_len);
    str[s1_len+s2_len] = '\0';
    return (str);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sb;
    size_t s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (s_len <= start)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    sb = malloc(len + 1);
    if (sb == NULL)
        return (NULL);
    ft_memcpy(sb, s + start, len);
    sb[len] = '\0';
    return (sb);
}

char *read_loop(int fd, char *stash, char *buffer)
{
    int bytes;
    char *new_stash;

    bytes = 1;
    while(!ft_strchr(stash, '\n') && bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(stash);
            return (NULL);
        }
        buffer[bytes] = '\0';
        new_stash = ft_strjoin(stash, buffer);
        if (!new_stash)
        {
            free(stash);
            return (NULL);
        }
        free(stash);
        stash = new_stash;
    }
    return (stash);
}
