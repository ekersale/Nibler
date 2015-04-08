//
// myWindow.hh for test in /home/koppe_m/c++/nibbler/test_qt
// 
// Made by koppe michiel
// Login   <koppe_m@epitech.net>
// 
// Started on  Tue Mar 18 15:49:29 2014 koppe michiel
// Last update Sun Apr  6 22:15:18 2014 koppe michiel
//

#ifndef		__QTDISPLAY_HH__
# define	__QTDISPLAY_HH__

#include "IDisplay.hh"

class	QtDisplay : public IDisplay
{
protected:
public:
  QtDisplay();
  virtual ~QtDisplay();

  virtual int		initWindow(int , int);
  virtual int		gameOver(int);
  virtual void		clearScreen();
  virtual int		loadItem(int , int , enum Item);
  virtual void		displayScore();
  virtual int		getKey();
  virtual void		soundEat();
};

#endif
