NAME = mlxtest
SRCS = mlxtest.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LMLXF = -Lmlx_linux -lmlx_Linux -L./mlx-linux -Imlx_linux -lXext -lX11 -lm -lz
# LIBMLX = ./mlx-linux/libmlx_Linux.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./mlx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LMLXF) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re 
