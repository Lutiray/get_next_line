#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifdef __cplusplus
extern "C" {
# endif

char    *get_next_line(int fd);

size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
size_t  ft_strlcpy(char *dst, const char *src, size_t dst_len);
void    *ft_memcpy(void *dest, const void *src, size_t len);
char    *ft_strdup(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *read_loop(int fd, char *stash, char *buffer);

# ifdef __cplusplus
}
# endif
#endif