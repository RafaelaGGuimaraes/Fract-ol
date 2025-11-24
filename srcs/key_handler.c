#include "fractol.h"

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	return (0);
}
