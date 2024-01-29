NAME	:= push_swap 
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
SRCS	:= main.c \
		   push_swap.c \
		   ps_actions.c \
		   ps_actions2.c \
		   ps_actions3.c \
		   choose_push.c \
		   choose_push_utils.c \
		   smart_rotate.c \
		   tools.c \
		   tools2.c
OBJS	:= ${SRCS:.c=.o} Libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) -o $(NAME)

Libft/libft.a: 
	$(MAKE) -C Libft/ all
	$(MAKE) -C Libft/ bonus

clean:
	@rm -rf $(OBJS)
	rm -f Libft/.bonus;
	$(MAKE) -C Libft/ clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re 
