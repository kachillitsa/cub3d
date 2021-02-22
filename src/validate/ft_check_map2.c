/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:43:18 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		ft_chm2_4(char **map, t_val *val)
{
	if (ft_trash(map, val) == -1 || \
	ft_borders(map, val) == -1)
		return (-1);
	else
		return (0);
}

void	ft_chm2_2(int *res, int *i, char **map, t_val *val)
{
	*res = 0;
	if (ft_chm2_4(map, val) == -1)
		*res = -1;
	*i = 0;
	while (*i < val->m_trashl)
	{
		free(map[*i]);
		*i = *i + 1;
	}
	free(map);
}

void	ft_chm2_3(int fd, int *i, char *line, t_val *val)
{
	*i = 0;
	while (*i < val->trashl_m - 1)
	{
		get_next_line(fd, &line);
		*i = *i + 1;
		if (line)
			free(line);
	}
	*i = 0;
}

int		ft_check_map2(int line_len, t_val *val)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		res;

	map = malloc(sizeof(char*) * val->m_trashl + 1);
	fd = open(g_adr.c_map, O_RDONLY);
	ft_chm2_3(fd, &i, line, val);
	while (i < val->m_trashl)
	{
		get_next_line(fd, &line);
		map[i] = malloc(sizeof(char) * line_len + 1);
		ft_check_map3(map[i], line, line_len, ' ');
		i++;
		if (line)
			free(line);
	}
	close(fd);
	ft_chm2_2(&res, &i, map, val);
	return (res);
}
