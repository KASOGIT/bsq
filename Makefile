##
## Makefile for Makefile in /home/soto_a/rendu/MUL_2014_fdf
## 
## Made by Kaso Soto
## Login   <soto_a@epitech.net>
## 
## Started on  Mon Nov 10 11:40:59 2014 Kaso Soto
## Last update Sat Oct 15 16:03:23 2016 
##

NAME	= bsq

CC	= gcc

SRC	= bsq.c \
	  parsing_plat.c \
	  search_max_square.c \
	  set_reset_init_on_square.c \
	  print_square.c \
	  get_next_line.c \

OBJ	= $(SRC:.c=.o)

CFLAGS	= -I././include/ -W -Wall -Ofast -O3 -march=native

LDFLAGS	= -L./lib/ -lmy

$(NAME): $(OBJ)
	 $(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

all :	 $(NAME)

clean :
	 rm -f $(OBJ)

fclean : clean
	 rm -f $(NAME)

re: fclean all
