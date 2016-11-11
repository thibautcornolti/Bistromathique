/*
** infin_div.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/utils
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 26 11:59:38 2016 Victorien Fischer
** Last update Fri Nov  4 21:41:10 2016 Victorien Fischer
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_infin.h"
#include "my_operators.h"
#include "utils.h"
#include "macro.h"

char	*find_rest(char *nb1, char *nb2, char **q)
{
  char	*tmp;
  char	*count;
  int	val[3];

  count = my_strdup("0");
  val[0] = my_strlen(nb1) + ((val[1] = my_strlen(nb2)) + (val[2] = -1)) * 0;
  tmp = mul(nb2, count);
  tmp[my_strlen(tmp)] = 0;
  while (my_infin_cmp(tmp, nb1) < 0)
    {
      count[0] += 1;
      if (count[0] == 58)
	tmp = mul(nb2, my_strdup("10"));
      else
	tmp = mul(nb2, count);
    }
  if (my_infin_cmp(tmp, nb1) != 0)
    count[0] -= 1;
  *q = count;
  if (my_infin_cmp(tmp, nb1) == 0)
    return ("0");
  else
    return (sub(nb1, sub(tmp, nb2)));
}

char	*infin_div_loop(char *nb1, char *nb2, int *val)
{
  char	*res;
  char	*tmp;
  char	*q;
  char	*tmp1;

  tmp1 = malloc(sizeof(char) * (val[1] + 2));
  res = malloc(sizeof(char) * (val[1] + 2));
  q = malloc(sizeof(char) * 2);
  if (tmp1 == NULL || res == NULL || q == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  my_memset_str(res, 0, val[1]);
  my_strcpy(tmp1, nb1);
  tmp1[val[0]] = 0;
  while (nb1[val[0] - 1] != 0)
    {
      tmp = find_rest(tmp1, nb2, &q);
      res[val[0] - val[2]] = q[0] + 0 * (val[3] = my_strlen(tmp));
      my_strcpy(tmp1, tmp);
      tmp1[val[3]] = nb1[val[0]];
      val[0] += 1;
      tmp1[val[3] + 1] = 0;
      tmp1 = remove_zeros(tmp1);
    }
  free(q);
  return (res);
}

char	*my_infin_div(char *nb1, char *nb2)
{
  char	*res;
  int	val[4];

  if (nb2[0] == '1' && nb2[1] == 0)
    return (my_strdup(nb1));
  if (my_infin_cmp(nb1, nb2) < 0)
    return (my_strdup("0"));
  val[1] = my_strlen(nb1);
  val[2] = my_strlen(nb2);
  val[0] = val[2];
  res = infin_div_loop(nb1, nb2, val);
  res[val[0] - val[2]] = 0;
  return (res);
}
