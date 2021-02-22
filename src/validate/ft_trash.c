/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:44:29 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 12:38:14 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	ft_position(char **map, t_val *val, int x, int y)
{
	if (map[x][y] == 'N')
		val->m_n++;
	if (map[x][y] == 'S')
		val->m_s++;
	if (map[x][y] == 'W')
		val->m_w++;
	if (map[x][y] == 'E')
		val->m_e++;
	if (map[x][y] == '2')
		g_sumup.sp_num++;
}

int		ft_trash(char **map, t_val *val)
{
	int	x;
	int	y;

	x = 0;
	while (x < val->m_trashl)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] != '2' && map[x][y] != '0' && \
			map[x][y] != '1' && map[x][y] != 'N' &&
			map[x][y] != 'S' && map[x][y] != 'W' && \
			map[x][y] != 'E' && map[x][y] != ' ')
				return (-1);
			ft_position(map, val, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
