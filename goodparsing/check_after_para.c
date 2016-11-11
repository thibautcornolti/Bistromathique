/*
** check_after_para.c for check_para in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Wed Nov  2 13:19:16 2016 yann probst
** Last update Wed Nov  2 13:19:30 2016 yann probst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int	check_num_before_para(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (num2(str[i]) == 0 && str[i + 1] == '(')
	return (-1);
      i++;
    }
  return (0);
}

int	check_num_after_para(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ')' && num2(str[i + 1]) == 0)
	return (-1);
      i++;
    }
  return (0);
}
