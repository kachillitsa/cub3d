/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farthest_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:13:43 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 17:36:32 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_params(float *fray_ang, int *ipriority)
{
	ipriority[0] = 1;
	g_sumup.f_xx = g_ur.ur_x;
	g_sumup.f_yy = g_ur.ur_y;
	g_math.fsinf_as = sinf(*fray_ang) * 0.4f;
	g_math.fcosf_as = cosf(*fray_ang) * 0.4f;
}

float	ft_farthest_wall(float *fray_ang, int *ipriority)
{
	static float	dist_wall;
	static int		i_xx;
	static int		i_yy;
	static int		i_xxold;
	static int		i_yyold;

	dist_wall = 0;
	ft_set_params(fray_ang, ipriority);
	i_xx = (int)(g_sumup.f_xx);
	i_yy = (int)(g_sumup.f_yy);
	while (g_sumup.map[i_yy][i_xx] != '#')
	{
		dist_wall += 0.4f;
		g_sumup.f_xx = g_sumup.f_xx - g_math.fsinf_as;
		g_sumup.f_yy = g_sumup.f_yy - g_math.fcosf_as;
		i_xx = (int)(g_sumup.f_xx);
		i_yy = (int)(g_sumup.f_yy);
		if (g_sumup.map[i_yy][i_xx] != ' ')
			if (i_xxold != i_xx && i_yyold != i_yy)
			{
				i_xxold = i_xx;
				i_yyold = i_yy;
			}
	}
	return (dist_wall);
}
