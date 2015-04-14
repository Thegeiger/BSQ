/*
** my_argv_gest.c for argv_gest in /home/geiger_a/rendu/CPE_2014_bsq
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Tue Dec 23 10:30:16 2014 anthony geiger
** Last update Sat Dec 27 12:02:33 2014 anthony geiger
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		my_err_square(t_map *s)
{
  int		x;
  int		y;

  x = 1;
  while (x < s->hight)
    {
      y = 0;
      while (s->map[x][y])
	{
	  if (s->map[x][y] != '.' && s->map[x][y] != 'o')
	    {
	      my_putstr("I only can suport '.' and 'o'\n");
	      return (- 1);
	    }
	  y++;
	}
      if (y != s->width && x < s->hight - 1)
	{
	  my_putstr("Please give me a true square or rectangle\n");
	  return (- 1);
	}
      x++;
    }
  return (0);
}

t_map		*my_argv_gest(char *argv)
{
  int		fd;
  char		*c;
  int		x;
  char		*save;
  t_map		*s;

  x = 0;
  fd = open(argv, O_RDONLY);
  if (fd == - 1)
    return (NULL);
  if ((s = my_malloc_map(argv, 0, 0, NULL)) == NULL)
    return (NULL);
  while ((c = get_next_line(fd)))
    {
      if ((save = my_put_chain(save, c)) == NULL)
	return (NULL);
      s->map[x] = save;
      free(c);
      x++;
    }
  s->width = my_width(s->map);
  if (my_err_square(s) == - 1)
    return (NULL);
  return (s);
}

t_map		*my_malloc_map(char *argv, int x, int fd, char *c)
{
  t_map		*s;

  if ((s = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  s->hight = 0;
  s->width = 0;
  if ((fd = open(argv, O_RDONLY)) == - 1)
    return (NULL);
  while ((c = get_next_line(fd)))
    {
      s->hight++;
      free(c);
    }
  if (s->hight == 0 || s->hight == 1)
    return (NULL);
  if ((s->map = malloc(sizeof(char **) * s->hight + 1)) == NULL)
    return (NULL);
  while (x != s->hight)
    {
      if ((s->map[x] = malloc(sizeof(char *))) == NULL)
	return (NULL);
      x++;
    }
  return (s);
}

int		my_width(char **map)
{
  int		i;

  i = 0;
  while (map[1][i])
    i++;
  return (i);
}
