/*
** create_list_chained.c for create liste chainey in /home/probst_y/rendu/JourPiscine/CPool_evalexpr/yann
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Thu Oct 27 16:36:45 2016 yann probst
** Last update Fri Oct 28 16:13:39 2016 yann probst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

void		operator_algo(t_list **pile, t_list **entree, t_list **sortie)
{
  t_list	*tmp;

  while (*pile && (is_operateur((*pile)->str) == 0 &&
		   (prioritaire((*entree)->str) <=  prioritaire((*pile)->str))))
    {
      *sortie = add_in_sortie(*sortie, *pile);
      tmp = *pile;
      (*pile) = (*pile)->next;
      free(tmp);
    }
  *pile = add_in_pile(*pile, *entree);
}

void		put_pill_in_sortie(t_list **pile, t_list **sortie)
{
  while (*pile != NULL)
    {
      if (is_operateur((*pile)->str) == 0)
	{
	  *sortie = add_in_sortie(*sortie, *pile);
	  *pile = (*pile)->next;
	}
      else
	  *pile = (*pile)->next;
    }
}

void		rm_maillon(t_list **tmp, t_list **pile)
{
  *tmp = *pile;
  *pile = (*pile)->next;
  free(*tmp);
}

t_list		*create_sortie(t_list *entree, t_list *sortie, t_list *pile)
{
  t_list	*tmp;

  while (entree != NULL)
    {
      if (is_num(entree->str) == 0 || is_num2(entree->str) == 0)
	sortie = add_in_sortie(sortie, entree);
      else if (my_strcmp(entree->str, "(") == 0)
	pile = add_in_pile(pile, entree);
      else if (is_operateur(entree->str) == 0)
	operator_algo(&pile, &entree, &sortie);
      else if (my_strcmp(entree->str, ")") == 0)
	{
	  while (my_strcmp(pile->str, "(") != 0)
	    {
	      sortie = add_in_sortie(sortie, pile);
	      rm_maillon(&tmp, &pile);
	    }
	  rm_maillon(&tmp, &pile);
	}
      entree = entree->next;
    }
  if (entree == NULL)
    put_pill_in_sortie(&pile, &sortie);
  return (sortie);
}

t_list		*my_putinlist(char *strbase)
{
  t_list	*entree;
  t_list	*sortie;
  t_list	*pile;
  int		i;
  char		*str;

  i = 0;
  entree = NULL;
  sortie = NULL;
  pile = NULL;
  while ((str = add_good_str(&i, strbase)) != NULL)
    entree = my_list_add(str, entree);
  my_rev_list(&entree);
  sortie = create_sortie(entree, sortie, pile);
  my_rev_list(&sortie);
  return (sortie);
}
