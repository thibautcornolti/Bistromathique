/*
** mod.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/function
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 26 11:16:40 2016 Victorien Fischer
** Last update Fri Nov  4 10:28:37 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "my_infin.h"
#include "utils.h"
#include "macro.h"

static char	*get_result(char *tmp1, char *tmp2, int *negative)
{
  if (tmp1[0] == '-' && tmp2[0] == '-')
    {
      *negative = 1;
      return (my_infin_mod(&tmp1[1], &tmp2[1]));
    }
  else if (tmp1[0] == '-' && tmp2[0] != '-')
    {
      *negative = 1;
      return (my_infin_mod(&tmp1[1], tmp2));
    }
  else if (tmp1[0] != '-' && tmp2[0] == '-')
    return (my_infin_mod(tmp1, &tmp2[1]));
  else
    return (my_infin_mod(tmp1, tmp2));
}

void	check_mod_by_zero(char *nb2)
{
  char	*zero;

  zero = my_strdup("0");
  if (my_infin_cmp(nb2, zero) == 0)
    {
      my_puterror(MOD_0_MSG);
      exit(EXIT_BY_0);
    }
  free(zero);
  zero = 0;
}

char	*mod(char *nb1, char *nb2)
{
  char	*tmp1;
  char	*tmp2;
  char	*res;
  int	negative;

  check_mod_by_zero(nb2);
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
