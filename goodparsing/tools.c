/*
** tools.c for taools in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 19:35:51 2016 yann probst
** Last update Fri Nov  4 10:34:01 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "macro.h"

int	num(char *str)
{
  if (str[0] == '-' && my_strlen(str) > 1)
    return (1);
  else if (str[0] >= '0' && str[0] <= '9')
    return (1);
  return (0);
}

void	str_to_int_list(t_list *list)
{
  while (list != NULL)
    {
      if (num(list->str))
	{
	  list->nb = malloc(sizeof(char) * (my_strlen(list->str) + 1));
	  if (list->nb == NULL)
	    exit(my_puterror(ERROR_MSG) + EXIT_MALLOC);
	  list->nb = my_strdup(list->str);
	}
      list = list->next;
    }
}
