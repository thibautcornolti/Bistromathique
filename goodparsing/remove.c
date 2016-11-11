/*
** remove.c for remove in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 20:42:09 2016 yann probst
** Last update Fri Nov  4 10:33:16 2016 Thibaut Cornolti
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "macro.h"

int	no_number(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	nb++;
      i++;
    }
  if (nb == 0)
    return (-1);
  return (0);
}

char	*remove_plus_before_para(char *str)
{
  int	i;
  int	a;
  char	*new;

  i = 0;
  a = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  while (str[i] != '\0')
    {
      if (str[i] == '+' && str[i - 1] == '(')
	i++;
      new[a++] = str[i++];
    }
  new[a] = '\0';
  return (new);
}

char	*remove_beginning_plus(char *str)
{
  int	i;
  int	a;
  char	*new;

  i = 0;
  a = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  while (str[i] != '\0')
    {
      if (str[i] == '+' && i == 0)
	i++;
      new[a++] = str[i++];
    }
  new[a] = '\0';
  return (new);
}

char	*remove_plus_after_cara(char *str)
{
  int	i;
  int	a;
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  a = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '+' && operateur_two(str[i - 1]) == 1)
	{
	  while (str[i] == '+' && operateur_two(str[i - 1]) == 1)
	    i++;
	}
      new[a++] = str[i++];
    }
  new[a] = '\0';
  return (new);
}
