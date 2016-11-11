/*
** add_and_show_list.c for add_and_show_list in /home/probst_y/rendu/JourPiscine/CPool_evalexpr/yann
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Thu Oct 27 10:38:35 2016 yann probst
** Last update Fri Nov  4 10:29:55 2016 Thibaut Cornolti
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "macro.h"

t_list		*my_list_add(char *str, t_list *list)
{
  t_list	*entree;

  if ((entree = malloc(sizeof(t_list))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  entree->str = str;
  entree->nb = 0;
  entree->next = list;
  return (entree);
}

t_list		*add_in_sortie(t_list *sortie, t_list *entree)
{
  t_list	*test;

  if ((test = malloc(sizeof(t_list))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  test->str = entree->str;
  test->nb = 0;
  test->next = sortie;
  return (test);
}

t_list		*add_in_pile(t_list *pile, t_list *entree)
{
  t_list	*test;

  if ((test = malloc(sizeof(t_list))) == NULL)
    exit(my_puterror(ERROR_MSG) * 0 + EXIT_MALLOC);
  test->str = entree->str;
  test->nb = 0;
  test->next = pile;
  return (test);
}
