/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:45:30 by tasikimu          #+#    #+#             */
/*   Updated: 2018/09/07 14:54:41 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIN_WIDTH 1280
# define WIN_HEIGH 720

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_colours
{
	int			red;
	int			green;
	int			blue;
}				t_colours;

typedef struct	s_coordint
{
	int			x;
	int			y;
}				t_coordint;

typedef struct	s_move
{
	int			up;
	int			left;
	int			right;
	int			down;
}				t_move;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		sidedist;
	t_coord		disd;
	t_coordint	posmap;
	int			lheight;
	int			ystart;
	int			yend;
}				t_ray;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coordint	step;
	t_move		move;
	double		rspeed;
	double		mspeed;
	double		hcamera;
	int			hit;
	int			wallside;
	int			sprint;
}				t_player;

typedef struct	s_map
{
	int			**map;
	int			display;
	int			sizex;
	int			sizey;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*d;
	int			bp;
	int			s;
	int			e;
}				t_img;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		r;
	double		time;
	double		oldtime;
	long int	frametime;
}				t_env;

void			get_timeframe(t_env *e);
void			*ft_memalloc(size_t size);
int				expose_hook(t_env *t);
int				loop_hook(t_env *e);
int				key_release(int keycode, t_env *e);
int				key_press(int keycode, t_env *e);
int				ft_esc(t_env *env);
int				*ft_strsplittoint(char const *s, char c);
int				ft_atoi(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlen(const char *s);
void			move(t_env *e);
void			colors(t_env *e, t_colours *c);
void			drawline(int x, t_env *e, t_colours *c);
int				get_next_line(int fd, char **line);

#endif
