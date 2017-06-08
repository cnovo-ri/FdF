
#include "fdf.h"

int		ft_abs(int val)
{
	if (val > 0)
		return (val);
	else
		return (-val);
}

void	center_img(t_var *var)
{
	if (!var->pos_x && !var->pos_y)
	{
		var->pos_x = (SCREEN_X / 2) - (var->len_line * var->space / 2);
		var->pos_y = (SCREEN_Y / 2) - (var->nb_line * var->space / 2);
	}
}

int		line_put(t_var var, int x, int y)
{
	if (x > 0 && y > 0 && x < 1600 && y < 900)
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

void	swap_coord(t_var *var)
{
	int tmp;

	tmp = var->x1;
	var->x1 = var->x2;
	var->x2 = tmp;
	tmp = var->y1;
	var->y1 = var->y2;
	var->y2 = tmp;
}

void	displine(t_var *var)
{
	if (ft_abs(var->x2 - var->x1) >= ft_abs(var->y2 - var->y1))
	{
		if (var->x1 < var->x2)
			draw_vertical_line(*var);
		else
		{
			swap_coord(*(&var));
			draw_vertical_line(*var);
		}
	}
	else
	{
		if (var->y1 < var->y2)
			draw_horizontal_line(*var);
		else
		{
			swap_coord(*(&var));
			draw_horizontal_line(*var);
		}
	}
}
