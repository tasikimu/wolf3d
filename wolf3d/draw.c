/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:07:47 by tasikimu          #+#    #+#             */
/*   Updated: 2018/09/17 13:51:24 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_colors(t_colours *c, int red, int green, int blue)
{
	c->red = red;
	c->green = green;
	c->blue = blue;
}

static void	mlx_image_put_pixel(void *mlx, t_img *i, t_coordint p, t_colours *c)
{
	if (i->e)
	{
		i->d[p.y * i->s + p.x * i->bp / 8] =
			mlx_get_color_value(mlx, c->red);
		i->d[p.y * i->s + p.x * i->bp / 8 + 1] =
			mlx_get_color_value(mlx, c->green);
		i->d[p.y * i->s + p.x * i->bp / 8 + 2] =
			mlx_get_color_value(mlx, c->blue);
	}
	else
	{
		i->d[p.y * i->s + i->bp / 8 * p.x] =
			mlx_get_color_value(mlx, c->blue);
		i->d[p.y * i->s + i->bp / 8 * p.x + 1] =
			mlx_get_color_value(mlx, c->green);
		i->d[p.y * i->s + i->bp / 8 * p.x + 2] =
			mlx_get_color_value(mlx, c->red);
	}
}

void		drawline(int x, t_env *e, t_colours *c)
{
	t_coordint		p;
	t_colours		skyfloor;

	p.x = x;
	e->img.d = mlx_get_data_addr(e->img.img, &e->img.bp, &e->img.s, &e->img.e);
	set_colors(&skyfloor, 20, 150, 250);
	p.y = 0;
	while (p.y < e->r.ystart)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
	p.y = e->r.ystart;
	while (p.y < e->r.yend)
	{
		mlx_image_put_pixel(e, &(e->img), p, c);
		p.y++;
	}
	set_colors(&skyfloor, 100, 92, 92);
	p.y = e->r.yend;
	while (p.y < WIN_HEIGH)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
}

void		colors(t_env *e, t_colours *c)
{
	if (e->player.wallside == 0)
	{
		if (e->player.step.x < 0)
			set_colors(c, 219, 186, 43);
		else
			set_colors(c, 0, 0, 0);
	}
	else
	{
		if (e->player.step.y < 0)
			set_colors(c, 200, 0, 0);
		else
			set_colors(c, 0, 199, 0);
	}
}
