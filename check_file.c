
#include "fdf.h"

void	print_error_type(char *type)
{
	ft_putstr(type);
	exit(EXIT_FAILURE);
}

int		**write_tab(int **tab, t_var *var, char *argv)
{
	int x;
	int y;

	x = 0;
	var->file = open(argv, O_RDONLY);
	while ((get_next_line(var->file, &var->line) > 0) && x < var->nb_line)
	{
		y = 0;
		var->line_split = ft_strsplit(var->line, ' ');
		while (y < var->len_line)
		{
			tab[x][y] = ft_atoi(var->line_split[y]);
			y++;
		}
		x++;
	}
	close(var->file);
	return (tab);
}

int		**get_tab(int nb_line, int len_line)
{
	int **tab;
	int index;

	index = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nb_line + 1)))
		print_error_type("Error : Dynamic table allocation problem.\n");
	while (index < nb_line)
	{
		if (!(tab[index] = (int *)malloc(sizeof(int) * len_line + 1)))
			print_error_type("Error : Dynamic table allocation problem.\n");
		index++;
	}
	tab[index] = NULL;
	return (tab);
}

int		get_len_line_split(char **line_split)
{
	int index;

	index = 0;
	while (line_split[index])
		index++;
	return (index);
}

int		check_file(t_var *var, char *argv)
{
	var->nb_line = 0;
	var->len_line = 0;
	var->len_cmp = 0;
	var->file = open(argv, O_RDONLY);
	while ((get_next_line(var->file, &var->line)) > 0)
	{
		var->line_split = ft_strsplit(var->line, ' ');
		if (!var->len_cmp)
			var->len_cmp = get_len_line_split(var->line_split);
		var->len_line = get_len_line_split(var->line_split);
		if (var->len_line != var->len_cmp)
			print_error_type("Error : Invalid map.\n");
		var->nb_line++;
	}
	close(var->file);
	var->tab = get_tab(var->nb_line, var->len_line);
	var->tab = write_tab(var->tab, var, argv);
	return (0);
}
