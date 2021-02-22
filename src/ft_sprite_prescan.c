/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_prescan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:53:00 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 18:55:27 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sp_presc2(void)
{
	static int		i_xx;
	static int		i_yy;
	static float	walldist;

	walldist = 0;
	g_sumup.f_xx = g_ur.ur_x;
	g_sumup.f_yy = g_ur.ur_y;
	i_xx = (int)(g_sumup.f_xx);
	i_yy = (int)(g_sumup.f_yy);
	while (g_sumup.map[i_yy][i_xx] != '#')
	{
		walldist += 0.09f;
		g_sumup.f_xx = g_sumup.f_xx - g_math.fsinf_as;
		g_sumup.f_yy = g_sumup.f_yy - g_math.fcosf_as;
		i_xx = (int)(g_sumup.f_xx);
		i_yy = (int)(g_sumup.f_yy);
		if (g_sumup.map[i_yy][i_xx] >= \
			'a' && g_sumup.map[i_yy][i_xx] <= 'v')
		{
			g_sumup.isprite_n = g_sumup.map[i_yy][i_xx] - 'a';
			ft_sprite(&walldist);
		}
	}
}

void	ft_sprite_prescan(void)
{
	static float	ray_ang;

	g_sumup.iray_x = -400;
	ray_ang = g_ur.ur_va + g_math.ffov05 - \
		g_sumup.iray_x * g_math.fray_as;
	while (g_sumup.iray_x < 0)
	{
		g_math.fsinf_as = sinf(ray_ang) * 0.09f;
		g_math.fcosf_as = cosf(ray_ang) * 0.09f;
		ft_sp_presc2();
		g_sumup.iray_x++;
		ray_ang -= g_math.fray_as;
	}
}
