/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:30:57 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 13:46:23 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	ft_map3(int *i, int fd, char *ln, t_val *val)
{
	*i = 0;
	while (*i < val->trashl_m - 1)
	{
		get_next_line(fd, &ln);
		*i = *i + 1;
		ft_free(&ln);
	}
	*i = 1;
}

void	ft_map2(int *i, int max_line, char *ln, t_val *val)
{
	int fd;
	int k;

	fd = open(g_adr.c_map, O_RDONLY);
	ft_map3(i, fd, ln, val);
	while (*i <= val->m_trashl)
	{
		get_next_line(fd, &ln);
		k = max_line - ft_strlen(ln) + 1;
		ft_strjoin_f("#", ln, &ln);
		while (k > 0)
		{
			ft_strjoin_f(ln, "#", &ln);
			k--;
		}
		g_sumup.map[*i] = ft_strdup(ln);
		ft_free(&ln);
		*i = *i + 1;
	}
	close(fd);
}

void	ft_setglobal(int *i, int *k, int *j, t_val *val)
{
	*i = 1;
	*k = 0;
	*j = 0;
	while (*i < val->m_trashl + 1)
	{
		*j = 0;
		while (g_sumup.map[*i][*j] != '\0')
		{
			if (g_sumup.map[*i][*j] == ' ')
				g_sumup.map[*i][*j] = '#';
			if (g_sumup.map[*i][*j] == '0')
				g_sumup.map[*i][*j] = ' ';
			if (g_sumup.map[*i][*j] == '2')
			{
				g_sumup.map[*i][*j] = 'a' + *k;
				*k = *k + 1;
			}
			*j = *j + 1;
		}
		*i = *i + 1;
	}
	g_sumup.im_h = val->m_trashl + 1;
}

int		ft_map(int max_line, char *ln, t_val *val)
{
	int	i;
	int	j;
	int	k;

	if (val->m_trashl == 0)
		return (-1);
	g_sumup.map = malloc(sizeof(char*) * (val->m_trashl + 2));
	ft_map2(&i, max_line, ln, val);
	j = 0;
	g_sumup.map[0] = ft_strdup("#");
	g_sumup.map[val->m_trashl + 1] = ft_strdup("#");
	while (j < max_line + 1)
	{
		ft_strjoin_f(g_sumup.map[0], "#", &g_sumup.map[0]);
		ft_strjoin_f(g_sumup.map[val->m_trashl + 1], \
		"#", &g_sumup.map[val->m_trashl + 1]);
		j++;
	}
	ft_setglobal(&i, &k, &j, val);
	return (0);
}
