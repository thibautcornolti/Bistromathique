/*
** my_strlen.c for my_strlen in //home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Thu Oct  6 10:42:10 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:29:49 2016 yann probst
*/

int	my_strlen(char *str)
{
  int	lenght;

  lenght = 0;
  while (*str != 0)
    {
      str += 1;
      lenght += 1;
    }
  return (lenght);
}
