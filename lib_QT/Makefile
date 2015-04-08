##
## Makefile for nibbler in /home/koppe_m/c++/nibbler/test_qt
## 
## Made by koppe michiel
## Login   <koppe_m@epitech.net>
## 
## Started on  Sun Apr  6 22:10:51 2014 koppe michiel
## Last update Sun Apr  6 23:28:32 2014 Elliot Kersale
##

NAME		=	lib_nibbler_QT.so

CMP		=	g++

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra -Werror -fPIC

SRCS		=	src/

OBJS		=	obj/

INC		=	include/

SRC		=	$(SRCS)QtDisplay.cpp

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
