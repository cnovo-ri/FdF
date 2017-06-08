
#include "fdf.h"

int		draw_vertical_line(t_var var)
{
	int dx;
	int dy;
	int x;
	int y;

	x = var.x1;
	dx = var.x2 - var.x1;
	dy = var.y2 - var.y1;
	while (x <= var.x2 && dx > 0)
	{
		y = var.y1 + dy * (x - var.x1) / dx;
		line_put(var, y + var.pos_x, x + var.pos_y);
		x++;
	}
	return (0);
}

int		draw_horizontal_line(t_var var)
{
	int dx;
	int dy;
	int x;
	int y;

	y = var.y1;
	dx = var.x2 - var.x1;
	dy = var.y2 - var.y1;
	while (y <= var.y2 && dy > 0)
	{
		x = var.x1 + dx * (y - var.y1) / dy;
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
//	int z;

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
			displine(&var);
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
//	int z;

	y = 0;
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
			displine(&var);
			x++;
		}
		y++;
	}
	return (0);
}
