# Variables
NAME = so_long
BONUS_NAME = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I include -I mlx -I src/get_next_line
MLX = mlx/libmlx.a
SRCDIR = src
OBJDIR = obj

# Manually specify source files
SRCS = $(SRCDIR)/solong_mandotary/init.c \
       $(SRCDIR)/solong_mandotary/render.c \
       $(SRCDIR)/solong_mandotary/utils.c \
	   $(SRCDIR)/solong_mandotary/map.c \
	   $(SRCDIR)/solong_mandotary/check.c \
       $(SRCDIR)/get_next_line/get_next_line.c \
       $(SRCDIR)/get_next_line/get_next_line_utils.c\
	   $(SRCDIR)/get_next_line/ft_printf.c

SRCS_BONUS = $(SRCDIR)/solong_bonus/init.c \
             $(SRCDIR)/solong_bonus/render.c \
             $(SRCDIR)/solong_bonus/utils.c \
			 $(SRCDIR)/solong_bonus/player_move.c \
			 $(SRCDIR)/solong_bonus/player_animation.c \
			 $(SRCDIR)/solong_bonus/map.c \
			 $(SRCDIR)/solong_bonus/enemy.c \
			 $(SRCDIR)/solong_bonus/events.c \
			 $(SRCDIR)/solong_bonus/check.c \
             $(SRCDIR)/get_next_line/get_next_line.c \
             $(SRCDIR)/get_next_line/get_next_line_utils.c\
			 $(SRCDIR)/get_next_line/ft_printf.c

# Manually specify object files
OBJS = $(OBJDIR)/solong_mandotary/init.o \
       $(OBJDIR)/solong_mandotary/render.o \
       $(OBJDIR)/solong_mandotary/utils.o \
	   $(OBJDIR)/solong_mandotary/map.o \
	   $(OBJDIR)/solong_mandotary/check.o \
       $(OBJDIR)/get_next_line/get_next_line.o \
       $(OBJDIR)/get_next_line/get_next_line_utils.o\
	   $(OBJDIR)/get_next_line/ft_printf.o

OBJS_BONUS = $(OBJDIR)/solong_bonus/init.o \
             $(OBJDIR)/solong_bonus/render.o \
             $(OBJDIR)/solong_bonus/utils.o \
			 $(OBJDIR)/solong_bonus/player_move.o \
			 $(OBJDIR)/solong_bonus/player_animation.o \
			 $(OBJDIR)/solong_bonus/map.o \
			 $(OBJDIR)/solong_bonus/enemy.o \
			 $(OBJDIR)/solong_bonus/events.o \
			 $(OBJDIR)/solong_bonus/check.o \
             $(OBJDIR)/get_next_line/get_next_line.o \
             $(OBJDIR)/get_next_line/get_next_line_utils.o\
			 $(OBJDIR)/get_next_line/ft_printf.o

# Rules
all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(MLX) -lm -lX11 -lXext

bonus: $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS_NAME) $(OBJS_BONUS) $(MLX) -lm -lX11 -lXext

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) $(OBJDIR)/get_next_line $(OBJDIR)/solong_mandotary $(OBJDIR)/solong_bonus
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	$(MAKE) -C mlx

clean:
	$(MAKE) -C mlx clean
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
