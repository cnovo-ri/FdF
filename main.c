
#include "fdf.h"

int			cmd_key(int key, t_var *var)
{
	(key == 78) ? var->space -= 1 : var->space;
	(key == 69) ? var->space += 1 : var->space;
	(key == 13) ? var->pos_y -= 50 : var->pos_y;
	(key == 1) ? var->pos_y += 50 : var->pos_y;
	(key == 2) ? var->pos_x += 50 : var->pos_x;
	(key == 0) ? var->pos_x -= 50 : var->pos_x;
	(key == 15) ? var->r += 5 : var->r;
	(key == 5) ? var->g += 5 : var->g;
	(key == 11) ? var->b += 5 : var->b;
	(key == 116) ? var->z += 1 : var->z;
	(key == 121) ? var->z -= 1 : var->z;
	if (key == 53)
		exit(EXIT_SUCCESS);
	mlx_destroy_image(var->mlx, var->img);
	fdf_init(var);
	return (0);
}

int			fdf_init(t_var *var)
{
	check_file(var, var->argv);
	center_img(var);
	var->img = mlx_new_image(var->mlx, SCREEN_X, SCREEN_Y);
	var->var = mlx_get_data_addr(var->img, &var->bpp, &var->size_line,
			&var->endian);
	line_tab_x(*var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	return (0);
}

void		color_init(t_var *var)
{
	var->b = 50;
	var->g = 50;
	var->r = 50;
	var->z = 0;
}

int			main(int argc, char **argv)
{
	t_var	var;
	//int		x;
//	int		y;

	color_init(&var);
	var.argv = argv[1];
	var.space = 35;
	if (argc != 2)
		print_error_type("usage: ./a.out [ Map_missing ]\n");
	else
	{
		var.mlx = mlx_init();
		var.win = mlx_new_window(var.mlx, SCREEN_X, SCREEN_Y, argv[1]);
		fdf_init(&var);
		mlx_hook(var.win, KEYPRESS, KEYPRESSMASK, cmd_key, &var);
		mlx_loop(var.mlx);
	}
	return (0);
}
