NAME		=	so_long
#
LIBFT_PATH	=	libft
PREF_S 		=	src/
PREF_OBJ 	=	obj/
#
HF_DIR 		=	hf
HEADER 		=	-I $(HF_DIR)
#
SRCS_SL 	=	so_long
SRCS_FIL 	=	fills
SRCS_SIZE 	=	sizes
SRCS_MPC 	=	map_parse_checker
SRCS_PHS 	=	phs_use
SRCS_MOVE 	=	move
SRCS_WINS 	=	wins
#
SRCSL		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_SL)))
SRCFIL		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_FIL)))
SRCSIZE		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_SIZE)))
SRCMPC		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_MPC)))
SRCPHS		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_PHS)))
SRCMOVE		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_MOVE)))
SRCWINS		=	$(addprefix $(PREF_S), $(addsuffix .c, $(SRCS_WINS)))
#
OBJSL		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_SL)))
OBJFIL		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_FIL)))
OBJSIZE		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_SIZE)))
OBJMPC		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_MPC)))
OBJPHS		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_PHS)))
OBJMOVE		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_MOVE)))
OBJWINS		=	$(addprefix $(PREF_OBJ), $(addsuffix .o, $(SRCS_WINS)))
#
CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra
MLX_FLAGS 	=	-lmlx -framework OpenGL -framework AppKit
#
FSANITIZE	=	-fsanitize=address -g3
#
OBJF		=	.done
#
all:		add $(NAME)
#
$(NAME):	$(OBJSL) $(OBJFIL) $(OBJSIZE) $(OBJMPC) $(OBJWINS) $(OBJPHS) $(OBJMOVE) $(OBJF)
				@$(CC) $(FLAGS) $(FSANITIZE) $(MLX_FLAGS) $(OBJSL) $(OBJFIL) $(OBJWINS) $(OBJSIZE) $(OBJMPC) $(OBJPHS) $(OBJMOVE) $(HEADER) $(LIBFT_PATH)/libft.a -o $@
				@echo "Executable file $(NAME) created successfully!"
#
$(PREF_OBJ)%.o:	$(PREF_S)%.c $(OBJF)
				@$(CC) $(FLAGS) $(FSANITIZE) $(HEADER) -I./mlx-linux -Imlx_linux -O3 -c $< -o $@
#
$(OBJF):
				@mkdir -p $(PREF_OBJ)
				@touch $(OBJF)
#
add:
				@make -C $(LIBFT_PATH)
#
clean:
				@rm -rf $(PREF_OBJ)
				@rm -f $(OBJF)
				@$(MAKE) -C $(LIBFT_PATH) clean
#
fclean:			clean
				@rm -f $(NAME)
				@rm -f $(LIBFT_PATH)/libft.a
#
re:				fclean all
#
.PHONY:	all add lean fclean re bonus
