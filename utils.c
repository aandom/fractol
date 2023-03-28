/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:35:21 by aandom            #+#    #+#             */
/*   Updated: 2023/03/09 20:17:47 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_fractal(char *str, char *fractal)
{
	if (ft_strlen(str) != ft_strlen(fractal))
		return (1);
	while (*str && *fractal)
	{
		if (*str != *fractal)
			return (1);
		str++;
		fractal++;
	}
	if ((!*str && !*fractal))
		return (0);
	return (1);
}
