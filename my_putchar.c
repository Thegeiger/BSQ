/*
** my_putchar.c for my_putchar in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:21:31 2014 anthony geiger
** Last update Sat Dec 13 19:56:16 2014 anthony geiger
*/

#include <unistd.h>
#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}
