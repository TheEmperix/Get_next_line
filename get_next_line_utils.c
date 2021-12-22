/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:05:02 by woberon           #+#    #+#             */
/*   Updated: 2021/12/18 18:05:04 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	k = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!k)
		return (NULL);
	while (s1[i])
		k[j++] = s1[i++];
	i = 0;
	while (s2[i])
		k[j++] = s2[i++];
	k[j] = '\0';
	free(s1);
	free(s2);
	return (k);
}

int	check_next_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_read(int fd, char *buff, int *i)
{
	int	c;

	c = read(fd, buff, BUFFER_SIZE);
	if (c <= 0)
		return (0);
	*i = 0;
	buff[c] = '\0';
	return (c);
}

char	*ft_check(const char *buff, int *i)
{
	int		j;
	char	*line2;

	j = *i;
	while (buff[j] != '\0' && buff[j] != '\n')
		j++;
	if (buff[j] == '\n')
		j++;
	line2 = (char *)malloc(j - *i + 1);
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
	{
		line2[j++] = '\n';
		(*i)++;
	}
	line2[j] = '\0';
	return (line2);
}
