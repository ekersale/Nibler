//
// Core.hpp for nibbler in /home/kersal_e/Dropbox/nib
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Fri Apr  4 15:26:58 2014 Elliot Kersale
// Last update Sun Apr  6 22:27:28 2014 Clement Girard
//

#ifndef	_CORE_HPP__
#define	_CORE_HPP__

#include <deque>
#include "IDisplay.hh"

# define SCORE		10

enum	Direction
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

class			Core
{	
private:
  std::deque<t_pos>	_snake;
  t_pos			_food;
  IDisplay		*_lib;
  Direction		_direction;
  bool			_isRunning;
  int			_snakeSize;
  int			_width;
  int			_height;
  int			_score;
  int			_key;
  bool			dir;
  bool			_turning;
  bool			_isEaten;
  
public:
  Core(IDisplay *);
  ~Core();
  
  void		run();
  t_pos		getHead() const;
  bool		biteHimself(const t_pos head);
  bool		checkWall(const t_pos head);
  void		HandleDirection();
  void		initSnake();
  bool		isDead(const t_pos head);
  bool		isOnSnake(const int x, const int y);
  void		addItem(const Item type);
  void		displaySnake();
  void		isOnFood();
  void		setWidth(const int width);
  void		setHeight(const int height);
  void		checkMove();
  void		handleKey();
  void		moveRight(t_pos *);
  void		moveLeft(t_pos *);
  void		newPos(t_pos *);
  void		addPart();
};

int		my_atoi(char *value, int max);
int		startGame(IDisplay *lib, char **av);
bool		checkSize(std::string value);
bool		checkValue(const std::string value);
bool		checkArgs(const char *width, const char *height, const int ac);


#endif
