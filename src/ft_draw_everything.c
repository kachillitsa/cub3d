/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:32:59 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 00:33:02 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_everything(void)
{
	ft_col_floor();
	ft_reset_sprites();
	ft_sprite_prescan();
	ft_walls();
	ft_col_ceiling();
	ft_key_actions();
}
