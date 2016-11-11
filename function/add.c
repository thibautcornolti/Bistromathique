/*
** add.c for bistro in /home/thibrex/delivery/CPool_bistro-matic
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Oct 24 10:18:54 2016 Thibaut Cornolti
** Last update Thu Nov  3 16:40:12 2016 yann probst
*/

#include <stdlib.h>
#include "my.h"
#include "my_infin.h"
#include "utils.h"

static char	*get_result(char *tmp1, char *tmp2, int *negative)
{
  if (tmp1[0] == '-' && tmp2[0] == '-')
    {
      *negative = 1;
      return (my_infin_add(&tmp1[1], &tmp2[2]));
    }
  else if (tmp1[0] == '-' && tmp2[0] != '-')
    if (my_infin_cmp(&tmp1[1], tmp2) > 0)
      {
	*negative = 1;
	return (my_infin_sub(&tmp1[1], tmp2));
      }
    else
      return (my_infin_sub(tmp2, &tmp1[1]));
  else if (tmp1[0] != '-' && tmp2[0] == '-')
      if (my_infin_cmp(tmp1, &tmp2[1]) < 0)
	{
	  *negative = 1;
	  return (my_infin_sub(&tmp2[1], tmp1));
	}
      else
	return (my_infin_sub(tmp1, &tmp2[1]));
  else
    return (my_infin_add(tmp1, tmp2));
}

char		*add(char *nb1, char *nb2)
{
  char		*res;
  char		*tmp1;
  char		*tmp2;
  int		negative;

  negative = 0;
  tmp1 = my_strdup(nb1);
  tmp2 = my_strdup(nb2);
  if (!are_correct_operandes(tmp1, tmp2))
    return (NULL);
  res = remove_zeros(get_result(tmp1, tmp2, &negative));
  free(tmp1);
  tmp1 = 0;
  free(tmp2);
  tmp2 = 0;
  if (negative)
    {
      my_revstr(res);
      res = (my_strcat(res, my_strdup("-")));
      my_revstr(res);
    }
  return (res);
}
