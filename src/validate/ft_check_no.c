/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:43:32 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_check_no(t_val *val, char *line)
{
	int	i;
	int fd;

	i = 0;
	ft_skip_spaces(line, &i);
	i = i + 2;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		g_adr.adr_no = ft_strdup(&line[i]);
	else
		return (-1);
	fd = open(g_adr.adr_no, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	val->ishere_n++;
	return (0);
}
