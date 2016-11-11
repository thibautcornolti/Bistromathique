/*
** infin_mod.c for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/utils
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Wed Oct 26 12:02:47 2016 Victorien Fischer
** Last update Mon Oct 31 15:32:56 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my_operators.h"

char	*my_infin_mod(char *nb1, char *nb2)
{
  char	*result;
  char	*tmp;
  char	*tmp2;

  tmp = divi(nb1, nb2);
  tmp2 = mul(tmp, nb2);
  result = sub(nb1, tmp2);
  return (result);
}
