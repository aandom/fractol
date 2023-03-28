/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:21:15 by aandom            #+#    #+#             */
/*   Updated: 2023/03/13 21:56:25 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(char *name, char *par1, char *par2)
{
	double	real;
	double	im;

	real = ft_atof(par1);
	im = ft_atof(par2);
	ft_set_window(name, 1, real, im);
}

void	print_error(int code)
{
	write(2, "\033[0;33m", 8);
	if (code == 1)
		write(2, "ERROR: Invalid number of arguments...\n", 39);
	else if (code == 2)
	{
		write(2, "ERROR: Invalid number of argument\n", 35);
		write (2, "Mandelbrot/Burningship doesn't take extra Arguments\n", 53);
	}
	else if (code == 3)
		write(2, "ERROR: Invalid option for Julia,\tValid input [-2  2] \n", 55);
	else if (code == 4)
	{
		write(2, "ERROR: Invalid number of argument for Julia\n", 45);
		write(2, "Usage: \t./fractol Julia [opion1] [option2]\n", 44);
		exit(1);
	}
	else
		write(2, "ERROR: Wrong_Name...\n", 22);
	write(2, "\n\n\nUsage: ./fractol <name> \n", 29);
	write(2, "<name>: [Mandelbrot / Julia / Burningship]\n\n", 45);
	write(2, "For Julia...\nUsage: ./fractol Julia [option1] [option2] \n", 58);
	exit (1);
}

void	check_param(char **av, int ac)
{
	if (ac == 2 && (check_fractal(av[1], "Mandelbrot") == 0))
		mandelbrot(av[1]);
	else if (ac == 2 && (check_fractal(av[1], "Burningship") == 0))
		burningship(av[1]);
	else if (ac >= 2 && (check_fractal(av[1], "Mandelbrot") == 0))
		print_error(2);
	else if (ac >= 2 && (check_fractal(av[1], "Burningship") == 0))
		print_error(2);
	else if (ac == 4 && (check_fractal(av[1], "Julia") == 0))
	{
		if (!is_valid_julia(av[2], av[3]))
			print_error(3);
		julia(av[1], av[2], av[3]);
	}
	else if (ac < 4 && (check_fractal(av[1], "Julia") == 0))
		print_error(4);
	else
		print_error(5);
}

int	main(int ac, char **av)
{
	if (ac >= 2 && ac <= 4)
		check_param(av, ac);
	else
		print_error(1);
	return (0);
}
