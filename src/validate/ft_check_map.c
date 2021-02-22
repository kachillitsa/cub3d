/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:43:10 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:22:20 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_ch_m4(int *i, char *line)
{
	if (line[*i] != '1' && line[*i] != '\0')
	{
		ft_free(&line);
		return (-1);
	}
	ft_free(&line);
	return (0);
}

int	ft_ch_m3(t_val *val, char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
	{
		ft_free(&line);
		return (-1);
	}
	val->m_trashl++;
	ft_free(&line);
	return (0);
}

int	ft_ch_m2(t_val *val, int fd, int *i, char *line)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			ft_free(&line);
			return (-1);
		}
		*i = 0;
		ft_skip_spaces(line, i);
		while (line[*i] == ' ' || line[*i] == '1')
		{
			if (line[*i] == '1')
			{
				val->m_trashl++;
				break ;
			}
			*i = *i + 1;
		}
		if (ft_ch_m4(i, line) == -1)
			return (-1);
	}
	if (ft_ch_m3(val, line) == -1)
		return (-1);
	return (0);
}

int	ft_check_map(t_val *val)
{
	int		i;
	int		fd;
	char	*line;

	if (ft_who_is_absent(val) == -1)
		return (-1);
	i = 0;
	fd = open(g_adr.c_map, O_RDONLY);
	while (i < val->trashl_m - 1)
	{
		get_next_line(fd, &line);
		i++;
		ft_free(&line);
	}
	if (ft_ch_m2(val, fd, &i, line) == -1)
		return (-1);
	close(fd);
	if (ft_check_map2(ft_the_line(val), val) == -1)
		return (-1);
	ft_map(ft_the_line(val), line, val);
	return (0);
}
