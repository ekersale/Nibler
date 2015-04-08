//
// Ncurses.hpp for nibbler in /home/girard_g/Dropbox/nib/new_nib_by_elliot_si_ce_n_est_pas_clair/lib_ncurses/include
// 
// Made by Clement Girard
// Login   <girard_g@epitech.net>
// 
// Started on  Sun Apr  6 13:54:14 2014 Clement Girard
// Last update Sun Apr  6 22:19:46 2014 Clement Girard
//

#ifndef		_NCURSES_HPP_
# define	_NCURSES_HPP_

#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <curses.h>
#include <unistd.h>
#include <ncurses.h>
#include "IDisplay.hh"

#define KEY_ESCAPE 27

class		Ncurses : public IDisplay
{
  typedef struct s_coord
  {
    int	x;
    int	y;
  }		t_coord;

  WINDOW	*window;
  int		_width;
  int		_height;

  void		drawWall();
public:
  Ncurses();
  virtual ~Ncurses();

  virtual int	initWindow(const int, const int);
  virtual int	gameOver(const int);
  virtual void	clearScreen();
  virtual int	loadItem(const int, const int, const Item);	
  virtual int	getKey();
  virtual void	soundEat();
};

void		xinitscr();
void		xraw();
void		xnoecho();
void		xecho();
void		xcurs_set();
void		xnoraw();
void		xwerase(WINDOW	*);
void		xwrefresh(WINDOW *);
void		xnotimeout(WINDOW *);
void		xnodelay(WINDOW *);
#endif
