/*
** basic.c for basic in /home/probst_y/rendu/JourPiscine/CPool_evalexpr/yann
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Wed Oct 26 12:35:08 2016 yann probst
** Last update Tue Nov  1 20:37:44 2016 yann probst
*/

#include "mylist.h"
#include "my.h"

int	num2(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  return (-1);
}

int	is_num(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  a++;
	  i++;
	}
      else
	i++;
    }
  if (a == i)
    return (0);
  else
    return (-1);
}

int	is_num2(char *str)
{
  int   i;
  int   a;
  int	taille;

  i = 1;
  a = 1;
  taille = my_strlen(str);
  if (taille > 1)
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= '0' && str[i] <= '9')
	    {
	      a++;
	      i++;
	    }
	  else
	    i++;
	}
      if (a == i)
	return (0);
      else
	return (-1);
    }
  return (-1);
}
