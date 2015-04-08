//
// IDisplay.hh<2> for nibbler in /home/girard_g/Dropbox/Math/nibler/lib_ncurses/include
// 
// Made by Clement Girard
// Login   <girard_g@epitech.net>
// 
// Started on  Sat Apr  5 23:11:18 2014 Clement Girard
// Last update Sun Apr  6 01:02:17 2014 Clement Girard
//

#ifndef _IDISPLAY_HH_
#define _IDISPLAY_HH_

#include <deque>
#include <string>

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

enum	Item
  {
    HEAD,
    BODY,
    TAIL,
    FOOD,
    SPEED
  };

class IDisplay
{
public:
  virtual	~IDisplay() {};

  virtual int	initWindow(int, int) = 0;
  virtual int	gameOver(int) = 0;
  virtual void	clearScreen() = 0;
  virtual int	loadItem(int, int, Item) = 0;	
  virtual int	getKey() = 0;
  virtual void	soundEat() = 0;
};

#endif
