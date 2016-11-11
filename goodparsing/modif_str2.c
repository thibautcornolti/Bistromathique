/*
** modif_str2.c for modifstr2 in /home/probst_y/rendu/JourPiscine/CPool_evalexpr
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Sat Oct 29 15:09:14 2016 yann probst
** Last update Wed Nov  2 19:16:00 2016 Victorien Fischer
*/

#include "mylist.h"
#include "my.h"

void	replace_for_multi(char *new, char *str, int *i, int *a)
{
  new[*a] = str[*i];
  new[(*a) + 1] = '*';
  (*a) += 2;
  (*i)++;
}
