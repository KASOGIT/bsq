/*
** search_max_quare.c for search_max_quare in /home/soto_a/rendu/CPE_2014_bsq
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Dec 23 16:33:01 2014 Kaso Soto
** Last update Fri Jan 23 16:45:24 2015 Kaso Soto
*/

#include "bsq.h"

t_square	search_max_square(char **plat)
{
  t_square	square;
  t_square	tmp_square;
  t_point	pos_plat;
  int		j;

  pos_plat.y = 0;
  init_squares(&square, &tmp_square);
  while (plat[pos_plat.y])
    {
      while (plat[pos_plat.y][pos_plat.x])
	{
	  j = act_on_square(plat, &square, &tmp_square);
	  pos_plat.x += (!plat[pos_plat.y][pos_plat.x + j - 1]) ? j - 1 : j;
	  reset_tmp_square(&tmp_square, pos_plat);
	}
      pos_plat.y++;
      pos_plat.x = 0;
      reset_tmp_square(&tmp_square, pos_plat);
    }
  return (square);
}

int	act_on_square(char **plat, t_square *square, t_square *tmp_square)
{
  int	bool;
  int	size_square;
  int	j;

  bool = 1;
  size_square = 1;
  while (bool == 1)
    {
      if ((j = check_is_square(plat, tmp_square, size_square)) == -1)
	{
	  tmp_square->p2.x = tmp_square->p1.x + size_square - 1;
	  tmp_square->p2.y = tmp_square->p1.y + size_square - 1;
	  ++size_square;
	}
      else
	{
	  compare_and_set_square(tmp_square, square);
	  bool = 0;
	}
    }
  return (j);
}

int		check_is_square(char **plat, t_square *square, int size_square)
{
  int		i;
  int		save_j;
  static int	j = 0;

  i = 0;
  save_j = j;
  while (i < size_square)
    {
      while (j < size_square)
	{
	  if (plat[square->p1.y + i] == NULL
	      || !plat[square->p1.y + i][square->p1.x + j]
	      || plat[square->p1.y + i][square->p1.x + j] == '\0'
	      || plat[square->p1.y + i][square->p1.x + j] == 'o')
	    return (reset_on_static(&j));
	  ++j;
	}
      ++i;
      if (i == (size_square - 1))
	j = 0;
      else
	j = save_j;
    }
  j = save_j + 1;
  return (-1);
}
