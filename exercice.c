/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:26:52 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/05/15 16:33:39 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_macos/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_struct;

void line(t_struct *key)
{	 
	int dx = abs(key->x1 - key->x0), sx = key->x0 < key->x1 ? 1 : -1;
	int dy = abs(key->y1 - key->y0), sy = key->y0 < key->y1 ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2, e2;

	for(;;)
	{
		mlx_pixel_put(key->mlx, key->win, key->x0, key->y0, 0x00FF00);
		if (key->x0 == key->x1 && key->y0 == key->y1) 
			break;
		e2 = err;
		if (e2 >-dx) 
		{ 
			err -= dy; key->x0 += sx;
		}
		if (e2 < dy) 
		{
			err += dx; key->y0 += sy;
		}
	}
}

int		ft_key_function(int keycode)
{	
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit (0);
	return (0);
}

void	draw(t_struct *key)
{
	if (key->y0 == 300 && key->x0 == 300)
	{
		key->y0 = 100;
		while (key->y0 < 300)
		{
			key->x0 = 300;
			while (key->x0 < 500)
			{
				mlx_pixel_put(key->mlx, key->win, key->x0, key->y0, 0x00FF00);
				key->x0++;
			}
			key->y0++;
		}
	}
	else
	{
		key->y0 = 100;
		while (key->y0 < 300)
		{
			key->x0 = 100;
			while (key->x0 < 300)
			{
				mlx_pixel_put(key->mlx, key->win, key->x0, key->y0, 0xFF00FF);
				key->x0++;
			}
			key->y0++;
		}
	}
}

int		mouse_hook(int button, int x, int y, t_struct *key)
{
	printf("mouse %d (%d:%d)\n", button, x, y);
	if (button == 1)
		draw(key);
	if (button == 2)
		mlx_clear_window(key->mlx, key->win);
	return (0);
}

/*int		expose_hook(t_struct *key)
  {
  return (0);
  }*/

int		main()
{
	t_struct	key;

	key.mlx = mlx_init();
	key.win = mlx_new_window(key.mlx, 800, 600, "first window");
	mlx_key_hook(key.win, ft_key_function, 0);
	//	mlx_expose_hook(key.win, expose_hook, &key);
	mlx_mouse_hook(key.win, mouse_hook, &key);
	mlx_loop(key.mlx);
	return (0);
}
