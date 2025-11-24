#include "fractol.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");

	draw_pixels(&vars);

	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_handler, &vars);

	mlx_loop(vars.mlx);
	return (0);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 800, 600, "fract-ol");

// 	mlx_hook(vars.win, 17, 0, close_window, &vars);  // X da janela
// 	mlx_key_hook(vars.win, key_handler, &vars);       // ESC

// 	mlx_loop(vars.mlx);
// 	return (0);
// }