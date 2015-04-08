//
// myWindow.cpp for nibbler in /home/koppe_m/c++/nibbler/test_qt
// 
// Made by koppe michiel
// Login   <koppe_m@epitech.net>
// 
// Started on  Sat Apr  5 20:18:17 2014 koppe michiel
// Last update Sun Apr  6 23:29:57 2014 Elliot Kersale
//

#include <iostream>
#include "QtDisplay.hh"

QtDisplay::QtDisplay()
{
}

QtDisplay::~QtDisplay()
{
}

int	QtDisplay::initWindow(int x, int y)
{
  x = y;
  return (x);
}

int	QtDisplay::loadItem(int x, int y, enum Item type)
{
  type = type;
  x = y;
  return (x);
}

int	QtDisplay::gameOver(int score)
{
  return (score);
}

void	QtDisplay::clearScreen()
{
}


int	QtDisplay::getKey()
{
  return (0);
}

void	QtDisplay::soundEat()
{
}

void	QtDisplay::displayScore()
{
}

extern "C"
{
  IDisplay      *create_nibbler() {return new QtDisplay();}
}
