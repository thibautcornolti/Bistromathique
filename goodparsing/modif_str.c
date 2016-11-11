/*
** test.c for probst in /home/probst_y
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Thu Oct 27 10:06:00 2016 yann probst
** Last update Sat Nov  5 22:14:44 2016 yann probst
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"
#include "my.h"
#include "macro.h"

char	*put_in_modif_str(char *new, char *str, int *i, int *a)
{
  if (str[*i] == '-' && str[(*i) + 1] == '(')
    {
      new[*a] = str[*i];
      new[(*a) + 1] = '1';
      new[(*a) + 2] = '*';
      (*a) += 3;
      (*i)++;
    }
  else if (str[*i] == ')' && num2(str[*i + 1]) == 0)
    replace_for_multi(new, str, i, a);
  else
    new[(*a)++] = str[(*i)++];
  return (new);
}

char	*modif_str(char *str)
{
  char	*new;
  int	i;
  int	a;

  a = 0;
  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) * 2))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  while (str[i] != '\0')
    new = put_in_modif_str(new, str, &i, &a);
  new[a] = '\0';
  return (new);
}

void		calc_str_point(int *a, int *i, char *str, char *new)
{
  new[*a] = str[(*i)];
  (*a)++;
  (*i)++;
  while ((str[*i] >= '0' && str[*i] <= '9'))
    {
      new[*a] = str[(*i)];
      (*i)++;
      (*a)++;
    }
}

char		*choose_ope(char *str, char *new, int *i, int *a)
{
  if (str[*i] == '-' && *i == 0)
    {
      while ((str[*i] >= '0' && str[*i] <= '9') || (*i == 0))
	{
	  new[*a] = str[*i];
	  (*i)++;
	  (*a)++;
	}
    }
  else if (str[*i] == '-' && *i > 0 && str[(*i) - 1] == '(')
    calc_str_point(a, i, str, new);
  else if (str[*i] == '-' && i != 0 && operateur(str[*i - 1]) == 0)
    {
      while ((str[*i] >= '0' && str[*i] <= '9') || operateur(str[*i - 1]) == 0)
	{
	  new[(*a)] = str[*i];
	  (*i)++;
	  (*a)++;
	}
    }
  else
    new[(*a)++] = str[(*i)++];
  return (new);
}

char		*add_good_str(int *i, char *str)
{
  char		*new;
  char		*clean;
  int		a;

  while (str[*i] != '\0')
    {
      a = 0;
      if ((new = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
	exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
      if (str[*i] >= '0' && str[*i] <= '9')
	{
	  while ((str[*i] >= '0' && str[*i] <= '9'))
	    new[a++] = str[(*i)++];
	}
      else
	new = choose_ope(str, new, i, &a);
      new[a] = '\0';
      clean = my_strdup(new);
      free(new);
      return (clean);
    }
  return (NULL);
}
