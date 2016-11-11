##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Sat Nov  5 22:05:22 2016 Thibaut Cornolti
##

SRC	=	main.c					\
		function/add.c				\
		function/divi.c				\
		function/mod.c				\
		function/mul.c				\
		function/sub.c				\
		utils/pre_check.c			\
		utils/infin_add.c			\
		utils/infin_cmp.c			\
		utils/infin_div.c			\
		utils/infin_mod.c			\
		utils/infin_mul.c			\
		utils/infin_sub.c			\
		utils/my_getnbr_base_str.c		\
		utils/utils.c				\
		utils/utils_is.c			\
		utils/utils_remove.c			\
		utils/convert_operators.c		\
		utils/convert_base_str.c		\
		utils/convert_expr.c			\
		goodparsing/eval_expr.c			\
		goodparsing/my_rev_list.c		\
		goodparsing/basic.c			\
		goodparsing/modif_str.c			\
		goodparsing/add_and_show_list.c		\
		goodparsing/prio_and_para.c		\
		goodparsing/create_list_chained.c	\
		goodparsing/calc.c			\
		goodparsing/my_list_size.c		\
		goodparsing/simple_calc.c		\
		goodparsing/tools.c			\
		goodparsing/modif_str2.c		\
		goodparsing/pre_parsing.c		\
		goodparsing/is_operateur.c		\
		goodparsing/check_sign.c		\
		goodparsing/check_oper.c		\
		goodparsing/remove.c			\
		goodparsing/check_oper2.c		\
		goodparsing/check_after_para.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	calc

CC	=	gcc

HEADER	=	include/

RM	=	rm -f

LIB_P	=	lib/my

LIB	=	my

all:	$(NAME)

$(NAME):	makelib
	$(CC) -o $(NAME) -I $(HEADER) $(SRC) -L$(LIB_P) -l$(LIB) -Wall -Wextra -pedantic

makelib:
	cd lib/my/ && make

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
