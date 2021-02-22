/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:42:40 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:15:47 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	ft_bord3(char **map, int *x)
{
	ft_strchr(map[*x], 0);
	*x = *x + 1;
}

int		ft_bord2(char *ln1, char *ln2, char *ln3, int y)
{
	if (ln2[y] == '0' || ln2[y] == 'W' || ln2[y] == 'E' \
	|| ln2[y] == 'S' || ln2[y] == 'N' || ln2[y] == '2')
		if (ln1[y] == ' ' || ln1[y - 1] == ' ' || ln1[y + 1] == \
		' ' || ln3[y] == ' ' || ln3[y - 1] == ' ' || ln3[y + 1] \
		== ' ' || ln2[y - 1] == ' ' || ln2[y + 1] == ' ')
			return (-1);
	if (ln2[y] == '0' || ln2[y] == 'W' || ln2[y] == 'E' \
	|| ln2[y] == 'S' || ln2[y] == 'N' || ln2[y] == '2')
		if (ln1[y] == '\0' || ln1[y - 1] == '\0' \
		|| ln1[y + 1] == '\0' || ln3[y] == '\0' \
		|| ln3[y - 1] == '\0' || ln3[y + 1] == '\0' \
		|| ln2[y - 1] == '\0' || ln2[y + 1] == '\0')
			return (-1);
	return (0);
}

int		ft_edges(char **map, t_val *val)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] == '0' || map[0][i] == 'W' \
		|| map[0][i] == 'E' || map[0][i] == 'S' \
		|| map[0][i] == 'N' || map[0][i] == '2')
			return (-1);
		i++;
	}
	i = 0;
	while (map[val->m_trashl - 1][i] != '\0')
	{
		if (map[val->m_trashl - 1][i] == '0' \
		|| map[val->m_trashl - 1][i] == 'W' \
		|| map[val->m_trashl - 1][i] == 'E' \
		|| map[val->m_trashl - 1][i] == 'S' \
		|| map[val->m_trashl - 1][i] == 'N' \
		|| map[val->m_trashl - 1][i] == '2')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_borders(char **map, t_val *val)
{
	int		x;
	int		y;
	char	*ln1;
	char	*ln2;
	char	*ln3;

	if (ft_edges(map, val) == -1)
		return (-1);
	x = 1;
	while (x < (val->m_trashl - 1))
	{
		y = 1;
		ln1 = ft_strdup(map[x - 1]);
		ln2 = ft_strdup(map[x]);
		ln3 = ft_strdup(map[x + 1]);
		while (map[x][y] != '\0')
		{
			if (ft_bord2(ln1, ln2, ln3, y) == -1)
				return (-1);
			y++;
		}
		ft_bord3(map, &x);
		ft_free_3(&ln1, &ln2, &ln3);
	}
	return (0);
}
