/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:13:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/20 17:43:00 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	upd_tail(char **tail, char *pointn)
{
	char	*tmp;

	if (!(tmp = ft_strdup_gnl(pointn)))
		return (-1);
	free(*tail);
	*tail = tmp;
	return (1);
}

int	what_tail(char **tail, char **line)
{
	char	*pointn;

	pointn = NULL;
	if (!*line)
		if (!(*line = ft_strdup_gnl("")))
			return (-1);
	if (*tail)
	{
		if ((pointn = ft_strchr_gnl(*tail, '\n')))
		{
			pointn[0] = '\0';
			if (!(*line = ft_strjoinfree(line, tail, 1)))
				return (-1);
			return (upd_tail(tail, pointn + 1));
		}
		else if (!(*line = ft_strjoinfree(line, tail, 3)))
		{
			if (line)
				free(line);
			if (tail)
				free(tail);
			return (-1);
		}
	}
	return (0);
}

int	ft_line(char **line, char **tail, int fd, char *buf)
{
	int		len;
	char	*pointn;

	if ((len = what_tail(tail, line)))
		return (len);
	else
	{
		pointn = NULL;
		while (!pointn && ((len = read(fd, buf, BUFFER_SIZE)) > 0))
		{
			buf[len] = '\0';
			if ((pointn = ft_strchr_gnl(buf, '\n')))
			{
				pointn[0] = '\0';
				if (!(*line = ft_strjoinfree(line, &buf, 1)))
					return (-1);
				return (upd_tail(tail, pointn + 1));
			}
			else if (!(*line = ft_strjoinfree(line, &buf, 1)))
				return (-1);
		}
	}
	return (len);
}

int	get_next_line(int fd, char **line)
{
	static char	*tail;
	char		*buf;
	int			beenread;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!tail)
		if (!(tail = ft_strdup_gnl("")))
			return (-1);
	if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
	{
		free(tail);
		tail = NULL;
		return (-1);
	}
	beenread = ft_line(line, &tail, fd, buf);
	free(buf);
	if (beenread == 0)
		free(tail);
	return (beenread);
}
