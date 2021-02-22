/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:09:19 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:44:21 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "gnl/get_next_line.h"
# include "../../libft/libft.h"
# include "../cub3d.h"

typedef struct	s_val
{
	int			scr_wdth;
	int			scr_hght;
	int			col_floor;
	int			col_ceiling;
	int			ishere_r;
	int			ishere_n;
	int			ishere_so;
	int			ishere_w;
	int			ishere_e;
	int			ishere_s;
	int			ishere_f;
	int			ishere_c;
	int			m_trashl;
	int			trashl_m;
	int			m_n;
	int			m_s;
	int			m_e;
	int			m_w;
}				t_val;

int				ft_borders(char **map, t_val *val);
int				ft_check_c(t_val *val, char *line);
int				ft_check_ea(t_val *val, char *line);
int				ft_check_f(t_val *val, char *line);
int				ft_check_map(t_val *val);
int				ft_check_map2(int line_len, t_val *val);
size_t			ft_check_map3(char *dst, const char *src, \
	size_t size, char x);
int				ft_check_no(t_val *val, char *line);
int				ft_check_position(t_val *val);
int				ft_check_r(t_val *val, char *line);
int				ft_check_s(t_val *val, char *line);
int				ft_check_so(t_val *val, char *line);
int				ft_check_we(t_val *val, char *line);
int				ft_definetype(t_val *val);
int				ft_definetype2(int fd, t_val *val);
int				ft_map(int max_line, char *ln, t_val *val);
void			ft_resolution(int *width, int *height);
void			ft_set_all_zero(t_val *val);
void			ft_skip_spaces(char *line, int *i);
int				ft_skip_spaces2(char *line, int *i);
int				ft_the_line(t_val *val);
int				ft_trash(char **map, t_val *val);
int				ft_validate(void);
int				ft_who_is_absent(t_val *val);

#endif
