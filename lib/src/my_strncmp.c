/*
** my_strcmp.c for my_strcmp.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 15:47:43 2014 adam kaso
** Last update Fri Dec  5 14:58:42 2014 Kaso Soto
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  while (n--)
    {
      if (*s1 == 0)
	return (0);
      s1++;
      s2++;
    }
  return (*s1 < *s2 ? -1 : 1);
}
