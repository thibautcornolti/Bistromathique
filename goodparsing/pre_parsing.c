/*
** pre_parsing.c for preparsing in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 20:27:39 2016 yann probst
** Last update Sat Nov  5 22:23:08 2016 yann probst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "macro.h"

char	*pre_parsing2(char *str)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  new = modif_sign(str);
  return (new);
}

int	check_para(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	nb++;
      else if (str[i] == ')')
	nb--;
      i++;
    }
  if (nb == 0)
    return (0);
  else
    return (-1);
}

int	check_empty_paran(char *str)
{
  int	i;

  i = 0;
  if (my_strcmp(str, "") == 0)
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] == '(' && str[i + 1] == ')')
	return (-1);
      i++;
    }
  return (0);
}

int	check_order_para(char *str)
{
  int	i;
  int	open;
  int	close;

  i = 0;
  open = 0;
  close = 0;
  while (str[i] != '\0')
    {
      if (close > open)
	return (-1);
      if (str[i] == '(')
	open++;
      else if (str[i] == ')')
	close++;
      i++;
    }
  return (0);
}

int	operateur_two(char c)
{
  if (c == '%' || c == '/' || c == '*')
    return (1);
  else
    return (0);
}
