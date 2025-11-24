#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_vars;

typedef struct s_fractal
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;
	int max_iter;
}	t_fractal;

// Funções gerais
int		close_window(t_vars *vars);
int		key_handler(int keycode, t_vars *vars);
void	put_pixel(t_vars *vars, int x, int y, int color);

// Funções do fractal
void	draw_mandelbrot(t_vars *vars, t_fractal *fractal);

#endif
