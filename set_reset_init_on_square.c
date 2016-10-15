/*
** set_reset_init_on_square.c for reset_set_init_on_square in /home/soto_a/rendu/CPE_2014_bsq
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Dec 26 15:59:36 2014 Kaso Soto
** Last update Sun Jan 18 15:09:00 2015 Kaso Soto
*/

#include "bsq.h"

int	reset_on_static(int *j)
{
  int	save_j;

  save_j = *j;
  *j = 0;
  return (save_j + 1);
}

void    compare_and_set_square(t_square *tmp_s, t_square *s)
{
  int   size_tmp_s;
  int   size_s;

  size_tmp_s = (tmp_s->p2.x - tmp_s->p1.x) + (tmp_s->p2.y - tmp_s->p1.y);
  size_s = (s->p2.x - s->p1.x) + (s->p2.y - s->p1.y);
  if (size_tmp_s > size_s)
    {
      s->p1.x = tmp_s->p1.x;
      s->p1.y = tmp_s->p1.y;
      s->p2.x = tmp_s->p2.x;
      s->p2.y = tmp_s->p2.y;
    }
}

void    init_squares(t_square *s1, t_square *s2)
{
  s1->p1.x = 0;
  s1->p1.y = 0;
  s1->p2.x = 0;
  s1->p2.y = 0;
  s2->p1.x = 0;
  s2->p1.y = 0;
  s2->p2.x = 0;
  s2->p2.y = 0;
}

void    reset_tmp_square(t_square *square, t_point pos_plat)
{
  square->p1.x = pos_plat.x;
  square->p1.y = pos_plat.y;
  square->p2.x = pos_plat.x;
  square->p2.y = pos_plat.y;
}
