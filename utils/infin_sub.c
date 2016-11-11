/*
** infin_sub.c for bistro in /home/thibrex/delivery/CPool_bistro-matic
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Oct 24 14:47:36 2016 Thibaut Cornolti
** Last update Fri Nov  4 10:36:03 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "macro.h"

static int	before(int *ret, int *i, char **nbr1, char **nbr2)
{
  *i = -1;
  *ret = 0;
  my_revstr(*nbr1);
  my_revstr(*nbr2);
  return (0);
}

static void	do_whil(char **result, int *sub, int *ret, int i)
{
  *(*(result) + i) = (*sub - *ret < 0) ?
    *sub - *ret + 10 + '0' : *sub - *ret + '0';
  *ret = (*sub - *ret < 0) ? 1 : 0;
}

char		*my_infin_sub(char *nbr1, char *nbr2)
{
  char		*result;
  int		len[2];
  int		i;
  int		sub;
  int		ret;

  before(&ret, &i, &nbr1, &nbr2);
  len[0] = my_strlen(nbr1) + (len[1] = my_strlen(nbr2)) * 0;
  if ((result = malloc(sizeof(*result) * (len[0] + len[1] + 2))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  my_memset_str(result, 0, len[0] + len[1]);
  while (++i < len[0] + 1 || i < len[1] + 1)
    {
      if (i >= len[0] && i >= len[1])
	sub = 0;
      else if (i >= len[0])
	sub = nbr2[i] - '0';
      else if (i >= len[1])
	sub = nbr1[i] - '0';
      else
	sub = nbr1[i] - nbr2[i];
      do_whil(&result, &sub, &ret, i);
    }
  result[i] = 0;
  return (my_revstr(result));
}
