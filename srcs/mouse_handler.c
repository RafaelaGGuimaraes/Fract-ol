#include "fractol.h"

static void	apply_zoom(t_fractal *f, int x, int y, double zoom)
{
	double	mouse_re;
	double	mouse_im;

	// Converter pixel para coordenada complexa
	mouse_re = f->x_min + (double)x / WIDTH * (f->x_max - f->x_min);
	mouse_im = f->y_min + (double)y / HEIGHT * (f->y_max - f->y_min);

	// Aproximar limites do ponto do mouse
	f->x_min = mouse_re + (f->x_min - mouse_re) * zoom;
	f->x_max = mouse_re + (f->x_max - mouse_re) * zoom;
	f->y_min = mouse_im + (f->y_min - mouse_im) * zoom;
	f->y_max = mouse_im + (f->y_max - mouse_im) * zoom;
}

int	mouse_handler(int button, int x, int y, void *param)
{
	t_vars		*vars;
	t_fractal	*f;

	vars = ((t_vars **)param)[0];
	f = ((t_fractal **)param)[1];

	if (button == 4) // scroll up: zoom in
		apply_zoom(f, x, y, 0.9);
	else if (button == 5) // scroll down: zoom out
		apply_zoom(f, x, y, 1.1);
	else
		return (0);

	draw_mandelbrot(vars, f);
	return (0);
}
