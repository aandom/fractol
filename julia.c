/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:53:44 by aandom            #+#    #+#             */
/*   Updated: 2023/03/13 21:28:33 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_julia(char *a, char *b)
{
	if (!*a || !*b)
		return (0);
	if ((ft_atof(a) >= 2.0 || ft_atof(a) <= -2.0) || \
	(ft_atof(b) >= 2.0 || ft_atof(b) <= -2.0))
		return (0);
	else
		return (1);
}

int	set_sign(char c, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	skipspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

double	afterpoint(char *str)
{
	float	m;
	double	res;
	int		i;

	m = 0.1;
	res = 0;
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res + ((float )((str[i] - '0') * m));
		m = m * 0.1;
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		print_error(3);
	return (res);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	int		i;

	sign = 1;
	res = 0;
	i = skipspace(str);
	i = i + set_sign(str[i], &sign);
	if (str[i] == '\0' || (!ft_isdigit(str[i]) && str[i] != '.'))
		return (7);
	while (str[i] && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
		return (res * sign);
	if (str[i] && str[i] != '.')
		return (7);
	i++;
	if (str[i])
		res = res + afterpoint(str + i);
	return (res * sign);
}
