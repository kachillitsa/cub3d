/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:26:18 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 23:49:34 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_walls(int *i, char *ctxtr_name)
{
	while (*i <= 4)
	{
		if (*i == 3)
			ctxtr_name = g_adr.adr_no;
		if (*i == 4)
			ctxtr_name = g_adr.adr_ea;
		if (*i == 1)
			ctxtr_name = g_adr.adr_we;
		if (*i == 2)
			ctxtr_name = g_adr.adr_so;
		g_txtr.txtr_wall[*i].ptr = mlx_xpm_file_to_image(g_proj.mlx, \
		ctxtr_name, &g_txtr.txtr_wall[*i].width, &g_txtr.txtr_wall[*i].height);
		g_txtr.txtr_wall[*i].data = \
			(int *)mlx_get_data_addr(g_txtr.txtr_wall[*i].ptr, \
			&g_txtr.txtr_wall[*i].bpp, &g_txtr.txtr_wall[*i].size_line, \
			&g_txtr.txtr_wall[*i].b_ord);
		g_txtr.txtr_wall[*i].scale = 1;
		g_txtr.txtr_wall[*i].height = g_txtr.txtr_wall[*i].height - 1;
		g_txtr.txtr_wall[*i].height_start = g_txtr.txtr_wall[*i].height * 3 / 4;
		g_txtr.txtr_wall[*i].iprior = 5;
		*i = *i + 1;
	}
}

void	ft_main_body(int argc)
{
	char	*ctxtr_name;
	int		i;

	i = 1;
	g_txtr.txtr_wall = malloc(sizeof(t_image) * 10);
	ctxtr_name = NULL;
	g_proj.scr_hght_m1 = g_proj.scr_hght - 1;
	g_proj.scr_wth_m1 = g_proj.scr_wth - 1;
	g_proj.scr_wth05 = g_proj.scr_wth / 2;
	g_proj.scr_hght05 = g_proj.scr_hght / 2;
	if (argc < 3)
		g_proj.mlx_win = mlx_new_window(g_proj.mlx, \
			g_proj.scr_wth, g_proj.scr_hght, "Hi there, adventurer!");
	ft_init_win();
	ft_rays();
	ft_sprite_init();
	ft_where_am_i(g_sumup.im_h, ft_strlen(g_sumup.map[0]) - 1);
	ft_init_walls(&i, ctxtr_name);
}

int		ft_check_c_map(char *ctemp)
{
	int	ret;

	ret = 0;
	if (ctemp[ft_strlen(ctemp) - 1] != 'b')
		ret = -1;
	if (ctemp[ft_strlen(ctemp) - 2] != 'u')
		ret = -1;
	if (ctemp[ft_strlen(ctemp) - 3] != 'c')
		ret = -1;
	if (ctemp[ft_strlen(ctemp) - 4] != '.')
		ret = -1;
	return (ret);
}

int		ft_check_args(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
		return (-1);
	if (argc > 1)
		if (ft_check_c_map(argv[1]) == -1)
			return (-1);
	if (argc == 3)
		if (ft_strcmp(argv[2], "--save") != 0)
			return (-1);
	g_adr.c_map = ft_strdup(argv[1]);
	return (0);
}

int		main(int argc, char **argv)
{
	if (ft_check_args(argc, argv) == -1)
	{
		write(2, "Error:\nwrong args\n", 19);
		return (-1);
	}
	g_proj.mlx = mlx_init();
	if (ft_validate() == -1)
		return (-1);
	ft_main_body(argc);
	g_sumup.ceil_dn = malloc(sizeof(int) * g_proj.scr_wth);
	if (argc == 3)
	{
		ft_draw_everything();
		ft_screenshot();
		ft_finish(1);
	}
	mlx_hook(g_proj.mlx_win, 2, 1L << 0, ft_key_press, &g_proj.mlx_win);
	mlx_hook(g_proj.mlx_win, 3, 1L << 1, ft_key_unpress, &g_proj.mlx_win);
	mlx_loop_hook(g_proj.mlx, ft_image_switcher, &g_proj.mlx_win);
	mlx_hook(g_proj.mlx_win, 17, 1L << 17, ft_finish, &g_proj.mlx_win);
	mlx_loop(g_proj.mlx);
	return (1);
}
