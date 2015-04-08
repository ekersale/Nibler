//
// Ncurses.cpp for nibbler in /home/girard_g/Dropbox/nib/new_nib_by_elliot_si_ce_n_est_pas_clair/lib_ncurses
// 
// Made by Clement Girard
// Login   <girard_g@epitech.net>
// 
// Started on  Sun Apr  6 13:53:41 2014 Clement Girard
// Last update Sun Apr  6 22:20:14 2014 Clement Girard
//

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses() 
{
}

int	Ncurses::initWindow(const int width, const int height)
{
  this->_width = width + 2;
  this->_height = height + 2;
  xinitscr();
  xraw();
  xnoecho();
  if ((this->window = newwin(this->_width, this->_height, 0, 0)) == NULL)
    {
      std::cerr << "Error: newWin() failed" << std::endl;
      exit(0);
    }
  xcurs_set();
  if (keypad(this->window, TRUE) == ERR)
    {
      std::cerr << "Error: keyPad() failed" << std::endl;
      exit(0);
    }
  intrflush(this->window, FALSE);
  xwerase(this->window);
  xwrefresh(this->window);
  xnotimeout(this->window);
  xnodelay(this->window);
  if (keypad(stdscr, TRUE) == ERR)
    {
      std::cerr << "Error: keyPad() failed" << std::endl;
      exit(0);
    }
  return (0);
}

int	Ncurses::loadItem(const int x, const int y, const Item type)
{
  switch (type)
    {
    case FOOD:
      mvwprintw(this->window, y, x, "O");
      break;
    case HEAD:
      mvwprintw(this->window, y, x, "X");
      break;
    case BODY:
      mvwprintw(this->window, y, x, "*");
      break;
    case TAIL:
      mvwprintw(this->window, y, x, "*");
      break;
    default:
      std::cerr << " " << std::cout;
      break;
    }
  xwrefresh(this->window);
  return (0);
}

int	Ncurses::gameOver(const int score)
{
  xnoraw();
  if (delwin(this->window) == ERR)
    std::cerr << "Error: delwin() failed" << std::endl;
  endwin();
  std::cout << "You have : " << score << " points." << std::endl;
  xecho();
  return (0);
}

int	Ncurses::getKey()
{
  int	key;

  switch (key = wgetch(this->window))
    {
    case KEY_ESCAPE:
      return (4);
    case KEY_LEFT:
      return (3);
    case KEY_RIGHT:
      return (2);
    }
  return (-1);
}

void   	Ncurses::drawWall()
{
  int	x;
  int	y;

  y = 0;

  while (y < this->_height)
    {
      x = 0;
      mvwprintw(this->window, y, x, "#");
      while (x < (this->_width - 1))
	{
	  if (y == 0)
	    mvwprintw(this->window, y, x, "#");
	  x++;
	}
      x -= 1;
      mvwprintw(this->window, y, x, "#");
      y++;
    }
  y -= 1;
  x = 0;
  while (x < (this->_width - 1))
    {
      mvwprintw(this->window, y, x, "#");
      x++;
    }
  xwrefresh(this->window);
}

void   	Ncurses::clearScreen()
{
  werase(this->window);
  drawWall();
}

void   	Ncurses::soundEat()
{
}

extern "C"
{
  IDisplay	*create_nibbler() {return new Ncurses();}
}

void	xinitscr()
{
  if (initscr() != stdscr)
    {
      std::cerr << "Error: initscr() failed" << std::endl;
      exit(0);
    }
}

void	xcurs_set()
{
  if (curs_set(0) == ERR)
    {
      std::cerr << "Error: curs_set() failed" << std::endl;
      exit(0);
    }
}

void	xraw()
{
  if (raw() == ERR)
    {
      std::cerr << "Error: raw() failed" << std::endl;
      exit(0);
    }
}

void	xnoraw()
{
  if (noraw() == ERR)
    {
      std::cerr << "Error: noraw() failed" << std::endl;
      exit(0);
    }
}

void	xnoecho()
{
  if (noecho() == ERR)
    {
      std::cerr << "Error: noecho() failed" << std::endl;
      exit(0);
    }
}

void	xecho()
{
  if (echo() == ERR)
    {
      std::cerr << "Error: noecho() failed" << std::endl;
      exit(0);
    }
}

void	xwerase(WINDOW	*window)
{
  if (werase(window) == ERR)
    {
      std::cerr << "Error: werase() failed" << std::endl;
      exit(0);
    }
}

void	xwrefresh(WINDOW *window)
{
  if (wrefresh(window) == ERR)
    {
      std::cerr << "Error: wrefresh() failed" << std::endl;
      exit(0);
    }
}

void	xnotimeout(WINDOW *window)
{
  if (notimeout(window, TRUE) == ERR)
    {
      std::cerr << "Error: notimeout() failed" << std::endl;
      exit(0);
    }
}

void	xnodelay(WINDOW *window)
{
  if (nodelay(window, TRUE) == ERR)
    {
      std::cerr << "Error: nodelay() failed" << std::endl;
      exit(0);
    }
}
