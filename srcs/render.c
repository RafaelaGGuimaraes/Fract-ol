#include "../includes/fractol.h"

static void	compute_pixel(t_fractol *f, int x, int y)
{
	double	pr;
	double	pi;
	int		iter;

	pr = f->min_r + (double)x * (f->max_r - f->min_r) / (double)WIDTH;
	pi = f->max_i + (double)y * (f->min_i - f->max_i) / (double)HEIGHT;
	if (f->set == MANDELBROT)
		iter = mandelbrot(pr, pi, f->max_iter);
	else
		iter = julia(f, pr, pi, f->max_iter);
	put_pixel(f, x, y, f->palette[iter]);
}

void	render(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win,
		f->img, 0, 0);
}
