/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:04:46 by woberon           #+#    #+#             */
/*   Updated: 2021/12/18 18:25:31 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_free(char *line1, char *line2)
{
	free(line1);
	return (*line2);
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
	line1 = ft_check(buff, &i);
	if (!line1)
		return (NULL);
	while (check_next_line(line1))
	{
		if (!ft_read(fd, buff, &i))
			return (line1);
		line2 = ft_check(buff, &i);
		if (!line2)
			ft_free(line1, line2);
		line1 = ft_strjoin(line1, line2);
	}
	return (line1);
}
