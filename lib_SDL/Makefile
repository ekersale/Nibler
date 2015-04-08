##
## Makefile for epikong in /home/kersal_e/rush-epikong
## 
## Made by Elliot Kersale
## Login   <kersal_e@epitech.net>
## 
## Started on  Fri Mar  7 20:47:19 2014 Elliot Kersale
## Last update Sun Apr  6 02:12:11 2014 Elliot Kersale
##

NAME            =	lib_nibbler_SDL.so

CMP             =	g++

RM              =	rm -f

CFLAGS          +=	-W -Wall -Wextra -Werror -fPIC

LDFLAGS         +=	-lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer

SRCS            =	src/

OBJS            =	obj/

INC             =	include/

SRC             =	$(SRCS)Sdl_display.cpp

OBJ             =	$(SRC:$(SRCS)%.cpp=$(OBJS)%.o)

all             :	$(NAME)

$(OBJS)%.o      :	$(SRCS)%.cpp
			$(CMP) $(CFLAGS) $(LDFLAGS) -c -I$(INC) -o $@ $<


$(NAME)         :	$(OBJ)
			$(CMP) -shared $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

clean           :
			$(RM)		\#*\#
			$(RM)		*~
			$(RM)		$(INC)*~
			$(RM)		$(INC)\#*\#
			$(RM)		$(SRCS)*~
			$(RM)		$(SRCS)\#*\#

fclean          :	clean
			$(RM)           $(NAME)

re              :       fclean all
