/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:22:51 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_win(void)
{
	g_proj.win_buf0.ptr = mlx_new_image(g_proj.mlx, \
	g_proj.scr_wth, g_proj.scr_hght);
	g_proj.win_buf0.addr = mlx_get_data_addr(g_proj.win_buf0.ptr, \
	&g_proj.win_buf0.bpp, &g_proj.win_buf0.size_line, &g_proj.win_buf0.b_ord);
	g_proj.win_buf0.data = (int *)mlx_get_data_addr(g_proj.win_buf0.ptr, \
	&g_proj.win_buf0.bpp, &g_proj.win_buf0.size_line, &g_proj.win_buf0.b_ord);
	g_proj.win_buf0.bpp_8 = g_proj.win_buf0.bpp / 8;
	g_proj.win_buf1.ptr = mlx_new_image(g_proj.mlx, \
	g_proj.scr_wth, g_proj.scr_hght);
	g_proj.win_buf1.addr = mlx_get_data_addr(g_proj.win_buf1.ptr, \
	&g_proj.win_buf1.bpp, &g_proj.win_buf1.size_line, &g_proj.win_buf1.b_ord);
	g_proj.win_buf1.data = (int *)mlx_get_data_addr(g_proj.win_buf1.ptr, \
	&g_proj.win_buf1.bpp, &g_proj.win_buf1.size_line, &g_proj.win_buf1.b_ord);
	g_proj.win_buf1.bpp_8 = g_proj.win_buf1.bpp / 8;
	g_proj.win_buf.ptr = g_proj.win_buf0.ptr;
	g_proj.win_buf.data = g_proj.win_buf0.data;
}
