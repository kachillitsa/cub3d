/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:58:50 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_walls_a(t_worldgen *worldgen, float *ray_ang, int *i)
{
	*i = 0;
	g_sumup.ceil_dn[g_sumup.iray_x] = g_proj.scr_hght;
	worldgen->ibiggest = 0;
	worldgen->fdist_to_wall = 0;
	g_math.fsinf_as = -sinf(*ray_ang) * g_math.fstep_check;
	g_math.fcosf_as = -cosf(*ray_ang) * g_math.fstep_check;
	g_sumup.f_xx = g_ur.ur_x;
	g_sumup.f_yy = g_ur.ur_y;
	worldgen->i_xx = (int)(g_sumup.f_xx);
	worldgen->i_yy = (int)(g_sumup.f_yy);
}

void	ft_walls_b(t_obj *obj, float *ray_ang, int *i)
{
	*i = *i - 1;
	ft_put_texture_on_wall(ray_ang, obj, i);
	g_sumup.iray_x++;
	*ray_ang = *ray_ang - g_math.fray_as;
}

void	ft_walls_c(t_worldgen *worldgen)
{
	while (worldgen->i_xx_old == (int)(g_sumup.f_xx) && \
		worldgen->i_yy_old == (int)(g_sumup.f_yy))
	{
		worldgen->fdist_to_wall += g_math.fstep_check;
		g_sumup.f_xx = g_sumup.f_xx + g_math.fsinf_as;
		g_sumup.f_yy = g_sumup.f_yy + g_math.fcosf_as;
	}
	worldgen->i_xx = (int)(g_sumup.f_xx);
	worldgen->i_yy = (int)(g_sumup.f_yy);
	worldgen->i_xx_old = worldgen->i_xx;
	worldgen->i_yy_old = worldgen->i_yy;
}

void	ft_walls_d(t_obj *obj, t_worldgen *worldgen, int *i)
{
	while (g_sumup.map[worldgen->i_yy][worldgen->i_xx] != '#')
	{
		ft_walls_c(worldgen);
		if (g_sumup.map[worldgen->i_yy][worldgen->i_xx] != ' ')
		{
			if (g_sumup.map[worldgen->i_yy][worldgen->i_xx] >= 'a')
				ft_walls3(worldgen, obj, i);
			else if (g_sumup.map[worldgen->i_yy][worldgen->i_xx] >= \
				'1' && g_txtr.txtr_wall[g_sumup.map[worldgen->i_yy]\
				[worldgen->i_xx] - '0'].iprior >= worldgen->ibiggest)
			{
				ft_walls2(worldgen, obj, i);
				if (worldgen->ibiggest >= 8 || *i > 6)
					break ;
			}
		}
	}
}

void	ft_walls(void)
{
	t_obj				obj[20];
	static t_worldgen	worldgen;
	float				ray_ang;
	int					i;

	worldgen.i_xx = 0;
	worldgen.i_yy = 0;
	worldgen.fdist_to_wall = 0;
	worldgen.ibiggest = 0;
	worldgen.i_xx_old = 0;
	worldgen.i_yy_old = 0;
	g_sumup.iray_x = 0;
	ray_ang = g_ur.ur_va + g_math.ffov05;
	while (g_sumup.iray_x < g_proj.scr_wth)
	{
		ft_walls_a(&worldgen, &ray_ang, &i);
		ft_walls_d(obj, &worldgen, &i);
		ft_walls_b(obj, &ray_ang, &i);
	}
}
