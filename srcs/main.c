#include "fractol.h"

int	main(void)
{
	t_vars	vars;
	t_fractal fractal;

	// Inicialização MLX
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");

	// Inicialização do fractal Mandelbrot
	fractal.x_min = -2.0;
	fractal.x_max = 1.0;
	fractal.y_min = -1.2;
	fractal.y_max = 1.2;
	fractal.max_iter = 100;

	// Desenhar fractal
	draw_mandelbrot(&vars, &fractal);

	// Hooks
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_handler, &vars);

	mlx_loop(vars.mlx);
	return (0);
}
