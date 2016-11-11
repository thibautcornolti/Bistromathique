/*
** utils.h for bistro in /home/fischerv/delivery/CPool/CPool_bistro-matic/include
** 
** Made by Victorien Fischer
** Login   <fischerv@epitech.net>
** 
** Started on  Mon Oct 31 13:13:04 2016 Victorien Fischer
** Last update Sun Nov  6 22:07:29 2016 yann probst
*/

#ifndef UTILS_H_
# define UTILS_H_

char	*inser_char(char **, char, int);
int	my_strtol(char *, int *);
int	is_an_operator(char);
int	c_is_an(char);
int	is_space(char);
char	*remove_spaces(char *);
char	*remove_zeros(char *);
char	my_convert_operators(char, char *);
char	*remove_char(char *, int);
char	*clean_digit_base(char *);
char	*get_expr(int);
char	**my_convert_expr_base(char **, char *, char *, char *);
char	*convert_base_str(char *, char *, char *, char *);
int	are_correct_operandes(char *, char *);
char	*my_getnbr_base_str(char *, char *, char *);
char	*convert_base_str2(char *, char *, char *, char *);

#endif /* !UTILS_H_ */
