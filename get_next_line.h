/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:04:52 by woberon           #+#    #+#             */
/*   Updated: 2021/12/18 18:04:55 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 150

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*ft_check(const char *buff, int *i);
char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_read(int fd, char *buff, int *i);
int			check_next_line(char *line);

#endif
