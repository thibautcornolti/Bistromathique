/*
** main.c for bistro in /home/thibrex/delivery/CPool_bistro-matic
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Oct 26 09:35:34 2016 Thibaut Cornolti
** Last update Sun Nov  6 22:00:08 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include <unistd.h>
#include "macro.h"
#include "my.h"
#include "utils.h"
#include "check.h"
#include "mylist.h"

static int	print_help(char *name)
{
  my_putstr("USAGE\n");
  my_putstr("           ");
  my_putstr(name);
  my_putstr(" base operators size_read\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("           base      all the symbols of the base\n");
  my_putstr("           operators the symbols for the ");
  my_putstr("parentheses and the 5 operators\n");
  my_putstr("           size_read number of characters to be read\n");
  return (EXIT_SUCCESS);
}

static int	print_usage(char *name)
{
  my_puterror("Usage: ");
  my_puterror(name);
  my_puterror(" base ops \"()");
  my_puterror("+");
  my_puterror("-*/%\" exp_len\n");
  return (EXIT_USAGE);
}

int		main(int ac, char **av)
{
  char		*expr;
  char		*result;

  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
    return (print_help(av[0]));
  else if (ac != 4)
    return (print_usage(av[0]));
  check_base(av[1], av[2]);
  check_ops(av[2]);
  expr = get_expr(my_getnbr(av[3]));
  check_expr(expr, av[1], av[2]);
  my_convert_expr_base(&expr, av[1], "0123456789", av[2]);
  result = eval_expr(expr);
  free(expr);
  expr = NULL;
  result = convert_base_str2(result, "0123456789", av[1], av[2]);
  result[0] = (result[0] == '-') ? av[2][3] : result[0];
  my_putstr(result);
  result = NULL;
  return (EXIT_SUCCESS);
}
