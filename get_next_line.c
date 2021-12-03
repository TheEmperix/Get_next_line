#include "get_next_line.h"
#include <stdio.h>

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
