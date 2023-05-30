NAME		=	so_long
#NAME_BONUS 	=	so_long_bonus
#
LIBFT_PATH	=	libft
PREF_S 		=	src/
PREF_OBJ 	=	obj/
#
HF_DIR 		=	hf
HEADER 		=	-I $(HF_DIR)
MLX_PATH 	=	mlx-linux
#
SRCS_SL 	=	so_long
SRCS_FIL 	=	fills
SRCS_SIZE 	=	sizes
SRCS_MPC 	=	map_parse_checker
SRCS_PHS 	=	phs_use
SRCS_MOVE 	=	move
#
SRCSL		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_SL)))
SRCFIL		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_FIL)))
SRCSIZE		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_SIZE)))
SRCMPC		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_MPC)))
SRCPHS		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_PHS)))
SRCMOVE		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_MOVE)))
#
OBJSL		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_SL)))
OBJFIL		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_FIL)))
OBJSIZE		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_SIZE)))
OBJMPC		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_MPC)))
OBJPHS		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_PHS)))
OBJMOVE		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_MOVE)))
#
CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra
MLX_FLAGS 	=	-Lmlx_linux -lmlx_Linux -L./mlx-linux -Imlx_linux -lXext -lX11 -lm -lz
#
FSANITIZE	=	-fsanitize=address -g3
#
OBJF		=	.done
#
all:		add $(NAME)
#
$(NAME):	$(OBJSL) $(OBJFIL) $(OBJSIZE) $(OBJMPC) $(OBJPHS) $(OBJMOVE) $(OBJF)
				@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJSL) $(OBJFIL) $(OBJSIZE) $(OBJMPC) $(OBJPHS) $(OBJMOVE) $(HEADER) $(MLX_PATH)/libmlx.a $(LIBFT_PATH)/libft.a -o $@
#
$(PREF_OBJ)%.o:	$(PREF_S)%.c $(OBJF)
				@$(CC) $(FLAGS) $(HEADER) -I./mlx-linux -Imlx_linux -O3 -c $< -o $@
#
$(OBJF):
				@mkdir -p $(PREF_OBJ)
				@touch $(OBJF)
#
add:
				make -C $(MLX_PATH)
				make -C $(LIBFT_PATH)
#
clean:
				@rm -rf $(PREF_OBJ)
				@rm -f $(OBJF)
				@$(MAKE) -C $(LIBFT_PATH) clean
				@$(MAKE) -C $(MLX_PATH) clean
#
fclean:			clean
				@rm -f $(NAME)
				@rm -f $(LIBFT_PATH)/libft.a
#
re:				fclean all
#
.PHONY:	all add lean fclean re bonus
