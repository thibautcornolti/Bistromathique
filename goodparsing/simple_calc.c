/*
** simple_calc.c for simplecalc in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 19:35:41 2016 yann probst
** Last update Thu Nov  3 21:32:02 2016 yann probst
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "my_operators.h"

char	*simple_calc(t_list *nb1, t_list *nb2, t_list *op)
{
  if (op->str[0] == '+')
    return (add(nb1->nb, nb2->nb));
  else if (op->str[0] == '-')
    return (sub(nb1->nb, nb2->nb));
  else if (op->str[0] == '*')
    return (mul(nb1->nb, nb2->nb));
  else if (op->str[0] == '/')
    return (divi(nb1->nb, nb2->nb));
  else if (op->str[0] == '%')
    return (mod(nb1->nb, nb2->nb));
  return (NULL);
}
