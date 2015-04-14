/*
** bsq.c for bsq in /home/geiger_a/rendu/tmp
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Dec 14 19:52:06 2014 anthony geiger
** Last update Tue Dec 23 12:21:20 2014 anthony geiger
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

char		*my_put_chain(char *save, char *c)
{
  int		i;

  i = 0;
  while (c[i])
    i++;
  if ((save = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (c[i])
    {
      save[i] = c[i];
      i++;
    }
  save[i] = '\0';
  return (save);
}

void		my_final_free(t_map *s, t_move *move)
{
  while (s->hight != 0)
    {
      free(s->map[s->hight - 1]);
      s->hight--;
    }
  free(s->map);
  free(s);
  free(move);
}

int		main(int argc, char **argv)
{
  t_map		*s;
  t_move	*move;

  if (argc == 1)
    {
      my_putstr("no argument\n");
      my_putstr("Usage : ./bsq [file]\n");
      return (1);
    }
  if (argc > 2)
    {
      my_putstr("to much argument\n");
      my_putstr("Usage : ./bsq [file]\n");
      return (1);
    }
  if ((s = my_argv_gest(argv[1])) == NULL)
    return (1);
  if ((move = my_square_algo(s)) == NULL)
    return (1);
  my_aff_final(s, move);
  my_final_free(s, move);
  return (0);
}
