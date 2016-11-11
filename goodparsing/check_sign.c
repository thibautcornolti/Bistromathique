/*
** check_sign.c for check_sign in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 20:38:29 2016 yann probst
** Last update Sat Nov  5 22:23:40 2016 yann probst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "macro.h"

int	is_sign_num(char c)
{
  if (c == '+' || c == '-')
    return (1);
  else
    return (-1);
}

void	modif_sign_put(char *str, char *new, int i[3], int *nb)
{
  while (is_sign_num(str[i[0]]) == 1)
    {

      if (str[i[0]] == '-')
	(*nb)++;
      else
	(*nb) = (*nb) + 2;
      (i[0])++;
    }
  if (*nb % 2 == 1)
    new[i[1]] = '-';
  else
    new[i[1]] = '+';
  (i[1])++;
}

char	*modif_sign(char *str)
{
  char	*new;
  int	i[3];
  int	nb;

  i[1] = 0;
  i[0] = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  while (str[i[0]] != '\0')
    {
      nb = 0;
      if (is_sign_num(str[i[0]]) == 1 && is_sign_num(str[i[0] + 1]) == 1)
	modif_sign_put(str, new, i, &nb);
      new[i[1]++] = str[i[0]++];
    }
  new[i[1]] = '\0';
  return (new);
}

int	check_two_operateur(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (operateur_two(str[i]) == 1 && operateur_two(str[i + 1]) == 1)
	return (-1);
      i++;
    }
  return (0);
}

int	check_modulo_div_zero(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '%' && str[i + 1] == '0')
	exit(EXIT_BY_0 + my_puterror(MOD_0_MSG) * 0);
      else if (str[i] == '/' && str[i + 1] == '0')
	exit(EXIT_BY_0 + my_puterror(DIV_0_MSG) * 0);
      i++;
    }
  return (0);
}
