/*
** parsing_plat.c for parsing_plat.c in /home/soto_a/rendu/CPE_2014_bsq
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Dec 22 23:03:43 2014 Kaso Soto
** Last update Sun Jan 18 18:25:05 2015 Kaso Soto
*/

#include "bsq.h"

char	**parsing_plat(const char *file_name)
{
  char	**plat;
  char	*read;
  int	fd_plat;
  int	size;
  int	i;

  i = 0;
  if ((fd_plat = open(file_name, O_RDWR)) < 0)
    exit(EXIT_FAILURE);
  if ((read = get_next_line(fd_plat)) == NULL)
    my_empty_file();
  check_if_number(read);
  size = my_getnbr(read);
  if ((plat = malloc(sizeof(char *) * (size + 1))) == NULL)
    exit(EXIT_FAILURE);
  free(read);
  while ((read = get_next_line(fd_plat)) && i != size)
    {
      plat[i] = my_strdup(read);
      free(read);
      ++i;
    }
  plat[i] = NULL;
  close(fd_plat);
  return (plat);
}

void	my_empty_file()
{
  my_putstr("The file is not valide\n");
  exit(EXIT_FAILURE);
}

void	check_if_number(char *number)
{
  int	i;

  i = 0;
  while (number[i])
    {
      if (!(number[i] >= '0' && number[i] <= '9'))
	{
	  my_putstr("The first line is not a number\n");
	  exit(EXIT_FAILURE);
	}
      ++i;
    }
}
