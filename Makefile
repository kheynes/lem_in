LEM_IN = lem-in

SRCS = lem_in.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(LEM_IN)

$(LEM_IN):
	gcc -Wall -Werror -Wextra -o $(LEM_IN) lem_in.h $(SRCS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(LEM_IN)
	rm -f $(OBJS)

re: fclean libre all

libre:
	make re -C ./libft