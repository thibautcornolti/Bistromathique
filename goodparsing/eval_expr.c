/*
** test.c for test in /home/probst_y
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Tue Oct 25 22:24:58 2016 yann probst
** Last update Sat Nov  5 22:22:41 2016 yann probst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "macro.h"

void	add_parenthese_cond(char *str, char *new, int t[3], int *nb)
{
  if ((str[t[0]] == '%' || str[t[0]] == '/') && (str[(t[0]) + 1] == '-'))
    {
      new[(t[1])] = str[(t[0])];
      (t[1])++;
      (t[0])++;
      new[t[1]] = '(';
      (t[1])++;
      while ((*nb) != 0 && str[t[0]] != '\0')
	{
	  if (str[t[0]] == '(')
	    (*nb)++;
	  else if (str[t[0]] == ')')
	    (*nb)--;
	  new[(t[1])++] = str[(t[0])++];
	}
      new[t[1]] = ')';
      (t[1])++;
    }
  new[(t[1])++] = str[(t[0])++];
}

char	*add_parenthese(char *str)
{
  int	t[3];
  int	nb;
  int	len;
  char	*new;

  t[0] = 0;
  t[1] = 0;
  nb = 1;
  len = my_strlen(str);
  if ((new = malloc(sizeof(char) * (len * 2))) == NULL)
    {
      my_puterror(ERROR_MSG);
      exit(EXIT_MALLOC);
    }
  my_memset_str(new, 0, (len * 2));
  while (t[0] < len)
    add_parenthese_cond(str, new, t, &nb);
  new[t[1]] = '\0';
  return (new);
}


char		*eval_expr(char *arg)
{
  char		*str;
  t_list	*sortie;
  char		*res;

  if (check_if_az(arg) == -1)
    exit(EXIT_EXPR + my_puterror(SYNTAX_ERROR_MSG));
  if (no_number(arg) == -1)
    exit(EXIT_EXPR + my_puterror(SYNTAX_ERROR_MSG));
  str = pre_parsing2(arg);
  str = remove_plus_before_para(str);
  if (check_num_after_para(str) == -1)
    exit(EXIT_EXPR + my_puterror(SYNTAX_ERROR_MSG));
  str = add_parenthese(str);
  str = modif_str(str);
  str = remove_beginning_plus(str);
  str = remove_plus_after_cara(str);
  if (check_parsing(str) == -1)
    exit(EXIT_EXPR + my_puterror(SYNTAX_ERROR_MSG));
  sortie = my_putinlist(str);
  res = calc(&sortie);
  if (res[0] == '-' && res[1] == '0' && res[2] == '\0')
    return (++res);
  return (res);
}
