/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:11:30 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_scrshot4(int fd)
{
	int				j;
	int				i;
	unsigned char	bmp_buf[4];

	i = g_proj.scr_hght;
	while (i >= 0)
	{
		j = 0;
		while (j < g_proj.scr_wth)
		{
			bmp_buf[0] = (unsigned char)(g_proj.win_buf0.data\
			[j + i * g_proj.scr_wth] & 0xFF);
			bmp_buf[1] = (unsigned char)(g_proj.win_buf0.data\
			[j + i * g_proj.scr_wth] >> 8 & 0xFF);
			bmp_buf[2] = (unsigned char)(g_proj.win_buf0.data\
			[j + i * g_proj.scr_wth] >> 16);
			bmp_buf[3] = (unsigned char)(0);
			write(fd, bmp_buf, 4);
			j++;
		}
		i--;
	}
}

void	ft_scrshot3(int fd)
{
	int				n;
	unsigned char	bmp_info[40];

	n = 0;
	while (n < 40)
		bmp_info[n++] = (unsigned char)(0);
	bmp_info[0] = (unsigned char)(40);
	n = g_proj.scr_wth;
	bmp_info[4] = (unsigned char)(n % 256);
	bmp_info[5] = (unsigned char)(n / 256 % 256);
	bmp_info[6] = (unsigned char)(n / 256 / 256 % 256);
	bmp_info[7] = (unsigned char)(n / 256 / 256 / 256);
	n = g_proj.scr_hght;
	bmp_info[8] = (unsigned char)(n % 256);
	bmp_info[9] = (unsigned char)(n / 256 % 256);
	bmp_info[10] = (unsigned char)(n / 256 / 256 % 256);
	bmp_info[11] = (unsigned char)(n / 256 / 256 / 256);
	bmp_info[12] = (unsigned char)(1);
	bmp_info[14] = (unsigned char)(32);
	write(fd, bmp_info, 40);
}

void	ft_scrshot2(int fd)
{
	int				n;
	unsigned char	bmp_info[14];

	n = 0;
	while (n < 14)
		bmp_info[n++] = (unsigned char)(0);
	bmp_info[0] = (unsigned char)(66);
	bmp_info[1] = (unsigned char)(77);
	n = g_proj.scr_hght * g_proj.scr_wth * 4 + 54;
	bmp_info[2] = (unsigned char)(n % 256);
	bmp_info[3] = (unsigned char)(n / 256 % 256);
	bmp_info[4] = (unsigned char)(n / 256 / 256 % 256);
	bmp_info[5] = (unsigned char)(n / 256 / 256 / 256);
	bmp_info[10] = (unsigned char)(54);
	write(fd, bmp_info, 14);
}

void	ft_screenshot(void)
{
	int	fd;

	fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_scrshot2(fd);
	ft_scrshot3(fd);
	ft_scrshot4(fd);
	close(fd);
}
