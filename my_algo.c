/*
** my_algo.c for my_algo in /home/geiger_a/rendu/CPE_2014_bsq
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Tue Dec 23 10:35:40 2014 anthony geiger
** Last update Sat Dec 27 12:00:07 2014 anthony geiger
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "get_next_line.h"

int	my_verif_square(t_map *s, t_move *move)
{
  move->x = move->xpos;
  while (move->x < move->square + move->xpos)
    {
      move->y = move->ypos;
      while (move->y < move->square + move->ypos)
	{
	  if (s->map[move->x][move->y] == 'o')
	    return (1);
	  move->y++;
	}
      move->x++;
    }
  return (0);
}

void		my_check_square(t_move *move, t_map *s)
{
  move->pass = 0;
  move->square = 0;
  while (move->pass == 0 && move->square + move->xpos < s->hight
	 && move->square + move->ypos < s->width)
    {
      if (my_verif_square(s, move) == 1)
	{
	  if (move->square_buff < move->square - 1)
	    {
	      move->xstart_square = move->xpos;
	      move->ystart_square = move->ypos;
	      move->square_buff = move->square - 1;
	    }
	  move->pass = 1;
	}
      move->square++;
    }
  move->ypos++;
}

int		my_verif_size(t_map *s)
{
  int		x;
  int		y;
  int		nb;

  x = 0;
  y = 0;
  nb = 0;
  while (s->map[x][y])
    {
      nb = nb * 10 + (s->map[x][y] - '0');
      y++;
    }
  if (nb + 2 != s->hight)
    return (1);
  return (0);
}

t_move		*my_square_algo(t_map *s)
{
  t_move	*move;

  if ((move = malloc(sizeof(t_move))) == NULL)
    return (NULL);
  if (my_verif_size(s) == 1)
    {
      my_putstr("Wrong number\n");
      return (NULL);
    }
  move->xpos = 1;
  move->square_buff = 0;
  move->xstart_square = 0;
  move->ystart_square = 0;
  while (move->xpos < s->hight)
    {
      move->ypos = 0;
      while (move->ypos < s->width)
	{
	  my_check_square(move, s);
	}
      move->xpos++;
    }
  return (move);
}
