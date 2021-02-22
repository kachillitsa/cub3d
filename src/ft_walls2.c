/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:02:01 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 17:19:53 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_walls_last(t_worldgen *worldgen, t_obj *obj, int *i)
{
	obj[*i].fdist = worldgen->fdist_to_wall;
	obj[*i].i_xx = worldgen->i_xx;
	obj[*i].f_xx = g_sumup.f_xx;
	obj[*i].f_yy = g_sumup.f_yy;
}

void	ft_walls_bb(t_worldgen *worldgen, t_obj *obj, int *i)
{
	worldgen->ibiggest = g_txtr.txtr_wall[g_sumup.map\
		[worldgen->i_yy][worldgen->i_xx] - '0'].iprior;
	if (g_sumup.map[worldgen->i_yy][(int)(g_sumup.f_xx - 0.01f)] != '1')
		obj[*i].ctype = '4';
	else if (g_sumup.map[worldgen->i_yy][(int)(g_sumup.f_xx + 0.01f)] != '1')
		obj[*i].ctype = '1';
	else if (g_sumup.map[(int)(g_sumup.f_yy + 0.01f)][worldgen->i_xx] != '1')
		obj[*i].ctype = '3';
	else if (g_sumup.map[(int)(g_sumup.f_yy - 0.01f)][worldgen->i_xx] != '1')
		obj[*i].ctype = '2';
	else
		obj[*i].ctype = '2';
	ft_walls_last(worldgen, obj, i);
	*i = *i + 1;
	while (worldgen->i_xx_old == (int)(g_sumup.f_xx) && \
		worldgen->i_yy_old == (int)(g_sumup.f_yy))
	{
		worldgen->fdist_to_wall += g_math.fstep_check;
		g_sumup.f_xx = g_sumup.f_xx + \
			g_math.fsinf_as;
		g_sumup.f_yy = g_sumup.f_yy + \
			g_math.fcosf_as;
	}
	worldgen->i_xx = (int)(g_sumup.f_xx);
	worldgen->i_yy = (int)(g_sumup.f_yy);
}

void	ft_walls_bd(t_worldgen *worldgen, t_obj *obj, int *i)
{
	if (g_sumup.map[worldgen->i_yy][worldgen->i_xx] < '1' || \
		g_sumup.map[worldgen->i_yy][worldgen->i_xx] >= 'a')
	{
		obj[*i].ctype = obj[*i - 1].ctype;
		obj[*i].fdist = worldgen->fdist_to_wall;
		obj[*i].i_xx = obj[*i - 1].i_xx;
		obj[*i].f_xx = g_sumup.f_xx - \
			g_math.fsinf_as;
		obj[*i].f_yy = g_sumup.f_yy - \
			g_math.fcosf_as;
		i++;
	}
	else if (g_txtr.txtr_wall[g_sumup.map[worldgen->i_yy]\
		[worldgen->i_xx] - '0'].iprior < worldgen->ibiggest)
	{
		obj[*i].ctype = obj[*i - 1].ctype;
		obj[*i].fdist = worldgen->fdist_to_wall;
		obj[*i].i_xx = obj[*i - 1].i_xx;
		obj[*i].f_xx = g_sumup.f_xx - g_math.fsinf_as;
		obj[*i].f_yy = g_sumup.f_yy - g_math.fcosf_as;
		i++;
	}
}

void	ft_walls2(t_worldgen *worldgen, t_obj *obj, int *i)
{
	ft_walls_bb(worldgen, obj, i);
	ft_walls_bd(worldgen, obj, i);
}
