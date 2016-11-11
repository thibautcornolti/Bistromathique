/*
** my_list_size.c for list_size in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 19:35:17 2016 yann probst
** Last update Tue Nov  1 19:35:18 2016 yann probst
*/

#include <unistd.h>
#include "mylist.h"

int	my_list_size(t_list *begin)
{
  int	ret;

  ret = 0;
  while (begin != NULL)
    {
      ret++;
      begin = begin->next;
    }
  return (ret);
}
