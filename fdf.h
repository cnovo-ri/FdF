/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 00:44:50 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/11/01 02:55:07 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>

# define SCREEN_X 1600
# define SCREEN_Y 900
# define KEYPRESS 2
# define KEYPRESSMASK (1L << 0)

typedef struct		s_var
{
	int				dx;
	int				dy;
	int				flag;
	int				nb_line;
	int				len_line;
	int				len_cmp;
	int				file;
	char			*line;
	char			**line_split;
	int				**tab;
	char			*argv;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;
	char			*var;
	int				size_line;
	int				bpp;
	int				endian;
	int				key;
	int				pos_x;
	int				pos_y;
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				space;
	char			r;
	char			g;
	char			b;
	char			z;
}					t_var;

void				print_error_type(char *type);
void				center_img(t_var *var);
int					check_file(t_var *var, char *argv);
int					get_len_line_split(char **line_split);
int					**get_tab(int nb_line, int len_line);
int					**write_tab(int **tab, t_var *var, char *argv);
int					line_tab_x(t_var var);
int					line_tab_y(t_var var);
void				converting_coord(t_var *var);
int					fdf_init(t_var *var);
int					line_put(t_var var, int x, int y);
int					draw_line(t_var var);

#endif
