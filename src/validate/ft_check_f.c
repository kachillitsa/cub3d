/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:43:04 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		ft_oct3f(int *oct3, int *i, char *line)
{
	if (line[*i] >= '0' && line[*i] <= '9')
		*oct3 = atoi(&line[*i]);
	else
		return (-1);
	if (*oct3 < 0 || *oct3 > 255)
		return (-1);
	*i = *i + ft_nbrlen(*oct3, 10);
	ft_skip_spaces(line, i);
	return (0);
}

int		ft_oct2f(int *oct2, int *i, char *line)
{
	if (line[*i] >= '0' && line[*i] <= '9')
		*oct2 = atoi(&line[*i]);
	else
		return (-1);
	if (*oct2 < 0 || *oct2 > 255)
		return (-1);
	*i = *i + ft_nbrlen(*oct2, 10);
	if (ft_skip_spaces2(line, i) == -1)
		return (-1);
	return (0);
}

int		ft_oct1f(int *oct1, int *i, char *line)
{
	if (line[*i] >= '0' && line[*i] <= '9')
		*oct1 = atoi(&line[*i]);
	else
		return (-1);
	if (*oct1 < 0 || *oct1 > 255)
		return (-1);
	*i = *i + ft_nbrlen(*oct1, 10);
	if (ft_skip_spaces2(line, i) == -1)
		return (-1);
	return (0);
}

void	ft_set_octets_f(int *oct1, int *oct2, int *oct3, int *i)
{
	*oct1 = 0;
	*oct2 = 0;
	*oct3 = 0;
	*i = 0;
}

int		ft_check_f(t_val *val, char *line)
{
	int	i;
	int	oct1;
	int	oct2;
	int	oct3;

	ft_set_octets_f(&oct1, &oct2, &oct3, &i);
	ft_skip_spaces(line, &i);
	i++;
	ft_skip_spaces(line, &i);
	if (ft_oct1f(&oct1, &i, line) == -1 || \
	ft_oct2f(&oct2, &i, line) == -1 || ft_oct3f(&oct3, &i, line) == -1)
		return (-1);
	if (line[i] != '\0')
		return (-1);
	val->col_floor = oct1 * 0x10000 + oct2 * 0x100 + oct3;
	g_proj.ifloor_col = val->col_floor;
	val->ishere_f++;
	return (0);
}
