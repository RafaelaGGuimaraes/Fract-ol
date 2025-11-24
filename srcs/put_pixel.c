#include "fractol.h"

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*pixel;

	pixel = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(int *)pixel = color;
}
