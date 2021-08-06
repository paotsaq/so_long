CC			= gcc
HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
AR 			= ar -rcsv
NAME 		= so_long
SRCS		= srcs/parser.c \
			  srcs/utils.c \
			  srcs/main.c

all: $(NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

$(NAME): libft.a
	$(CC) $(CFLAGS) -L. -l ft -I $(HDRS) $(SRCS) -o $(NAME)


clean:
	rm $(NAME)

re: clean all

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED
