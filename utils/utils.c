/*
** utils.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Tue Oct 25 09:49:51 2016 Victorien Fischer
** Last update Fri Nov  4 10:29:23 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "macro.h"

int	are_correct_operandes(char *nb1, char *nb2)
{
  if (nb1[0] == '-' && !my_str_isnum(nb1 + 1))
    return (0);
  if (nb1[0] != '-' && !my_str_isnum(nb1))
    return (0);
  if (nb2[0] == '-' && !my_str_isnum(nb2 + 1))
    return (0);
  if (nb2[0] != '-' && !my_str_isnum(nb2))
    return (0);
  if (nb1[0] == '-' && nb2[0] == '-' && nb1[1] == 0 && nb2[1] == 0)
    return (0);
  return (1);
}

char	*inser_char(char **str, char c, int pos)
{
  char	*tmp;
  int	i;
  int	j;

  i = -1;
  if ((tmp = malloc(sizeof(char) * (my_strlen(*str) + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  while ((*str)[++i] != 0)
    tmp[i] = (*str)[i];
  tmp[i] = 0;
  free(*str);
  if ((*str = malloc(sizeof(char) * (my_strlen(tmp) + 3))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  i = -1 + 0 * (j = 0);
  while (tmp[++i - j] != 0)
    if (i == pos)
      {
	(*str)[i] = c;
	j += 1;
      }
    else
      (*str)[i] = tmp[i - j];
  (*str)[i] = 0;
  (*str)[i] = (my_strlen(*str) == pos) ? c + 0 * ((*str)[i + 1] = 0) : 0;
  return (*str);
}

int	my_strtol(char *str, int *counter)
{
  int	result;
  char	nbr[12];

  str += *counter;
  result = my_getnbr(str);
  my_int_to_str(result, nbr);
  *counter += my_strlen(nbr) - 1;
  return (result);
}
