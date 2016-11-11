/*
** my_rev_list.c for revlist in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 19:35:29 2016 yann probst
** Last update Tue Nov  1 19:35:30 2016 yann probst
*/

#include <unistd.h>
#include "mylist.h"

int		my_rev_list(t_list **begin)
{
  t_list	*prev_elem;
  t_list	*tmp;
  t_list	*next_elem;

  tmp = *begin;
  prev_elem = NULL;
  while (tmp != NULL)
    {
      next_elem = tmp->next;
      tmp->next = prev_elem;
      prev_elem = tmp;
      tmp = next_elem;
    }
  *begin = prev_elem;
  return (0);
}
