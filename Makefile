# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:16:54 by mcha              #+#    #+#              #
#    Updated: 2022/06/03 18:37:49 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################################
##																		##
##								Basic									##
##																		##
##########################################################################
CC			= gcc
CFLAGS		= -I $(HEAD_ROOT) -Wall -Werror -Wextra


##########################################################################
##																		##
##								Dependency								##
##																		##
##########################################################################
NAME		= cub3D
LIBFT		= libft/libft.a
RM			= rm -rf


##########################################################################
##																		##
##							  Root Directory							##
##																		##
##########################################################################
OBJS_ROOT	= obj
SRCS_ROOT	= src
LIBF_ROOT	= libft
HEAD_ROOT	= include
PARS_ROOT	= $(SRCS_ROOT)/parse


##########################################################################
##																		##
##							Source Directory							##
##					* Add Directory path at vpath						##
##					* _P_ = Parse										##
##					* _E_ = Execute										##
##																		##
##########################################################################
SRCS_MAIN	= $(SRCS_ROOT)/main
SRCS_P_ERRO	= $(PARS_ROOT)/error
SRCS_P_CHEK	= $(PARS_ROOT)/check
SRCS_P_STRT	= $(PARS_ROOT)/struct
SRCS_P_FREE	= $(PARS_ROOT)/free

vpath %.c	$(SRCS_MAIN) \
			$(SRCS_P_ERRO) \
			$(SRCS_P_CHEK) \
			$(SRCS_P_STRT) \
			$(SRCS_P_FREE) \


##########################################################################
##																		##
##								Source File								##
##																		##
##########################################################################
FILE_MAIN	= $(notdir $(wildcard $(SRCS_MAIN)/*.c))
FILE_P_ERRO	= $(notdir $(wildcard $(SRCS_P_ERRO)/*.c))
FILE_P_CHEK = $(notdir $(wildcard $(SRCS_P_CHEK)/*.c))
FILE_P_STRT = $(notdir $(wildcard $(SRCS_P_STRT)/*.c))
FILE_P_FREE = $(notdir $(wildcard $(SRCS_P_FREE)/*.c))



##########################################################################
##																		##
##								Object File								##
##																		##
##########################################################################
OBJ_MAIN	= $(FILE_MAIN:.c=.o)
OBJ_P_ERRO	= $(FILE_P_ERRO:.c=.o)
OBJ_P_CHEK	= $(FILE_P_CHEK:.c=.o)
OBJ_P_STRT	= $(FILE_P_STRT:.c=.o)
OBJ_P_FREE	= $(FILE_P_FREE:.c=.o)



##########################################################################
##																		##
##							Integrated object File						##
##																		##
##########################################################################
OBJ_PARSE	:= $(OBJ_P_ERRO) $(OBJ_P_CHEK) $(OBJ_P_STRT) $(OBJ_P_FREE)
OBJ 		:= $(OBJ_MAIN) $(OBJ_PARSE)
OBJ 		:= $(addprefix $(OBJS_ROOT)/, $(OBJ))


$(OBJS_ROOT)/%.o : %.c
	@echo "[~] Linking $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	@echo "[+] Create libft"
	@make -s -C $(LIBF_ROOT)
	@echo "[+] Create cub3D"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)


##########################################################################
##																		##
##								  Commands								##
##																		##
##########################################################################
all : $(NAME)

clean :
	@$(RM) $(OBJ)
	@echo "[-] Delete object files"

fclean : clean
	@echo "[-] Delete run files"
	@$(RM) $(NAME)
	@echo "[-] Delete libft"
	@make fclean -s -C $(LIBF_ROOT)

re : 
	make fclean
	make all

.PHONY : all clean fclean re