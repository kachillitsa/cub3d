/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:43:47 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_check_s(t_val *val, char *line)
{
	int	i;
	int fd;

	i = 0;
	ft_skip_spaces(line, &i);
	i++;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		g_adr.adr_s = ft_strdup(&line[i]);
	else
		return (-1);
	val->ishere_s++;
	fd = open(g_adr.adr_s, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
