# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:16:54 by mcha              #+#    #+#              #
#    Updated: 2022/06/14 12:11:43 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################################
##																		##
##								Basic									##
##																		##
##########################################################################
CC			= gcc
CFLAGS		= -I $(HEAD_ROOT) -Wall -Werror -Wextra -g3 -fsanitize=address
LFLAGS		= -lmlx -framework OpenGL -framework AppKit


##########################################################################
##																		##
##								Dependency								##
##																		##
##########################################################################
NAME		= cub3D
LIBFT		= libft/libft.a
MLIBX		= minilibx_opengl/libmlx.a
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
MLIB_ROOT	= minilibx_opengl
PARS_ROOT	= $(SRCS_ROOT)/parse
LIBM_ROOT	= $(SRCS_ROOT)/mlx
RAYC_ROOT	= $(SRCS_ROOT)/raycast
FREE_ROOT	= $(SRCS_ROOT)/free


##########################################################################
##																		##
##							Source Directory							##
##					* Add Directory path at vpath						##
##					* _P_ = Parse										##
##					* _E_ = Execute										##
##					* _M_ = Mlx											##
##																		##
##########################################################################
SRCS_MAIN	= $(SRCS_ROOT)/main
SRCS_FREE	= $(SRCS_ROOT)/free
SRCS_P_ERRO	= $(PARS_ROOT)/error
SRCS_P_CHEK	= $(PARS_ROOT)/check
SRCS_P_STRT	= $(PARS_ROOT)/struct
SRCS_P_PROC	= $(PARS_ROOT)/proc
SRCS_P_GETN	= $(PARS_ROOT)/gnl
SRCS_P_BIND	= $(PARS_ROOT)/bind
SRCS_M_PROC	= $(LIBM_ROOT)/proc
SRCS_M_CHEK	= $(LIBM_ROOT)/check
SRCS_M_BIND	= $(LIBM_ROOT)/bind
SRCS_M_FREE	= $(LIBM_ROOT)/free
SRCS_R_INIT	= $(RAYC_ROOT)/init
SRCS_R_EVNT	= $(RAYC_ROOT)/event
SRCS_R_DRAW	= $(RAYC_ROOT)/draw

vpath %.c	$(SRCS_MAIN) \
			$(SRCS_FREE) \
			$(SRCS_P_ERRO) \
			$(SRCS_P_CHEK) \
			$(SRCS_P_STRT) \
			$(SRCS_P_PROC) \
			$(SRCS_P_GETN) \
			$(SRCS_P_BIND) \
			$(SRCS_M_PROC) \
			$(SRCS_M_CHEK) \
			$(SRCS_M_BIND) \
			$(SRCS_M_FREE) \
			$(SRCS_R_INIT) \
			$(SRCS_R_EVNT) \
			$(SRCS_R_DRAW)


##########################################################################
##																		##
##								Source File								##
##																		##
##########################################################################
FILE_MAIN	= $(notdir $(wildcard $(SRCS_MAIN)/*.c))
FILE_FREE	= $(notdir $(wildcard $(SRCS_FREE)/*.c))
FILE_P_ERRO	= $(notdir $(wildcard $(SRCS_P_ERRO)/*.c))
FILE_P_CHEK = $(notdir $(wildcard $(SRCS_P_CHEK)/*.c))
FILE_P_STRT = $(notdir $(wildcard $(SRCS_P_STRT)/*.c))
FILE_P_FREE = $(notdir $(wildcard $(SRCS_P_FREE)/*.c))
FILE_P_PROC	= $(notdir $(wildcard $(SRCS_P_PROC)/*.c))
FILE_P_GETN	= $(notdir $(wildcard $(SRCS_P_GETN)/*.c))
FILE_P_BIND	= $(notdir $(wildcard $(SRCS_P_BIND)/*.c))
FILE_M_PROC = $(notdir $(wildcard $(SRCS_M_PROC)/*.c))
FILE_M_CHEK = $(notdir $(wildcard $(SRCS_M_CHEK)/*.c))
FILE_M_BIND	= $(notdir $(wildcard $(SRCS_M_BIND)/*.c))
FILE_M_FREE	= $(notdir $(wildcard $(SRCS_M_FREE)/*.c))
FILE_R_INIT	= $(notdir $(wildcard $(SRCS_R_INIT)/*.c))
FILE_R_EVNT	= $(notdir $(wildcard $(SRCS_R_EVNT)/*.c))
FILE_R_DRAW	= $(notdir $(wildcard $(SRCS_R_DRAW)/*.c))


##########################################################################
##																		##
##								Object File								##
##																		##
##########################################################################
OBJ_MAIN	= $(FILE_MAIN:.c=.o)
OBJ_FREE	= $(FILE_FREE:.c=.o)
OBJ_P_ERRO	= $(FILE_P_ERRO:.c=.o)
OBJ_P_CHEK	= $(FILE_P_CHEK:.c=.o)
OBJ_P_STRT	= $(FILE_P_STRT:.c=.o)
OBJ_P_PROC	= $(FILE_P_PROC:.c=.o)
OBJ_P_GETN	= $(FILE_P_GETN:.c=.o)
OBJ_P_BIND	= $(FILE_P_BIND:.c=.o)
OBJ_M_PROC	= $(FILE_M_PROC:.c=.o)
OBJ_M_CHEK	= $(FILE_M_CHEK:.c=.o)
OBJ_M_BIND	= $(FILE_M_BIND:.c=.o)
OBJ_M_FREE	= $(FILE_M_FREE:.c=.o)
OBJ_R_INIT	= $(FILE_R_INIT:.c=.o)
OBJ_R_EVNT	= $(FILE_R_EVNT:.c=.o)
OBJ_R_DRAW	= $(FILE_R_DRAW:.c=.o)


##########################################################################
##																		##
##							Integrated object File						##
##																		##
##########################################################################
OBJ_PARSE	:= $(OBJ_P_ERRO) $(OBJ_P_CHEK) $(OBJ_P_STRT) $(OBJ_P_PROC) $(OBJ_P_GETN) $(OBJ_P_BIND)
OBJ_RAYC	:= $(OBJ_R_INIT) $(OBJ_R_EVNT) $(OBJ_R_DRAW)
OBJ_MLX		:= $(OBJ_M_PROC) $(OBJ_M_CHEK) $(OBJ_M_BIND) $(OBJ_M_FREE)
OBJ 		:= $(OBJ_MAIN) $(OBJ_FREE) $(OBJ_PARSE) $(OBJ_RAYC) $(OBJ_MLX)
OBJ 		:= $(addprefix $(OBJS_ROOT)/, $(OBJ))


$(OBJS_ROOT)/%.o : %.c
	@echo "[~] Linking $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	@echo "[+] Create libft"
	@make -s -C $(LIBF_ROOT)
	@echo "[+] Create minilibx_opengl"
	@make -s -C $(MLIB_ROOT)
	@echo "[+] Create cub3D"
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $(OBJ) $(LIBFT) -L $(MLIB_ROOT)


##########################################################################
##																		##
##								  Commands								##
##																		##
##########################################################################
all : $(NAME)

clean :
	@$(RM) $(OBJ)
	@echo "[-] Delete object files"
	@make clean -s -C $(LIBF_ROOT)
	@echo "[-] Delete libft object files"
	@make clean -s -C $(MLIB_ROOT)
	@echo "[-] Delete minilibx_opengl"

fclean : clean
	@echo "[-] Delete run files"
	@$(RM) $(NAME)
	@echo "[-] Delete libft"
	@make fclean -s -C $(LIBF_ROOT)

re : 
	make fclean
	make all

.PHONY : all clean fclean re