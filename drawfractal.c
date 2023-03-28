/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:14 by aandom            #+#    #+#             */
/*   Updated: 2023/03/13 21:43:29 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_loop(t_complex *num, t_complex *c, t_data *data)
{
	int	iter;

	if (!c || !num)
		return (-1);
	iter = 0;
	while (iter < 100)
	{
		ft_calculate_complex(num, c, data);
		if ((data->f_id == 1) && data->r->value >= 4)
			break ;
		else if ((data->f_id == 0 || data->f_id == 3) && data->c->value >= 4)
			break ;
		iter++;
	}
	return (iter);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	data->pos = (y * data->var.s_line + x * (data->var.b_p_p / 8));
	dst = data->addr + data->pos;
	*(unsigned int *)dst = color;
}

void	ft_draw_cordinate(double x, double y, t_data *data)
{
	int		iteration;
	double	real;
	double	im;

	if (data->f_id == 3)
		im = (-2 + (4.0 / (700)) * (y + data->v * data->scale)) / data->scale;
	else
		im = (2 - (4.0 / (700)) * (y + data->v * data->scale)) / data->scale;
	real = (-2 + (4.0 / (700)) * (x + data->h * data->scale)) / data->scale;
	ft_init_complex(real, im, &data->r);
	ft_init_complex(data->x, data->y, &data->c);
	if (data->f_id == 1)
		iteration = ft_check_loop(data->r, data->c, data);
	else
		iteration = ft_check_loop(data->c, data->r, data);
	if (iteration == -1)
		ft_clean(data);
	else if (iteration >= 100)
		my_mlx_pixel_put(data, x, y, 0x000000);
	else
		my_mlx_pixel_put(data, x, y, ((iteration >> 4) * 0x31104a));
}

void	ft_draw_fractal(t_data *data)
{
	double	y;
	double	x;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			ft_draw_cordinate(x, y, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
