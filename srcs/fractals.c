#include "../includes/fractol.h"

int	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		tmp = 2.0 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		++i;
	}
	return (i);
}

int	julia(t_fractol *f, double zr, double zi, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		tmp = 2.0 * zr * zi + f->j_ci;
		zr = zr * zr - zi * zi + f->j_cr;
		zi = tmp;
		++i;
	}
	return (i);
}
