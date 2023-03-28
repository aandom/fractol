/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:20:48 by aandom            #+#    #+#             */
/*   Updated: 2023/03/13 21:56:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "mlx/mlx.h"
# include <unistd.h>
# include <math.h>
# define WIDTH 700
# define HEIGHT 700

typedef struct s_complex
{
	double	z_re;
	double	z_im;
	double	value;
}	t_complex;

typedef struct s_param {
	int	b_p_p;
	int	s_line;
	int	endian;
}	t_param;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			f_id;
	int			v;
	int			h;
	double		scale;
	double		x;
	double		y;
	int			pos;
	t_param		var;
	t_complex	*r;
	t_complex	*c;
}			t_data;

t_data	*ft_init_win(char *name);
void	ft_set_window(char *name, int f_id, double x, double y);
void	mandelbrot(char *name);
void	burningship(char *name);
void	ft_sum(t_complex *z, t_complex *c, t_data *data);
void	ft_init_complex(double z_re, double z_im, t_complex **num);
void	ft_calculate_complex(t_complex *num, t_complex *c, t_data *data);
size_t	ft_strlen(char *s);
int		check_fractal(char *str, char *fractal);
void	julia(char *name, char *par1, char *par2);
double	ft_atof(char *str);
int		set_sign(char c, int *sign);
int		ft_isdigit(int c);
int		is_valid_julia(char *a, char *b);
int		ft_check_loop(t_complex *num, t_complex *c, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_cordinate(double x, double y, t_data *data);
void	ft_draw_fractal(t_data *data);
int		zoom_fract(int scroll, int x, int y, t_data *data);
int		key_handler(int key, t_data *data);
int		ft_clean(t_data *data);
void	print_error(int code);

#endif