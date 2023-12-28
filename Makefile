NAME	:= push_swap
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
HEADERS	:= -I ./Libft
SRCS	:= push_swap.c
OBJS	:= ${SRCS:.c=.o} Libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

Libft/libft.a: 
	$(MAKE) -C libft/ all
	$(MAKE) -C libft/ bonus

clean:
	@rm -rf $(OBJS)
	rm -f libft/.bonus;

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re 
