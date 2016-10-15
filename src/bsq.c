/*
** bsq.c for bsq in /home/soto_a/rendu/CPE_2014_bsq
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Dec 22 19:15:21 2014 Kaso Soto
** Last update Sun Jan 18 18:29:24 2015 Kaso Soto
*/

#include "bsq.h"

void	free_plat(char **plat)
{
  int	i;

  i = 0;
  while (plat[i] != NULL)
    {
      free(plat[i]);
      i++;
    }
  free(plat);
}

int		main(int ac, char **av)
{
  char		**plat;
  t_square	max_square;
  int		param;

  param = 1;
  if (ac == 1)
    my_putstr("Usage : ./bsq [-n] + map\n");
  else if (ac > 1 && ac < 4)
    {
      if (av[1][0] == '-' && ac == 3)
	param++;
      else if (av[1][0] == '-' && ac == 2)
	{
	  my_putstr("Usage : ./bsq [-n] + map\n");
	  return (0);
	}
      plat = parsing_plat(av[param]);
      max_square = search_max_square(plat);
      print_square(plat, max_square, param);
      free_plat(plat);
    }
  else
    my_putstr("Usage : ./bsq [-n] + map\n");
  return (0);
}
