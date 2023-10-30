# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:21:42 by rboudwin          #+#    #+#              #
#    Updated: 2023/10/30 11:59:11 by rboudwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c	\
	   ft_isalpha.c	\
	   ft_isascii.c	\
	   ft_isdigit.c	\
	   ft_isprint.c	\
   	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c	\
	   ft_memcpy.c	\
	   ft_memmove.c	\
	   ft_memset.c	\
	   ft_putchar_fd.c \
   	   ft_putendl_fd.c \
   	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
   	   ft_strlcat.c \
	   ft_strlcpy.c	\
	   ft_strjoin.c	\
	   ft_strrchr.c \
   	   ft_strlen.c \
	   ft_strchr.c	\
	   ft_strdup.c	\
	   ft_striteri.c \
   	   ft_strnstr.c \
	   ft_strncmp.c \
	   ft_strmapi.c	\
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_toupper.c \
	   ft_tolower.c 

OBJS = $(SRCS:.c=.o)

EXEC = libft.a

all: $(EXEC)

$(EXEC) : $(OBJS)
	ar -rc $(EXEC) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
