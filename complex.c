/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:53:47 by aandom            #+#    #+#             */
/*   Updated: 2023/03/09 19:29:31 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_sum(t_complex *z, t_complex *c, t_data *data)
{
	if (data->f_id == 1)
		ft_init_complex(z->z_re + c->z_re, c->z_im + z->z_im, &data->r);
	else
		ft_init_complex(z->z_re + c->z_re, c->z_im + z->z_im, &data->c);
	return ;
}

void	ft_init_complex(double z_re, double z_im, t_complex **num)
{	
	(*num)->z_re = z_re;
	(*num)->z_im = z_im;
	(*num)->value = (z_re * z_re) + (z_im * z_im);
	return ;
}

void	ft_calculate_complex(t_complex *num, t_complex *c, t_data *data)
{
	if (data->f_id == 1)
	{
		ft_init_complex((num->z_re * num->z_re - num->z_im * num->z_im), \
		2 * (num->z_re * num->z_im), &data->r);
		ft_sum(data->r, c, data);
	}
	else if (data->f_id == 3)
	{
		ft_init_complex((num->z_re * num->z_re - num->z_im * num->z_im), \
		2 * fabs(num->z_re * num->z_im) + c->z_im, &data->c);
		ft_sum(data->c, c, data);
	}
	else
	{
		ft_init_complex((num->z_re * num->z_re - num->z_im * num->z_im), \
		2 * (num->z_re * num->z_im), &data->c);
		ft_sum(data->c, c, data);
	}
	return ;
}
