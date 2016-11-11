/*
** infin_cmp.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/utils
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 26 11:46:26 2016 Victorien Fischer
** Last update Mon Oct 31 15:25:22 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_infin_cmp(char *nbr1, char *nbr2)
{
  int	len1;
  int	len2;

  len1 = my_strlen(nbr1);
  len2 = my_strlen(nbr2);
  if (len1 > len2)
    return (1);
  else if (len1 < len2)
    return (-1);
  else
    return (my_strcmp(nbr1, nbr2));
  return (0);
}
