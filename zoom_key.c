/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:57:46 by aandom            #+#    #+#             */
/*   Updated: 2023/03/11 19:42:32 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_clean(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->c);
	free(data->r);
	free(data);
	exit (0);
}

int	key_handler(int key, t_data *data)
{
	if (key == 53)
	{
		ft_clean(data);
		exit (0);
	}
	else if (key == 125)
		data->v -= 5;
	else if (key == 126)
		data->v += 5;
	else if (key == 123)
		data->h += 5;
	else if (key == 124)
		data->h -= 5;
	ft_draw_fractal(data);
	return (0);
}

int	zoom_fract(int scroll, int x, int y, t_data *data)
{
	if (scroll != 4 && scroll != 5)
		return (0);
	if (scroll == 4)
		data->scale *= 1.2;
	else if (scroll == 5)
		data->scale /= 1.2;
	else
	{
		mlx_mouse_get_pos(data->win_ptr, &x, &y);
		(void) x;
		(void) y;
		return (0);
	}
	ft_draw_fractal(data);
	return (0);
}
