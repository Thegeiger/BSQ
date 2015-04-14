/*
** final_aff.c for aff in /home/geiger_a/rendu/CPE_2014_bsq
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Tue Dec 23 10:26:17 2014 anthony geiger
** Last update Tue Dec 23 14:50:12 2014 anthony geiger
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

void		my_aff_final(t_map *s, t_move *move)
{
  int		x;
  int		y;

  x = 0;
  while (x < move->square_buff)
    {
      y = 0;
      while (y < move->square_buff)
	{
	  s->map[move->xstart_square + x][move->ystart_square + y] = 'x';
	  y++;
	}
      x++;
    }
  my_aff_tab(x, y, s);
}

void		my_color_put(int x, int y, t_map *s)
{
  if (s->map[x][y] == 'x')
    {
      my_putstr("\033[31m");
      my_putchar(s->map[x][y]);
      my_putstr("\033[0m");
    }
  else if (s->map[x][y] == 'o')
    {
      my_putstr("\033[32m");
      my_putchar(s->map[x][y]);
      my_putstr("\033[0m");
    }
  else
    {
      my_putstr("\033[34m");
      my_putchar(s->map[x][y]);
      my_putstr("\033[0m");
    }
}

void		my_aff_tab(int x, int y, t_map *s)
{
  my_putchar('\r');
  x = 1;
  while (x < s->hight - 1)
    {
      y = 0;
      while (y < s->width)
	{
	  my_color_put(x, y, s);
	  y++;
	}
      my_putchar('\n');
      x++;
    }
}
