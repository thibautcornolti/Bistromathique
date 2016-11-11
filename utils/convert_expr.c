/*
** convert_expr.c for bistro in /home/thibrex/delivery/CPool_bistro-matic
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Nov  1 22:16:52 2016 Thibaut Cornolti
** Last update Sat Nov  5 20:07:07 2016 yann probst
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"
#include "macro.h"

char	**insern_str(char **str1, char *str2, int pos_max)
{
  int	i;

  i = 0;
  while (i <= pos_max)
    {
      remove_char(*str1, 0);
      i += 1;
    }
  i = 0;
  while (str2[i] != 0)
    {
      inser_char(str1, str2[i], i);
      i += 1;
    }
  return (str1);
}

int	init_str(char **tmp, char **tmp2, char **nbr, char **base)
{
  int	len;

  len = my_strlen(*nbr) * my_strlen(base[0]) * my_strlen(base[1]) + 1;
  *tmp = malloc(sizeof(char) * len);
  *tmp2 = malloc(sizeof(char) * len);
  if (*tmp == NULL || *tmp2 == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  return (1);
}

static void	convert_expr_base_sup(char **nbr, char *tmp,
				      char *tmp2, char **base)
{
  int		i;
  int		j;
  char		c;

  i = -1;
  while (0 * (j = ++i) || (*nbr)[i] != 0)
    if (!my_str_contains((*nbr)[i], base[0]))
      {
	c = (*nbr)[i + 1];
	(*nbr)[i + 1] = 0;
	(*nbr)[i] = my_convert_operators((*nbr)[i], base[2]);
	my_strcat(tmp2, &((*nbr)[i]));
	(*nbr)[i + 1] = c;
      }
    else
      {
	while ((*nbr)[i] != 0 && my_str_contains((*nbr)[i], base[0]))
	  {
	    tmp[i - j] = (*nbr)[i];
	    i += 1;
	    tmp[i - j] = 0;
	  }
	my_strcat(tmp2, convert_base_str(tmp, base[0], base[1], base[2]));
	i -= 1;
      }
}

char	**my_convert_expr_base(char **nb, char *base_f, char *base_t, char *op)
{
  char	*tmp;
  char	*tmp2;
  char	*base[3];
  int	len;

  len = my_strlen(*nb) * my_strlen(base_f) * my_strlen(base_t) + 1;
  base[0] = base_f;
  base[1] = base_t;
  base[2] = op;
  if (init_str(&tmp, &tmp2, nb, base) == 0)
    return (NULL);
  my_memset_str(tmp, 0, len);
  my_memset_str(tmp2, 0, len);
  convert_expr_base_sup(nb, tmp, tmp2, base);
  free(tmp);
  tmp = 0;
  *nb = tmp2;
  return (nb);
}
