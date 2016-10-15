/*
** print_square.c for print_square in /home/soto_a/rendu/CPE_2014_bsq
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Dec 23 16:34:32 2014 Kaso Soto
** Last update Sun Jan 18 16:14:00 2015 Kaso Soto
*/

#include "bsq.h"

void		print_and_reset_pos(char *str, t_point *p)
{
  my_putstr(str);
  my_putchar('\n');
  p->x = 0;
  p->y++;
}

void		print_square(char **plat, t_square square, int param)
{
   t_point	p;

   p.x = 0;
   p.y = 0;
   if (param == 1)
     {
       if_litle_square('q', &square);
       while (plat[p.y])
	 {
	   while (plat[p.y][p.x])
	     {
	       if (plat[p.y][p.x] != 'o' && square.p1.x != -1
		   && ((p.y >= square.p1.y && p.y <= square.p2.y)
		   && (p.x >= square.p1.x && p.x <= square.p2.x)))
		 plat[p.y][p.x] = 'x';
	       else if (if_litle_square(plat[p.y][p.x], &square))
		 plat[p.y][p.x] = 'x';
	       p.x++;
	     }
	   print_and_reset_pos(plat[p.y], &p);
	 }
     }
   else
     print_only_pos(square);
}

int		if_litle_square(char c, t_square *square)
{
  static int	i = -1;

  if (i == -1 && square->p1.x == 0 && square->p1.y == 0
      && square->p2.x == 0 && square->p2.y == 0)
    {
      i++;
      square->p1.x = -1;
      square->p1.y = -1;
      square->p2.x = -1;
      square->p2.y = -1;
    }
  else
    {
      if (c != 'o' && square->p1.x == -1 && square->p1.y == -1 
	  && square->p2.x == -1 && square->p2.y == -1
	  && i == 0)
	{
	  i++;
	  return (1);
	}
      else
	return (0);
    }
  return (0);
}

void	print_only_pos(t_square square)
{
  my_putstr("square start : ");
  my_put_nbr(square.p1.x);
  my_putchar(',');
  my_put_nbr(square.p1.y);
  my_putchar('\n');
  my_putstr("square end : ");
  my_put_nbr(square.p2.x);
  my_putchar(',');
  my_put_nbr(square.p2.y);
  my_putchar('\n');
}
