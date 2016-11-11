/*
** check_oper.c for checkoper in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 20:40:05 2016 yann probst
** Last update Fri Nov  4 16:11:17 2016 Victorien Fischer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int	check_parsing_suite(char *str)
{
  if (check_num_before_para(str) == -1)
    return (-1);
  if (check_number_after_oper(str) == -1)
    return (-1);
  if (check_oper_before_para(str) == -1)
    return (-1);
  if (check_after_para(str) == -1)
    return (-1);
  if (check_two_operateur(str) == -1)
    return (-1);
  if (check_para(str) == -1)
    return (-1);
  if (check_empty_paran(str) == -1)
    return (-1);
  return (0);
}

int	check_parsing(char *str)
{
  int	i;

  i = 0;
  if (operateur2(str[0]) == 0)
    return (-1);
  if (check_parsing_suite(str) == -1)
    return (-1);
  if (check_order_para(str) == -1)
    return (-1);
  if (check_modulo_div_zero(str) == -1)
    return (-1);
  if (check_oper_oper(str) == -1)
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] == ')' && str[i + 1] == '(')
	return (-1);
      i++;
    }
  return (0);
}

int	is_cara_ok(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else if (c == '-' || c == '+' || c == '%' || c == '*' || c == '/')
    return (1);
  else if (c == '(' || c == ')')
    return (1);
  else
    return (-1);
}

int	check_if_az(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (is_cara_ok(str[i]) == -1)
	return (-1);
      i++;
    }
  return (0);
}
