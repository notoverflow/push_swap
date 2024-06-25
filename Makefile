NAME = push_swap

libft = libft/

libft_a = $(addprefix $(libft), libft.a)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror
SRCS	= function.c list.c push_swap.c func.c index.c

OBJECTS	=	$(SRCS:.c=.o)
all:		$(NAME)
$(NAME):	$(OBJECTS) $(libft_a)
		$(CC) $(CFLAGS) $(OBJECTS) $(libft_a) -o $(NAME)
$(libft_a):
	make -s -C $(libft)
clean:
		rm -f $(OBJECTS)
		make -C $(libft) clean


fclean: clean
		rm -f $(NAME)
		make -C $(libft) clean


re:		fclean all

.PHONY: clean fclean re all