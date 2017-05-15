/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:07:03 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/31 18:23:47 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "mlx.h"

int		main()
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "42");
	img = mlx_new_image(mlx, 500, 500);
	mlx_pixel_put(mlx, win, 400, 400, 0x50FFFF);
	mlx_loop(mlx);
}
