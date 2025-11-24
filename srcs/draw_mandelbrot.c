#include "fractol.h"
#include <math.h>

static int	mandelbrot(double c_re, double c_im, int max_iter)
{
	double z_re = 0;
	double z_im = 0;
	int i = 0;
	double z_re2, z_im2;

	while (i < max_iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_vars *vars, t_fractal *f)
{
	int x, y;
	double c_re, c_im;
	int iter;
	int color;

	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img,
			&vars->bits_per_pixel, &vars->line_length, &vars->endian);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// Map pixel para plano complexo
			c_re = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
			c_im = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;

			iter = mandelbrot(c_re, c_im, f->max_iter);

			// Colorir: simples gradiente
			if (iter == f->max_iter)
				color = 0x000000; // preto
			else
				color = (iter * 255 / f->max_iter) << 16 | (iter * 255 / f->max_iter) << 8 | (iter * 255 / f->max_iter);

			put_pixel(vars, x, y, color);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
