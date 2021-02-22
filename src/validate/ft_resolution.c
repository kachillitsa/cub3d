/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:30:01 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	ft_resolution(int *width, int *height)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	mlx_get_screen_size(g_proj.mlx, &w, &h);
	if (h < *height)
		*height = h;
	if (w < *width)
		*width = w;
}
