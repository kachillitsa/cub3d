/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:01:28 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:11:10 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_finish_2(int *i, int *j)
{
	while (*i <= 4)
	{
		if (g_txtr.txtr_wall[*i].ptr)
			mlx_destroy_image(g_proj.mlx, g_txtr.txtr_wall[*i].ptr);
		*i = *i + 1;
	}
	*i = 0;
	while (*i < g_sumup.sp_num)
	{
		*j = 0;
		while (*j <= 30)
		{
			if (g_sumup.sprite[*i][*j])
				free(g_sumup.sprite[*i][*j]);
			*j = *j + 1;
		}
		if (g_txtr.en_anim[*i][0].ptr)
			mlx_destroy_image(g_proj.mlx, g_txtr.en_anim[*i][0].ptr);
		if (g_txtr.en_anim[*i])
			free(g_txtr.en_anim[*i]);
		if (g_sumup.sprite[*i])
			free(g_sumup.sprite[*i]);
		*i = *i + 1;
	}
}

void	ft_finish_3(void)
{
	if (g_sumup.map)
		free(g_sumup.map);
	if (g_txtr.txtr_wall)
		free(g_txtr.txtr_wall);
	if (g_sumup.ceil_dn)
		free(g_sumup.ceil_dn);
}

void	ft_finish_4(void)
{
	if (g_sprite)
		free(g_sprite);
	if (g_proj.win_buf0.ptr)
		mlx_destroy_image(g_proj.mlx, g_proj.win_buf0.ptr);
	if (g_proj.win_buf1.ptr)
		mlx_destroy_image(g_proj.mlx, g_proj.win_buf1.ptr);
	if (g_proj.mlx && g_proj.mlx_win)
		mlx_destroy_window(g_proj.mlx, g_proj.mlx_win);
	if (g_sumup.sprite)
		free(g_sumup.sprite);
	if (g_txtr.en_anim)
		free(g_txtr.en_anim);
}

void	ft_finish_1(void)
{
	int	i;

	i = 0;
	while (i <= g_sumup.im_h)
	{
		if (g_sumup.map[i] != NULL)
			free(g_sumup.map[i]);
		i++;
	}
	if (g_adr.c_map)
		free(g_adr.c_map);
}

int		ft_finish(int key)
{
	int	i;
	int	j;

	i = 1;
	if (key == 1)
	{
		ft_finish_1();
		ft_finish_2(&i, &j);
		ft_finish_3();
		ft_finish_4();
	}
	if (key == 2)
	{
		ft_finish_1();
		ft_finish_4();
	}
	exit(0);
}
