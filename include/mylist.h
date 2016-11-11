/*
** my.h for my.h in /home/probst_y/rendu/JourPiscine/CPool_evalexpr/yann
** 
** Made by yann probst
** Login   <probst_y@epitech.net>
** 
** Started on  Wed Oct 26 12:33:04 2016 yann probst
** Last update Thu Nov  3 11:09:47 2016 yann probst
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list
{
  char          *str;
  char          *nb;
  struct s_list *next;
}               t_list;

char		*eval_expr(char *);
void		replace_for_multi(char *, char *, int *, int *);
int		num2(char);
int		prioritaire(char *);
int             my_rev_list(t_list **);
t_list          *my_list_add(char *, t_list *);
char            *add_good_str(int *, char *);
t_list          *my_putinlist(char *);
int		is_num(char *);
int		is_num2(char *);
char		*modif_str(char *);
int		is_operateur(char *);
t_list          *add_in_sortie(t_list *, t_list *);
t_list          *add_in_pile(t_list *, t_list *);
int             is_parenthese(char *);
int             is_para(char *);
int             prio(char *);
char            *add_good_str(int *, char *);
char            *choose_ope(char *, char *, int *, int *);
void            operator_algo(t_list **, t_list **, t_list **);
void            put_pill_in_sortie(t_list **, t_list **);
void            rm_maillon(t_list **, t_list **);
t_list          *create_sortie(t_list *, t_list *, t_list *);
t_list          *my_putinlist(char *);
char		*put_in_modif_str(char *, char *, int *, int *);
char		*calc(t_list **);
int		num(char *);
char		*simple_calc(t_list *, t_list *, t_list *);
int		my_list_size(t_list *);
void		str_to_int_list(t_list *);
int		operateur(char);
int		operateur2(char);
void		calc_str_point(int *, int *, char *, char *);
char		*pre_parsing2(char *);
int		check_para(char *);
int		check_empty_paran(char *);
int		check_order_para(char *);
int		operateur_two(char);
int		is_sign_num(char);
char		*modif_sign(char *);
int		check_two_operateur(char *);
int		check_modulo_div_zero(char *);
int		check_oper_oper(char *);
int		check_after_para(char *);
int		check_parsing(char *);
int		is_cara_ok(char);
int		check_if_az(char *);
int		no_number(char *);
char		*remove_plus_before_para(char *);
char		*remove_beginning_plus(char *);
char		*remove_plus_after_cara(char *);
int		check_num_after_para(char *);
int		check_num_before_para(char *);
int		check_num_after_para(char *);
int		check_number_after_oper(char *);
int		check_oper_before_para(char *);
int		check_parsing_suite(char *);

#endif /* !MYLIST_H_ */
