##
## Makefile for nibbler in /home/kersal_e/Dropbox/nib/rendu
## 
## Made by Elliot Kersale
## Login   <kersal_e@epitech.net>
## 
## Started on  Sun Apr  6 23:01:52 2014 Elliot Kersale
## Last update Sun Apr  6 23:32:56 2014 Clement Girard
##

NAME 		= 	nibbler

SRC 		= 	./src/Core.cpp		\
			./src/DLLoader.cpp	\
			./src/main.cpp

OBJ 		= 	$(SRC:.cpp=.o)

CC 		=	g++

CPPFLAGS 	= 	-W -Wall -Wextra -Werror -I./include/

LDFLAGS		= 	-ldl

LIB1 		=	SDL

LIB2 		=	QT

LIB3		=	ncurses

RM		=	rm -f

MAKE		=	make -sC


all		:	$(NAME)

$(NAME) 	:	$(OBJ)
			$(MAKE) lib_ncurses
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)
			$(MAKE) lib_SDL
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)
			$(MAKE) lib_QT
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

clean 		:
			$(MAKE) lib_ncurses clean
			$(MAKE) lib_SDL clean
			$(MAKE) lib_QT clean
			$(RM) ./src/*.o *~

fclean 		: 	clean
			$(MAKE) lib_ncurses fclean
			$(MAKE) lib_SDL fclean
			$(MAKE) lib_QT fclean
			$(RM) $(NAME)

re 		:	fclean all
