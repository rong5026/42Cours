#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

int	is_invalid_input(int *readsize, char **backup, int fd, char *buf);
int	join_buf_and_backup(char **backup, char buf[]);
int	copy_to_return(char **backup, int readsize, char **return_value);
int make_new_backup(char **new_backup, char **backup);
char *get_next_line(int fd);

size_t	ft_strlen(char *s, int only_null);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int	ft_strchr(const char *s, int c);

#endif