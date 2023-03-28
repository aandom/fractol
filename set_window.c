/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:44:56 by aandom            #+#    #+#             */
/*   Updated: 2023/03/13 21:58:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*ft_init_win(char *name)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free (data);
		return (NULL);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, name);
	data->img = mlx_new_image (data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->win_ptr || !data->img)
	{
		ft_clean(data);
		return (NULL);
	}
	return (data);
}

void	ft_set_window(char *name, int f_id, double x, double y)
{
	t_data	*data;

	data = ft_init_win(name);
	data->c = (t_complex *) malloc(sizeof(t_complex));
	data->r = (t_complex *) malloc(sizeof(t_complex));
	data->f_id = f_id;
	data->scale = 1;
	data->v = 0;
	data->h = 0;
	mlx_mouse_hook(data->win_ptr, zoom_fract, data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_hook(data->win_ptr, 17, 0, ft_clean, data);
	data->x = x;
	data->y = y;
	data->addr = mlx_get_data_addr(data->img, &data->var.b_p_p, \
	&data->var.s_line, &data->var.endian);
	if (!data->addr)
		ft_clean(data);
	ft_draw_fractal(data);
	mlx_loop(data->mlx_ptr);
	free(data->r);
	free(data->c);
}

void	mandelbrot(char *name)
{
	ft_set_window(name, 0, 0, 0);
}

void	burningship(char *name)
{
	ft_set_window(name, 3, 0, 0);
}
