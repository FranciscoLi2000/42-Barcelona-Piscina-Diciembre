CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SRCS = ft_display_file.c

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
		@rm -f *.o

fclean: clean
		@rm -f $(NAME)

.PHONY: all clean fclean
