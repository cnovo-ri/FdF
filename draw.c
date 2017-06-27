
#include "fdf.h"

int		line_put(t_var var, int x, int y)
{
	if (x > 0 && y > 0 && x < SCREEN_X && y < SCREEN_Y)
	{
		if ((var.z1 > 0 && var.z1 <= 10) || (var.z2 > 0 && var.z2 <= 10))
		{
			var.var[(y * var.size_line) + (x * (var.bpp / 8))] = -var.b;
			var.var[(y * var.size_line) + (x * (var.bpp / 8)) + 1] = -var.g;
			var.var[(y * var.size_line) + (x * (var.bpp / 8)) + 2] = -var.r;
		}
		else
		{
			var.var[(y * var.size_line) + (x * (var.bpp / 8))] = var.b;
			var.var[(y * var.size_line) + (x * (var.bpp / 8)) + 1] = var.g;
			var.var[(y * var.size_line) + (x * (var.bpp / 8)) + 2] = var.r;
		}
	}
	return (0);
}

int			draw_line(t_var var)
{
	int x;
	int y;

	var.dx = var.x2 - var.x1;
	var.dy = var.y2 - var.y1;
	if (var.flag == 1)
	{
		x = var.x1;
		while (x <= var.x2 && var.dx > 0)
		{
			y = var.y1 + var.dy * (x - var.x1) / var.dx;
			line_put(var, y + var.pos_x, x + var.pos_y);
			x++;
		}
		return (0);
	}
	y = var.y1;
	while (y <= var.y2 && var.dy > 0)
	{
		x = var.x1 + var.dx * (y - var.y1) / var.dy;
		line_put(var, y + var.pos_x, x + var.pos_y);
		y++;
	}
	return (0);
}

void	converting_coord(t_var *var)
{
	var->x1 *= var->space;
	var->y1 *= var->space;
	var->x2 *= var->space;
	var->y2 *= var->space;
	var->x1 += var->z1;
	var->y1 += var->z1;
	var->x2 += var->z2;
	var->y2 += var->z2;
	var->x2 += var->z;
	var->y2 += var->z;
}

int		line_tab_x(t_var var)
{
	int x;
	int y;

	x = 0;
	while (x < var.nb_line)
	{
		y = 0;
		while (y < var.len_line)
		{
			var.z1 = var.tab[x][y];
			var.z2 = ((y + 1) < var.len_line) ? var.tab[x][y + 1] : var.z1;
			var.x1 = x;
			var.y1 = y;
			var.x2 = x;
			var.y2 = ((y + 1) < var.len_line) ? y + 1 : y;
			converting_coord(&var);
			draw_line(var);
			y++;
		}
		x++;
	}
	line_tab_y(var);
	return (0);
}

int		line_tab_y(t_var var)
{
	int x;
	int y;
	
	y = 0;
	var.flag = 1;
	while (y < var.len_line)
	{
		x = 0;
		while (x < var.nb_line)
		{
			var.z1 = var.tab[x][y];
			var.z2 = ((x + 1) < var.nb_line) ? var.tab[x + 1][y] : var.z1;
			var.x1 = x;
			var.y1 = y;
			var.x2 = ((x + 1) < var.nb_line) ? x + 1 : x;
			var.y2 = y;
			converting_coord(&var);
			draw_line(var);
			x++;
		}
		y++;
	}
	return (0);
}
