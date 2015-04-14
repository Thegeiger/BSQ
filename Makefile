##
## Makefile for make in /home/geiger_a/rendu/MY_LS
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Sun Nov 23 15:17:22 2014 anthony geiger
## Last update Tue Dec 23 10:39:11 2014 anthony geiger
##

CC	= gcc

RM      = rm -f

NAME    = bsq

CFLAGS  += -Wextra -Wall
CFLAGS  += -pedantic
CFLAGS  += -I.

LDFLAGS =

SRCS    = my_putnbr.c \
        my_putstr.c \
	final_aff.c \
	my_algo.c \
	my_argv_gest.c \
	get_next_line.c \
	bsq.c \
        my_putchar.c

OBJS    = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
