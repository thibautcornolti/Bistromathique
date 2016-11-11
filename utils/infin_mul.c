/*
** infin_mul.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/utils
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 26 11:58:35 2016 Victorien Fischer
** Last update Fri Nov  4 10:35:43 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "macro.h"

char	*my_infin_mul(char *nb1, char *nb2)
{
  char	*result;
  int	i;
  int	j;
  int	len;

  len = my_strlen(nb1) + my_strlen(nb2) + 1;
  i = -1;
  if ((result = malloc(sizeof(char) * (len + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  my_memset_str(result, 0, len + 1);
  my_revstr(nb1);
  my_revstr(nb2);
  while (nb1[++i] != 0 * (j = -1))
    while (nb2[++j] != 0)
      {
	result[i + j] += (nb2[j] - '0') * (nb1[i] - '0');
	result[i + j + 1] += result [i + j] / 10;
	result[i + j] = result[i + j] % 10;
      }
  i = -1;
  while (++i < len  - 1)
    result[i] += '0';
  return (my_revstr(result));
}
