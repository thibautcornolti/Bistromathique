/*
** sub.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/function
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 26 11:27:46 2016 Victorien Fischer
** Last update Fri Nov  4 21:13:51 2016 Victorien Fischer
*/

#include <stdlib.h>
#include "my.h"
#include "my_infin.h"
#include "utils.h"

static char	*get_result_normal(char *tmp1, char *tmp2, int *negative)
{
  if (my_infin_cmp(tmp1, tmp2) >= 1)
    return (my_infin_sub(tmp1, tmp2));
  else if (my_infin_cmp(tmp1, tmp2) == 0)
    return (my_strdup("0"));
  else
    {
      *negative = 1;
      return (my_infin_sub(tmp2, tmp1));
    }
}

static char	*get_result(char *tmp1, char *tmp2, int *negative)
{
  if (tmp1[0] == '-' && tmp2[0] == '-')
    if (my_infin_cmp(&tmp1[1], &tmp2[1]) >= 1)
      {
	*negative = 1;
	return (my_infin_sub(&tmp1[1], &tmp2[1]));
      }
    else
      return (my_infin_sub(&tmp2[1], &tmp1[1]));
  else if (tmp1[0] == '-' && tmp2[0] != '-')
    {
      *negative = 1;
      return (my_infin_add(&tmp1[1], tmp2));
    }
  else if (tmp1[0] != '-' && tmp2[0] == '-')
    return (my_infin_add(tmp1, &tmp2[1]));
  else
    return (get_result_normal(tmp1, tmp2, negative));
}

char		*sub(char *nb1, char *nb2)
{
  char		*tmp1;
  char		*tmp2;
  char		*res;
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
      res = my_strcat(res, my_strdup("-"));
      my_revstr(res);
    }
  return (res);
}
