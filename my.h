/*
** my.h for m in /home/geiger_a/rendu/CPE_2014_Pushswap
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Dec  6 13:23:29 2014 anthony geiger
** Last update Tue Dec 23 15:03:12 2014 anthony geiger
*/

#ifndef MY_H_
# define MY_H_
# include "get_next_line.h"
# include "struct.h"

void		my_putchar(char c);
void		my_putnbr(int nb);
void		my_putstr(char *str);
void		my_putsterr(char *str);
char		*get_next_line(const int fd);
char		*my_put_chain(char *save, char *c);
void		my_aff_final(t_map *s, t_move *move);
void		my_final_free(t_map *s, t_move *move);
void		my_aff_tab(int x, int y, t_map *s);
t_map		*my_argv_gest(char *argv);
t_map		*my_malloc_map(char *argv, int x, int fd, char *c);
int		my_width(char **map);
int		my_verif_square(t_map *s, t_move *move);
void		my_check_square(t_move *move, t_map *s);
t_move		*my_square_algo(t_map *s);
int		my_verif_size(t_map *s);
void		my_load_barre();

#endif /* !MY_H_ */
