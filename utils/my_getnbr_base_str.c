/*
** my_getnbr_base_str.c for my_getnbr_base_str in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 22:15:13 2016 Cornolti Thibaut
** Last update Sat Nov  5 20:09:52 2016 Victorien Fischer
*/

#include <stdlib.h>
#include "my.h"
#include "my_operators.h"
#include "utils.h"
#include "macro.h"

static int	getnbr_index_of(char value, char *str)
{
  int		count;
  int		index;

  count = 0;
  index = -1;
  while (str[count] != 0 && index < 0)
    {
      if (str[count] == value)
	index = count;
      count += 1;
    }
  return (index);
}

static char	*my_getnbr_base_str_it(char *str, char *base)
{
  char		*result;
  int		lenb;
  char		*lenbstr;
  int		len;
  long		i;
  int		index;
  char		*idstr;

  len = (my_strlen(str) * my_strlen(base) + 1);
  result = malloc(sizeof(char) * len);
  idstr = malloc(sizeof(char) * 14);
  lenbstr = malloc(sizeof(char) * 14);
  if (result == NULL || idstr == NULL || lenbstr == NULL)
    return (NULL);
  my_memset_str(result, 0, len);
  lenb = my_strlen(base);
  i = -1;
  while (str[++i] != '\0')
    {
      index = getnbr_index_of(str[i], base);
      my_int_to_str(index, idstr);
      my_int_to_str(lenb, lenbstr);
      my_strcpy(result, add(mul(result, lenbstr), idstr));
    }
  return (result);
}

static int	contains_char(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (1);
      i += 1;
    }
  return (0);
}

char	*my_getnbr_base_str(char *str, char *base, char *op)
{
  int	len;
  int	i;
  char	*neg;

  neg = my_strdup("1");
  i = 0;
  len = 0;
  while (*str != 0 && (*str == op[3] || *str == op[2]))
    {
      if (*str == op[3])
	neg = mul(neg, "-1");
      str += 1;
    }
  while (base[len] != 0)
    len += 1;
  while (contains_char(str[i], base) == 1)
    i += 1;
  return (mul(my_getnbr_base_str_it(str, base), neg));
}
