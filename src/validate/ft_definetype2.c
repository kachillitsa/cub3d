/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_definetype2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:32:28 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 18:27:05 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_deft5(int i, char **line)
{
	if (line[0][i] != 'C' && line[0][i] != 'R' && \
	line[0][i] != 'S' && line[0][i] != 'W' && \
	line[0][i] != 'N' && line[0][i] != 'E' && \
	line[0][i] != 'F')
		return (-1);
	return (0);
}

int	ft_deft4(t_val *val, int *i, char *line)
{
	val->trashl_m++;
	if (line[*i] <= '~' && line[*i] >= '!')
		return (-1);
	return (0);
}

int	ft_deft3(t_val *val, int i, char *line)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		if (ft_check_no(val, line) == -1)
			return (-1);
	}
	if (line[i] == 'F')
	{
		if (ft_check_f(val, line) == -1)
			return (-1);
	}
	if (line[i] == 'C')
	{
		if (ft_check_c(val, line) == -1)
			return (-1);
	}
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		if (ft_check_we(val, line) == -1)
			return (-1);
	}
	return (0);
}

int	ft_deft2(t_val *val, int i, char *line)
{
	if (ft_deft3(val, i, line) == -1)
		return (-1);
	if (line[i] == 'S' && line[i + 1] != 'O')
	{
		if (ft_check_s(val, line) == -1)
			return (-1);
	}
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		if (ft_check_ea(val, line) == -1)
			return (-1);
	}
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		if (ft_check_so(val, line) == -1)
			return (-1);
	}
	if (line[i] == 'R')
	{
		if (ft_check_r(val, line) == -1)
			return (-1);
	}
	return (0);
}

int	ft_definetype2(int fd, t_val *val)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		ft_deft4(val, &i, line);
		if (line[i] == '1')
			break ;
		else if (ft_deft2(val, i, line) == -1)
		{
			ft_free(&line);
			return (-1);
		}
		if (line[i] != '\0' && ft_deft5(i, &line) == -1)
		{
			ft_free(&line);
			return (-1);
		}
		ft_free(&line);
	}
	ft_free(&line);
	return (0);
}
