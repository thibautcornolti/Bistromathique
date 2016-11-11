/*
** prio_and_para.c for prioandpara in /home/probst_y/rendu/JourPiscine/CPool_evalexpr/yann
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Thu Oct 27 10:43:30 2016 yann probst
** Last update Fri Oct 28 14:15:50 2016 yann probst
*/

#include "mylist.h"

int		is_parenthese(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	return (0);
      i++;
    }
  return (-1);
}

int		is_para(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ')')
	return (0);
      i++;
    }
  return (-1);
}

int		prio(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*')
	return (0);
      else if (str[i] == '/')
	return (0);
      else
	return (1);
      i++;
    }
  return (0);
}

int	prioritaire(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/' || str[i] == '*' || str[i] == '%')
	return (0);
      i++;
    }
  return (-1);
}
