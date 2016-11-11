/*
** pre_check.c for bistro in /home/thibrex/delivery/CPool_bistro-matic
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Nov  1 20:12:15 2016 Thibaut Cornolti
** Last update Sun Nov  6 21:59:07 2016 Thibaut Cornolti
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"
#include "macro.h"

void	check_double_char_str(char *str, int error)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_MALLOC + 0 * my_puterror(ERROR_MSG));
  my_memset_str(new, 0, my_strlen(str) + 1);
  while (str[i] != 0)
    {
      if (my_str_contains(str[i], new) == 1)
	{
	  my_puterror(SYNTAX_ERROR_MSG);
	  exit(error);
	}
      new[i] = str[i];
      i += 1;
    }
  free(new);
}

void	check_expr(char *expr, char *base, char *ops)
{
  int	i;

  check_double_char_str(ops, EXIT_EXPR);
  i = 0;
  while (expr[i] != 0)
    {
      if (my_str_contains(expr[i], ops) == 0 &&
	  my_str_contains(expr[i], base) == 0)
	{
	  my_puterror(SYNTAX_ERROR_MSG);
	  exit(EXIT_EXPR);
	}
      i += 1;
    }
}

void	check_base(char *base, char *ops)
{
  int	i;

  check_double_char_str(base, EXIT_BASE);
  i = -1;
  if (my_strlen(base) < 2)
    {
      my_puterror(SYNTAX_ERROR_MSG);
      exit(EXIT_BASE);
    }
  while (base[++i])
    if (my_str_contains(base[i], ops))
      {
	my_puterror(SYNTAX_ERROR_MSG);
	exit(EXIT_BASE);
      }
}

void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_puterror(SYNTAX_ERROR_MSG);
      exit(EXIT_OPS);
    }
}

char	*get_expr(int size)
{
  char	*expr;

  if (size <= 0)
    {
      my_puterror(SYNTAX_ERROR_MSG);
      exit(EXIT_SIZE_NEG);
    }
  if ((expr = malloc(sizeof(char) * (size + 1))) == NULL)
    {
      my_puterror(ERROR_MSG);
      exit(EXIT_MALLOC);
    }
  if (expr == 0)
    {
      my_puterror(ERROR_MSG);
      exit(EXIT_MALLOC);
    }
  if (read(0, expr, size) != size)
    {
      my_puterror(ERROR_MSG);
      exit(EXIT_READ);
    }
  expr[size] = 0;
  return (expr);
}
