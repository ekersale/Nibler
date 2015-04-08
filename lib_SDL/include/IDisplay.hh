//
// IDisplay.hh for nibbler in /home/girard_g/Dropbox/nib/rendu/lib_SDL
// 
// Made by Clement Girard
// Login   <girard_g@epitech.net>
// 
// Started on  Sun Apr  6 20:23:01 2014 Clement Girard
// Last update Sun Apr  6 22:31:26 2014 Clement Girard
//

#ifndef	       	_IDISPLAY_HH_
#define	       	_IDISPLAY_HH_

#include       	<deque>
#include       	<string>

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

enum	 	Item
  {
		HEAD,
		BODY,
		TAIL,
		FOOD,
		SPEED
  };

class		IDisplay
{
public:
  virtual	~IDisplay() {};

  virtual int	initWindow(const int, const int) = 0;
  virtual int	gameOver(const int) = 0;
  virtual void	clearScreen() = 0;
  virtual int	loadItem(const int, const int, const Item) = 0;	
  virtual int	getKey() = 0;
  virtual void	soundEat() = 0;
};

#endif
/* EOF		_IDISPLAY_HH__		*/
