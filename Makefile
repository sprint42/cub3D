# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:16:54 by mcha              #+#    #+#              #
#    Updated: 2022/06/06 16:26:06 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################################
##																		##
##								Basic									##
##																		##
##########################################################################
CC			= gcc
CFLAGS		= -I $(HEAD_ROOT) -Wall -Werror -Wextra -g3 -fsanitize=address


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
SRCS_P_PROC	= $(PARS_ROOT)/proc
SRCS_P_GETN	= $(PARS_ROOT)/gnl
SRCS_P_BIND	= $(PARS_ROOT)/bind

vpath %.c	$(SRCS_MAIN) \
			$(SRCS_P_ERRO) \
			$(SRCS_P_CHEK) \
			$(SRCS_P_STRT) \
			$(SRCS_P_FREE) \
			$(SRCS_P_PROC) \
			$(SRCS_P_GETN) \
			$(SRCS_P_BIND) \


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
FILE_P_PROC	= $(notdir $(wildcard $(SRCS_P_PROC)/*.c))
FILE_P_GETN	= $(notdir $(wildcard $(SRCS_P_GETN)/*.c))
FILE_P_BIND	= $(notdir $(wildcard $(SRCS_P_BIND)/*.c))



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
OBJ_P_PROC	= $(FILE_P_PROC:.c=.o)
OBJ_P_GETN	= $(FILE_P_GETN:.c=.o)
OBJ_P_BIND	= $(FILE_P_BIND:.c=.o)



##########################################################################
##																		##
##							Integrated object File						##
##																		##
##########################################################################
OBJ_PARSE	:= $(OBJ_P_ERRO) $(OBJ_P_CHEK) $(OBJ_P_STRT) $(OBJ_P_FREE) $(OBJ_P_PROC) $(OBJ_P_GETN) $(OBJ_P_BIND)
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