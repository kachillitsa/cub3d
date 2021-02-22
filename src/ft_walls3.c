/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:00:31 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 17:19:53 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_walls_ab(t_worldgen *worldgen)
{
	while (worldgen->i_xx_old == (int)(g_sumup.f_xx) \
		&& worldgen->i_yy_old == (int)(g_sumup.f_yy))
	{
		worldgen->fdist_to_wall += g_math.fstep_check;
		g_sumup.f_xx = g_sumup.f_xx + g_math.fsinf_as;
		g_sumup.f_yy = g_sumup.f_yy + g_math.fcosf_as;
	}
}

void	ft_walls3(t_worldgen *worldgen, t_obj *obj, int *i)
{
	while (worldgen->i_xx_old == (int)(g_sumup.f_xx) && \
		worldgen->i_yy_old == (int)(g_sumup.f_yy))
	{
		if (g_sumup.sprite[g_sumup.map[worldgen->i_yy]\
			[worldgen->i_xx] - 'a'][(int)(30 * (g_sumup.f_yy - \
			(int)g_sumup.f_yy))][(int)(30 * (g_sumup.f_xx - \
			(int)g_sumup.f_xx))] == '+')
		{
			obj[*i].ctype = g_sumup.map[worldgen->i_yy][worldgen->i_xx];
			obj[*i].fdist = worldgen->fdist_to_wall;
			obj[*i].i_xx = worldgen->i_xx;
			obj[*i].f_xx = g_sumup.f_xx;
			obj[*i].f_yy = g_sumup.f_yy;
			*i = *i + 1;
			break ;
		}
		worldgen->fdist_to_wall += g_math.fstep_check;
		g_sumup.f_xx = g_sumup.f_xx + g_math.fsinf_as;
		g_sumup.f_yy = g_sumup.f_yy + g_math.fcosf_as;
	}
	ft_walls_ab(worldgen);
}
