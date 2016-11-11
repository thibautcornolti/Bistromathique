/*
** calc.c for calc in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 19:34:38 2016 yann probst
** Last update Thu Nov  3 21:31:46 2016 yann probst
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"

void		adjust(t_list **list, t_list *nb1, t_list *op)
{
  t_list	*tmp;

  tmp = *list;
  if (tmp != nb1)
    {
      while (tmp->next != nb1)
	tmp = tmp->next;
      tmp->next = op;
    }
  else
    *list = op;
}

void		inter_calc(t_list **list)
{
  t_list	*op;
  t_list	*nb1;
  t_list	*nb2;

  op = *list;
  while (op != NULL && num(op->str))
    op = op->next;
  nb2 = *list;
  while (nb2->next != op)
    nb2 = nb2->next;
  nb1 = *list;
  while (nb1->next != nb2)
    nb1 = nb1->next;
  op->nb = simple_calc(nb1, nb2, op);
  op->str = my_strdup("1");
  adjust(list, nb1, op);
}

char		*calc(t_list **list)
{
  str_to_int_list(*list);
  while (my_list_size(*list) > 1)
    inter_calc(list);
  return ((*list)->nb);
}
