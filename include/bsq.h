/*
** bsq.h for bsq in /home/soto_a/rendu/CPE_2014_bsq
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Dec 22 19:16:29 2014 Kaso Soto
** Last update Sun Jan 18 19:49:20 2015 Kaso Soto
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my.h"

typedef struct	s_point
{
  int		x;
  int		y;
}		t_point;

typedef struct	s_square
{
  t_point	p1;
  t_point	p2;
}		t_square;

char		**parsing_plat(const char *file_name);
void		check_if_number(char *number);
void		my_empty_file();
t_square	search_max_square(char **plat);
int		check_is_square(char **plat, t_square *square, int size_square);
void		compare_and_set_square(t_square *tmp_s, t_square *s);
int		act_on_square(char **plat, t_square *square, t_square *tmp_square);
void		init_squares(t_square *s1, t_square *s2);
void		reset_tmp_square(t_square *square, t_point pos_plat);
int		reset_on_static(int *j);
void		print_square(char **plat, t_square square, int param);
int		if_litle_square(char c, t_square *square);
void		print_and_reset_pos(char *str, t_point *p);
void		free_plat(char **plat);
void		print_only_pos(t_square square);

#endif /* !BSQ_H_ */
