/*
** check_oper2.c for check_oper in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Wed Nov  2 13:06:51 2016 yann probst
** Last update Wed Nov  2 13:08:01 2016 yann probst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int	check_oper_oper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-' && operateur(str[i + 1]) == 0)
	return (-1);
      if (str[i] == '+' && operateur(str[i + 1]) == 0)
	return (-1);
      i++;
    }
  return (0);
}

int	check_after_para(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(' && operateur2(str[i + 1]) == 0)
	return (-1);
      i++;
    }
  return (0);
}

int	check_number_after_oper(char *str)
{
  int	i;
  int	a;
  int	b;

  a = 0;
  b = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (num2(str[i]) == 0)
	{
	  a = i;
	}
      else if (operateur(str[i]) == 0)
	{
	  b = i;
	}
      i++;
    }
  if (b > a)
    return (-1);
  return (0);
}

int	check_oper_before_para(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ')' && operateur(str[i - 1]) == 0)
	return (-1);
      i++;
    }
  return (0);
}
