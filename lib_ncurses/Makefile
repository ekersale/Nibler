##
## Makefile for nibbler in /home/girard_g/Dropbox/nib/new_nib_by_elliot_si_ce_n_est_pas_clair/lib_ncurses
## 
## Made by Clement Girard
## Login   <girard_g@epitech.net>
## 
## Started on  Sun Apr  6 13:53:53 2014 Clement Girard
## Last update Sun Apr  6 19:33:01 2014 Clement Girard
##

NAME		=	lib_nibbler_ncurses.so

CMP		=	g++

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra -Werror -fPIC

LDFLAGS		+=	-lncurses

SRCS		=	src/

OBJS		=	obj/

INC		=	include/

SRC		=	$(SRCS)Ncurses.cpp	\

OBJ		=	$(SRC:$(SRCS)%.cpp=$(OBJS)%.o)

all		:	$(NAME)

$(OBJS)%.o	:	$(SRCS)%.cpp
			$(CMP) $(CFLAGS) $(LDFLAGS) -c -I$(INC) -o $@ $<


$(NAME)		:	$(OBJ)
			$(CMP) -shared $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

clean		:
			$(RM)		\#*\#
			$(RM)		*~
			$(RM)		$(INC)*~
			$(RM)		$(INC)\#*\#
			$(RM)		$(SRCS)*~
			$(RM)		$(SRCS)\#*\#

fclean		:	clean
			$(RM)		$(NAME)

re		:	fclean all

.PHONY		:	all clean re
