/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:02:45 by tasikimu          #+#    #+#             */
/*   Updated: 2018/09/17 17:23:40 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static void		readsize(t_env *e, int fd)
{
	int			*size;
	char		*line;

	if (get_next_line(fd, &line) < 1)
	{
		perror("Could not read map size.");
		exit(EXIT_FAILURE);
	}
	size = ft_strsplittoint(line, ' ');
	e->map.sizex = size[0];
	e->map.sizey = size[1];
	free(line);
	free(size);
}

static void		readmap(t_env *e, int fd)
{
	char		*line;
	int			**worldmap;
	int			i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * e->map.sizex);
	if (worldmap == NULL)
	{
		perror("Could not read map.");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	e->map.map = worldmap;
	free(line);
}

void			get_timeframe(t_env *e)
{
	struct timeval time;

	e->oldtime = e->time;
	gettimeofday(&time, NULL);
	e->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	e->frametime = e->time - e->oldtime;
	e->player.mspeed = e->frametime * 0.003;
	e->player.rspeed = e->frametime * 0.005;
}

static void		readfile(t_env *e)
{
	int			fd;
	int			i;

	i = 0;
	if ((fd = open("wolf3d_map", O_RDONLY)) == -1)
	{
		perror("No Map");
		exit(EXIT_FAILURE);
	}
	readsize(e, fd);
	readmap(e, fd);
	close(fd);
}

int				main(void)
{
	t_env		e;

	e.mlx = mlx_init();
	if ((e.mlx = mlx_init()) == NULL)
	{
		perror("mlx: Cannot init mlx");
		exit(EXIT_FAILURE);
	}
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGH, "wolf3d");
	e.img.img = NULL;
	e.player.pos.x = 4;
	e.player.pos.y = 4;
	e.player.dir.x = -1;
	e.player.dir.y = 0;
	e.r.plane.x = 0;
	e.r.plane.y = 0.80;
	e.time = 0;
	e.oldtime = 0;
	readfile(&e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_hook(e.win, 17, 0L, ft_esc, &e);
	mlx_loop(e.mlx);
	return (0);
}
