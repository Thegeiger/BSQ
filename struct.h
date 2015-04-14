/*
** struct.h for struct in /home/geiger_a/rendu/CPE_2014_bsq
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Mon Dec 22 12:14:32 2014 anthony geiger
** Last update Tue Dec 23 11:07:28 2014 anthony geiger
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_move
{
  int	x;
  int	y;
  int	xpos;
  int	square;
  int	ypos;
  int	square_buff;
  int	pass;
  int	xstart_square;
  int	ystart_square;
}		t_move;

typedef	struct	s_map
{
  int		hight;
  int		width;
  char		**map;
}		t_map;

#endif /* !STRUCT_H_ */
