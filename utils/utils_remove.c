/*
** utils_remove.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/utils
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Mon Oct 31 13:09:51 2016 Victorien Fischer
** Last update Fri Nov  4 10:36:59 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "my_infin.h"
#include "utils.h"
#include "macro.h"

char	*inser_char_wm(char *str, char c, int pos)
{
  int	pos2;

  pos2 = my_strlen(str);
  while (pos2 > pos)
    {
      str[pos2 + 1] = str[pos2];
      pos2 -= 1;
    }
  str[pos] = c;
  return (str);
}

char	*remove_char(char *str, int pos)
{
  while (str[pos] != 0)
    {
      str[pos] = str[pos + 1];
      pos += 1;
    }
  return (str);
}

char	*clean_digit_base(char *str)
{
  int	i;
  int	s;

  i = 0;
  while (str[i] != 0 && str[i + 1] != 0)
    {
      if ((i == 0 || my_str_contains(str[i - 1], "()+-*/%")) &&
	  str[i + 1] >= '0' && str[i + 1] <= '9' && str[i] == '0')
	{
	  s = i;
	  while (is_space(str[++s]) && s != -1)
	    if (!is_an_operator(str[s + 1]))
	      exit(my_puterror(SYNTAX_ERROR_MSG) + EXIT_EXPR);
	  remove_char(str, i);
	}
      else
	i += 1;
    }
  return (str);
}

char	*remove_zeros(char *str)
{
  while (*str == '0' && *(str + 1) != 0)
    str += 1;
  return (str);
}

char	*remove_spaces(char *input)
{
  char	*output;
  int	count;
  int	index;
  int	len;
  char	tmp;

  len = my_strlen(input);
  if ((output = malloc(sizeof(*output) * (len + 1))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  count = -1;
  while (++count < len)
    output[count] = 0;
  count = -1;
  index = -1;
  while (input[++count] != 0)
    if (!is_space(input[count]))
      {
	tmp = input[count];
	if (count > 0)
	  if (c_is_an(output[index]) && is_space(input[count - 1]) && c_is_an(tmp))
	    exit(EXIT_EXPR + my_puterror(SYNTAX_ERROR_MSG) * 0);
	output[++index] = tmp;
      }
  output[++index] = 0;
  return (output);
}
