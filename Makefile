CC			= gcc
HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
AR 			= ar -rcsv
NAME 		= so_long
SRCS		= srcs/parser.c \
			  srcs/utils.c \
			  srcs/main.c \
			  srcs/linked_lists_utils.c \
			  srcs/window.c

MLX_FLAGS	=	 -lmlx -framework OpenGL -framework AppKit
LIBFT_FOLDER =		libft
MINILIBX_FOLDER =	minilibx_mms_20200219

all: $(NAME)

compile_libraries:
	$(MAKE) -C $(LIBFT_FOLDER)
	$(MAKE) -C $(MINILIBX_FOLDER)
	mv $(MINILIBX_FOLDER)/libmlx.dylib .
	mv $(LIBFT_FOLDER)/libft.a .

$(NAME): compile_libraries
	$(CC) $(CFLAGS) $(MLX_FLAGS) -L. -lft -I $(HDRS) $(SRCS) -o $(NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

clean:
	rm $(NAME)

re: clean all

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED
