// #ifndef FRACTOL_H
// # define FRACTOL_H

// # include "mlx.h"
// # include <stdlib.h>

// typedef struct s_vars
// {
//     void    *mlx;
//     void    *win;
// }   t_vars;

// int     close_window(t_vars *vars);
// int     key_handler(int keycode, t_vars *vars);

// #endif

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

int		close_window(t_vars *vars);
int		key_handler(int keycode, t_vars *vars);
void	draw_pixels(t_vars *vars);
void	put_pixel(t_vars *vars, int x, int y, int color);

#endif
