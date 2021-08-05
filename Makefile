CC			= gcc
HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
AR 			= ar -rcsv
NAME 		= so_long
SRCS		= srcs/parser.c

## $(NAME): $(OBJ)
	## $(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME):
	$(CC) -I $(HDRS) $(SRCS) -o $(NAME)

all: libft.a

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

clean:
	make clean -C ./libft
	rm -rf ft_*.o

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED
