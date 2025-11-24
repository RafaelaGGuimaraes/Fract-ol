#include "fractol.h"

void	draw_pixels(t_vars *vars)
{
	int	x;
	int	y;

	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img,
			&vars->bits_per_pixel, &vars->line_length, &vars->endian);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// Teste: degradê simples
			put_pixel(vars, x, y, (x * 255 / WIDTH) << 16 | (y * 255 / HEIGHT) << 8);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
