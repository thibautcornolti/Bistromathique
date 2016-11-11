/*
** is_operateur.c for isooperateur in /home/probst_y/goodparsing
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Nov  1 20:37:05 2016 yann probst
** Last update Tue Nov  1 20:37:52 2016 yann probst
*/

#include "mylist.h"
#include "my.h"

int	operateur(char c)
{
  if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%')
    return (0);
  else
    return (-1);
}

int	operateur2(char c)
{
  if (c == '*' || c == '/' || c == '%')
    return (0);
  else
    return (-1);
}

int	is_operateur(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '+' || str[i] == '-' ||
	  str[i] == '*' || str[i] == '/' || str[i] == '%')
	{
	  return (0);
	}
      i++;
    }
  return (-1);
}
