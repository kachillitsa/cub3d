/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_definetype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:32:17 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 18:27:26 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		ft_definetype(t_val *val)
{
	char	*ln;
	int		fd;

	if ((fd = open(g_adr.c_map, O_RDONLY)) == -1)
		return (-1);
	if (get_next_line(fd, &ln) > 0)
		if (ln[0] == '\n' || ln[0] == '\0')
		{
			ft_free(&ln);
			return (-1);
		}
	ft_free(&ln);
	close(fd);
	if ((fd = open(g_adr.c_map, O_RDONLY)) == -1)
		return (-1);
	ft_definetype2(fd, val);
	close(fd);
	if (ft_check_map(val) == -1)
		return (-1);
	return (0);
}
