#include "../includes/fractol.h"

static void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	print_help(void)
{
	ft_putendl_fd("====================================", 1);
	ft_putendl_fd("        FRACT-OL — HELP MENU        ", 1);
	ft_putendl_fd("====================================", 1);
	ft_putendl_fd("Uso:", 1);
	ft_putendl_fd("  ./fractol mandelbrot", 1);
	ft_putendl_fd("  ./fractol julia <real> <imag>", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Exemplos:", 1);
	ft_putendl_fd("  ./fractol 'mandelbrot'/'m'/'M'", 1);
	ft_putendl_fd("  ./fractol 'julia'/'j'/'J' -0.8 0.156", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Controles:", 1);
	ft_putendl_fd("  Scroll     → Zoom", 1);
	ft_putendl_fd("  WASD       → Mover", 1);
	ft_putendl_fd("  ESC        → Sair", 1);
	ft_putendl_fd("====================================", 1);
}
