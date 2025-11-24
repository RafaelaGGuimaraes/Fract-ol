# ===============================
#        CONFIGURAÇÃO
# ===============================

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/close_window.c \
       $(SRCDIR)/key_handler.c \
       $(SRCDIR)/draw_image.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I includes -I $(MLX_DIR)

# ===============================
#          REGRAS
# ===============================

all: $(MLX) $(NAME)

# Compila o projeto
$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

# Compila arquivos do srcs
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Baixa a MLX se não existir
$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@if [ ! -f $(MLX) ]; then \
		$(MAKE) -C $(MLX_DIR); \
	fi

# Limpa objetos do projeto e da MLX
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean || true

# Limpa tudo (executável + objetos + lib da MLX)
fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

# Recompila tudo do zero
re: fclean all

.PHONY: all clean fclean re
