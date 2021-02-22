/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:00:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 23:01:55 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include "validate/validate.h"

# define PI				3.14159
# define PI2			6.28318
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_LT			65361
# define KEY_RT			65363
# define KEY_ESC		65307

# define K_NONE			0b0000000000000000
# define K_ON_W			0b0000000000000001
# define K_ON_S			0b0000000000000010
# define K_ON_A			0b0000000000000100
# define K_ON_D			0b0000000000001000
# define K_ON_LT		0b0000000000010000
# define K_ON_RT		0b0000000000100000
# define K_ON_ESC		0b0000000001000000

typedef struct			s_image
{
	int					bpp;
	int					bpp_8;
	int					b_ord;
	int					width;
	int					height;
	int					height_start;
	int					*data;
	float				scale;
	float				step;
	int					iprior;
	void				*ptr;
	char				*addr;
	int					size_line;
}						t_image;

typedef struct			s_proj
{
	void				*mlx;
	void				*mlx_win;
	void				*win;
	t_image				win_buf;
	t_image				win_buf0;
	t_image				win_buf1;
	int					scr_wth;
	int					scr_hght;
	int					scr_wth_m1;
	int					scr_hght_m1;
	int					scr_wth05;
	int					scr_hght05;
	int					iceilling_col;
	int					ifloor_col;
}						t_proj;

typedef struct			s_user
{
	float				ur_x;
	float				ur_y;
	float				fur_z0;
	int					iur_z;
	float				fur_z2;
	float				ur_va;
	float				speed;
	unsigned int		keys_on;
}						t_user;

typedef struct			s_obj
{
	char				ctype;
	int					ipriority;
	float				fdist;
	int					i_xx;
	float				f_xx;
	float				f_yy;
}						t_obj;

typedef struct			s_math
{
	float				ffov;
	float				ffov05;
	float				ffov_width;
	float				ffov_vert;
	float				ffloor_ang0;
	float				fsinf_as;
	float				fcosf_as;
	float				fray_as;
	float				ffloor_as;
	float				fray_as2;
	float				ffloor_as2;
	float				fstep_check;
}						t_math;

typedef struct			s_sumup
{
	int					im_h;
	int					im_w;
	char				**map;
	int					*ceil_dn;
	char				***sprite;
	float				f_xx;
	float				f_yy;
	int					ishot;
	float				ceil_x;
	int					iray_x;
	int					isprite_n;
	int					sp_num;
}						t_sumup;

typedef struct			s_temp
{
	int					iceiling_y;
	int					ifloor_y;
	float				fcount_h;
	int					icount_w;
	float				ftxtr_hstep;
}						t_temp;

typedef struct			s_worldgen
{
	int					i_xx;
	int					i_yy;
	float				fdist_to_wall;
	int					ibiggest;
	int					i_xx_old;
	int					i_yy_old;
}						t_worldgen;

typedef struct			s_txtr
{
	t_image				txtr_ceil;
	t_image				*txtr_wall;
	t_image				**en_anim;
}						t_txtr;

typedef struct			s_sprite
{
	float				fsprite_width;
	int					isprite_width;
	float				fsprite_wzero;
	float				fsprite_stepw;
	float				fsprite_txtrh_step;
	float				fe_count_w;
	float				fsprite_h;
	float				fsprite_up;
	float				fsprite_dn;
	float				fsprite_tall;
	int					en_anim_i;
	int					isprite_y;
	int					isprite_y2;
	int					isprite_x;
	int					ifirst_rayx;
	int					iheart;
}						t_sprite;

typedef struct			s_adr
{
	char				*adr_no;
	char				*adr_so;
	char				*adr_we;
	char				*adr_ea;
	char				*adr_s;
	char				*c_map;
}						t_adr;

t_proj					g_proj;
t_user					g_ur;
t_math					g_math;
t_sumup					g_sumup;
t_txtr					g_txtr;
t_sprite				*g_sprite;
t_adr					g_adr;

void					ft_col_ceiling();
void					ft_col_floor();
int						ft_darken(int *color, float *fdist_to_wall);
void					ft_draw_everything();
float					ft_farthest_wall(float *fray_ang, int *ipriority);
int						ft_finish(int key);
int						ft_image_switcher();
void					ft_init_win();
void					ft_key_actions();
int						ft_key_press(int ikey);
int						ft_key_unpress(int ikey);
void					ft_put_texture_on_wall(float *fray_ang, \
	t_obj *obj, int *i);
void					ft_put_texture_on_wall2(float *fray_ang, \
int *ihit_wall, t_obj *obj, int *n);
void					ft_rays();
void					ft_reset_sprites();
void					ft_screenshot();
void					ft_sprite(float *fdist_to_wall);
void					ft_sprite2(int *y, float *fdist_to_wall);
void					ft_sprite_init();
void					ft_sprite_prescan();
void					ft_walls();
void					ft_walls2(t_worldgen *worldgen, t_obj *obj, int *i);
void					ft_walls3(t_worldgen *worldgen, t_obj *obj, int *i);
void					ft_where_am_i(int y, int x0);

#endif
