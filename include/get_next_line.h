/*
** get_next_line.h for get_next_line in /home/soto_a/rendu/CPE_2014_get_next_line
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Nov 14 12:29:34 2014 Kaso Soto
** Last update Fri Jan 16 17:16:29 2015 Kaso Soto
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUFF_SIZE 4096

char	*my_realloc(char *, int);
void	my_reset_buff(char *buffer);
char	*get_line(char *, int, const int);
char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
