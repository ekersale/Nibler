/*
** Sdl_display.h for nibler in /home/kersal_e/projet_actuels/cpp_nibbler/sources
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Wed Mar 19 16:49:53 2014 Elliot Kersale
// Last update Sun Apr  6 22:31:52 2014 Clement Girard
*/

#ifndef			_SDL_DISPLAY_HH__
# define		_SDL_DISPLAY_HH__

#include		<SDL/SDL.h>
#include		<SDL/SDL_ttf.h>
#include		<SDL/SDL_image.h>
#include		<SDL/SDL_mixer.h>
#include		<iostream>
#include		<sstream>
#include		<fstream>
#include		<string>
#include		"IDisplay.hh"

# define		AMBIANCE		"./sons/ambiance.wav"
# define		EAT			"./sons/eat.wav"
# define		LOOSE			"./sons/looser.wav"
# define		BACKGROUND		"./img/background.jpg"
# define		POLICE			"./img/police.ttf"
# define		DHEAD			"./img/head.png"
# define		DBODY			"./img/body.png"
# define		DFOOD			"./img/apple.png"

class			Sdldisplay : public IDisplay
{
public:
  Sdldisplay();
  Sdldisplay(const Sdldisplay &);
  ~Sdldisplay();


  int			getKey();
  int			initWindow(const int, const int);
  void			clearScreen();
  int			loadItem(const int, const int, const Item);
  int			gameOver(const int);
  int			music();
  void			soundEat();
  void			soundLoose();
  Sdldisplay		&operator=(const Sdldisplay &);
  
private:
  SDL_Surface		*screen;
  bool			quit;
  Mix_Chunk		*sound_eat;
  Mix_Chunk		*sound_loose;
  Mix_Music		*sound_music;
  SDL_Surface		*background;
};

#endif
//EOF _SDL_DISPLAY_HH__
