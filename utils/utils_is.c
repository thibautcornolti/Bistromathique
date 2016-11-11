/*
** utils_is.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/utils
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Thu Nov  3 19:55:17 2016 Victorien Fischer
** Last update Fri Nov  4 10:42:13 2016 Thibaut Cornolti
*/

int	c_is_an(char c)
{
  if ((c >= 'a' && c <= 'z')
	  || (c >= 'A' && c <= 'Z')
	  || (c >= '0' && c<= 'z'))
    return (1);
  return (0);
}

int	is_space(char c)
{
  return (c == ' ' || c == '\t');
}

int	is_an_operator(char c)
{
  if (c == '+' || c == '-' || c == '*'||
      c == '/' || c == '%')
    return (1);
  return (0);
}
