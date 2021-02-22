/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:44:22 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	ft_tl2(int *i, t_val *val, int fd, char *line)
{
	while (*i < val->trashl_m - 1)
	{
		get_next_line(fd, &line);
		*i = *i + 1;
		if (line)
			free(line);
	}
	*i = 0;
}

int		ft_the_line(t_val *val)
{
	char	*line;
	int		fd;
	int		i;
	size_t	longest_mline;

	i = 0;
	longest_mline = 0;
	fd = open(g_adr.c_map, O_RDONLY);
	ft_tl2(&i, val, fd, line);
	while (i < val->m_trashl)
	{
		get_next_line(fd, &line);
		if (ft_strlen(line) > longest_mline)
			longest_mline = ft_strlen(line);
		if (line)
			free(line);
		i++;
	}
	close(fd);
	return (longest_mline);
}
