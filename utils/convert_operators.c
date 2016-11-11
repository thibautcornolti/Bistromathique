/*
** convert_operators.c for bistro in /home/thibrex/delivery/CPool_bistro-matic/thib
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Nov  1 01:02:58 2016 Thibaut Cornolti
** Last update Sat Nov  5 20:10:09 2016 Victorien Fischer
*/

#include <stdlib.h>
#include "my.h"

char		my_convert_operators(char nbr, char *ops)
{
  char		*r_op;
  int		j;

  r_op = my_strdup("()+-*/%");
  if (ops == NULL)
    return (nbr);
  j = 0;
  while (ops[j] != 0)
    {
      if (nbr == ops[j])
	nbr = r_op[j];
      j += 1;
    }
  return (nbr);
}
