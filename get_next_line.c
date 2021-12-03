#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	check_next_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*check(const char *buff, int *i)
{
	int		j;
	char	*line2;

	j = *i;
	while (buff[j] != '\0' && buff[j] != '\n')
		j++;
	if (buff[j] == '\n')
		j++;
	line2 = (char *)malloc(j - *i + 2);
	if (!line2)
		return (NULL);
	j = 0;
	while (buff[*i] != '\0' && buff[*i] != '\n')
	{
		line2[j] = buff[*i];
		j++;
		(*i)++;
	}
	if (buff[*i] == '\n')
		line2[j] = buff[(*i)++];
	return (line2);
}

int	ft_read(int fd, char *buff, int *i)
{
	int	c;

	c = read(fd, buff, BUFFER_SIZE);
	if (c <= 0)
		return (0);
	buff[c] = '\0';
	*i = 0;
	return (c);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	static int	i;
	char		*line1;
	char		*line2;

	if (buff[i] == '\0')
	{
		if (!ft_read(fd, buff, &i))
			return (NULL);
	}
	line1 = check(buff, &i);
	if (!line1)
		return (NULL);
	while (!check_next_line(line1))
	{
		if (!ft_read(fd, buff, &i))
			return (line1);
		line2 = check(buff, &i);
		if (!line2)
		{
			free(line1);
			return (line2);
		}
		line1 = ft_strjoin(line1, line2);
	}
	return (line1);
}

//int	main()
//{
//	int fd;
//
//	fd = open("text.txt", O_RDONLY);
//	printf("%s", get_next_line(fd));
//}
