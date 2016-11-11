/*
** convert_base.c for convert_base in /home/fischerv/delivery/CPool/CPool_Day08/task05
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 12 17:23:02 2016 Victorien Fischer
** Last update Sat Nov  5 21:18:40 2016 Victorien Fischer
*/

#include <stdlib.h>
#include "my.h"
#include "my_infin.h"
#include "my_operators.h"
#include "utils.h"
#include "macro.h"

char		*get_nbr_base_str(char *nbr, char *base, int length, char *str)
{
  char		*value;
  char		*len;
  char		tmp[2];
  char		*zero;

  if ((len = malloc(sizeof(char) * 20)) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  my_int_to_str(length, len);
  tmp[1] = 0;
  zero = my_strdup("0");
  value = my_strdup(nbr);
  if (my_infin_cmp(value, zero) == 0)
    my_strcpy(str, zero);
  while (my_infin_cmp(value, zero) > 0)
    {
      tmp[0] = base[my_getnbr(mod(value, len))];
      my_strcat(str, tmp);
      value = divi(value, len);
    }
  my_revstr(str);
  return (str);
}

char		*convert_base_str(char *nbr, char *base_f, char *base_t, char *ops)
{
  char		*number;

  if (my_infin_cmp(base_f, base_t) == 0)
      return (nbr);
  number = my_getnbr_base_str(nbr, base_f, ops);
  if (number[0] == '-')
    number = mul(number, my_strdup("-1"));
  return (number);
}

char	*convert_base_str2_neg(char *str, int neg, char *ops)
{
  char	minus[2];

  minus[0] = ops[3];
  minus[1] = 0;
  if (neg)
    {
      my_revstr(str);
      my_strcat(str, minus);
      my_revstr(str);
    }
  return (str);
}

char		*convert_base_str2(char *nbr, char *base_f,
				   char *base_t, char *ops)
{
  char		*str;
  int		len;
  int		negative;

  negative = 0;
  len = my_strlen(nbr) * my_strlen(base_t) * my_strlen(base_f) + 1;
  if (my_infin_cmp(base_f, base_t) == 0)
    return (nbr);
  if ((str = malloc(sizeof(char) * len)) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  if (str == 0)
    return (0);
  my_memset_str(str, 0, len);
  if (nbr[0] == '-')
    {
      get_nbr_base_str(my_strdup(&nbr[1]), base_t, my_strlen(base_t), str);
      negative = 1;
    }
  else
    get_nbr_base_str(my_strdup(nbr), base_t, my_strlen(base_t), str);
  while (*str == base_t[0] && *(str + 1) != 0)
    str += 1;
  return (convert_base_str2_neg(str, negative, ops));
}
