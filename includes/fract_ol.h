/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:37:36 by moguy             #+#    #+#             */
/*   Updated: 2019/03/26 16:28:02 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				siz;
	int				bpp;
	int				end;
	int				width;
	int				heigth;
	int				mode;
	int				mode2;
	int				mode3;
	int				colorset;
	int				onoff;
	int				nlt;
	int				ymove;
	int				xmove;
	int				ymouse;
	int				xmouse;
	int				keyboard;
	int				keymouse;
	float			itertest;
	float			itermax;
	double			ix;
	double			iy;
	double			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			ci;
	double			cr;
	pthread_t		thread[4];
}					t_mlx;

void				deal_exit(void *mlx);

int					deal_exit2(int key, void *mlx);

void				deal_color(void *mlx);

void				deal_arrow(void *mlx, int key);

int					deal_key(int key, void *mlx);

int					deal_loop(void *mlx);

int					deal_move(void *mlx);

int					deal_mouse3(int key, int x, int y, void *mlx);

int					deal_mouse2(void *mlx);

int					deal_mouse(void *mlx);

int					deal_key2(int key, void *mlx);

int					deal_move2(int x, int y, void *mlx);

void				fill_pixel(void *mlx, int color, int *x, int *y);

void				fill_color(void *mlx, int i, int *x, int *y);

void				init_fract(void *mlx);

void				init_diff(void *mlx);

void				fract_ol(void *mlx);

void				ft_buttons(void *mlx);

void				threader(void *mlx);

int					get_thread(pthread_t id, void *mlx);

void				ft_usage2(void);

void				ft_usage(void);

void				ft_error(void);

void				ft_error2(void);

#endif
