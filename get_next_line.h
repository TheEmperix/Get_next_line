#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 150

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_read(int fd, char *buff, int *i);
int			check_next_line(char *line);
static char	*check(const char *buff, int *i);
#endif