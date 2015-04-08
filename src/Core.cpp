//
// Core.cpp for nibler in /home/kersal_e/projet_actuels/cpp_nibbler
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Sat Apr  5 14:37:06 2014 Elliot Kersale
// Last update Sun Apr  6 22:25:46 2014 Clement Girard
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "Core.hh"

Core::Core(IDisplay *lib)
{
  this->_lib = lib;
  this->_direction = RIGHT;
  this->_score = 0;
  this->_snakeSize = 4;
  this->_isRunning = true;
  this->_key = 2;
  this->dir = true;
  this->_turning = false;
  this->_isEaten = true;
}

Core::~Core()
{
  delete this->_lib;
}

void	Core::moveLeft(t_pos *head)
{
  if (dir == true)
    {
      if (_turning == true)
	{
	  head->y -= 1;
	  dir = false;
	  _turning = false;
	}
      else
	head->x--;
      return ;
    }
  if (dir == false)
    {
      if (_turning == true)
	{
	  head->x -= 1;
	  dir = true;
	  _turning = false;
	}
      else
	head->y--;
      return ;
    }
}

void	Core::moveRight(t_pos *head)
{
  if (dir == true)
    {
      if (_turning == true)
	{
	  head->y += 1;
	  _turning = false;
	  dir = false;
	}
      else
	head->x++;
      return ;
    }
  if (dir == false)
    {
      if (_turning == true)
	{
	  head->x += 1;
	  dir = true;
	  _turning = false;
	}
      else
	head->y++;
      return ;
    }
}

void	Core::HandleDirection()
{
  t_pos	head;
  t_pos tmp;

  head = getHead();
  tmp = getHead();
  switch (this->_direction)
    {
    case LEFT :
      moveLeft(&head);
      break;
    case RIGHT :
      moveRight(&head);
      break;
    default :
      break;
    }
  if (isDead(getHead()) == true)
    return ;
  else
    {
      this->_snake.push_front(head);
      this->_snake.pop_back();
    }
  newPos(&tmp);
}

void Core::newPos(t_pos *tmp)
{
  t_pos	test;
  t_pos save;
  std::deque<t_pos>::const_iterator it;

  it = this->_snake.begin();
  while (it != this->_snake.end())
    {
      ++it;
      test = *it;
      save.x = test.x;
      save.y = test.y;
      test.x = tmp->x;
      test.y = tmp->y;
      tmp->x = save.x;
      tmp->y = save.y;
    }
}

bool	Core::checkWall(const t_pos head)
{
  if (head.x <= 0 || head.x >= this->_width ||
      head.y <= 0 || head.y >= this->_height)
    return (false);
  return (true);
}

bool	Core::biteHimself(const t_pos head)
{
  t_pos	test;
  std::deque<t_pos>::const_iterator it;

  it = this->_snake.begin();
  while (it != this->_snake.end())
    {
      ++it;
      test = *it;
      if (test.x == head.x && test.y == head.y)
	return (true);
    }
  return (false);
}

t_pos	Core::getHead() const
{
  t_pos	head;

  head = this->_snake[0];
  return (head); 
}

bool	Core::isDead(const t_pos head)
{
  if (checkWall(head) != true)
    {
      this->_isRunning = false;
      return (true);
    }
  if (biteHimself(head) == true)
    {
      this->_isRunning = false;
      return (true);
    }
  return (false);
}

void	Core::initSnake()
{
  t_pos	tail;
  int	i;

  i = 0;
  tail.x = (this->_width / 2 - this->_snakeSize);
  tail.y = (this->_height / 2);
  while (i != this->_snakeSize)
    {
      this->_snake.push_back(tail);
      tail.x--;
      i++;
    }
}

bool Core::isOnSnake(const int x, const int y)
{
  t_pos	head;
  
  head = getHead();
  if (x == head.x && y == head.y)
    return (true);
  return (false);
}

void Core::addItem(const Item type)
{
  int		x;
  int		y;

  if (_isEaten == true)
    {
      x = rand() % (this->_width - 1);
      y = rand() % (this->_height - 1);
      if (x == 0)
	x++;
      if (y == 0)
	y++;
      _food.x = x;
      _food.y = y;
      _isEaten = false;
    }
  while (isOnSnake(x, y) == true)
    {
      this->addItem(FOOD);
      break;
    }
  if (_isEaten == true)
    this->_lib->loadItem(x, y, type);
  this->_lib->loadItem(_food.x, _food.y, type);
}

void	Core::addPart()
{
  t_pos	tail;
  t_pos	tmp;

  tail.x = (this->_width / 2 - this->_snakeSize);
  tail.y = (this->_height / 2);
  tmp.x = tail.x - 1;
  if (checkWall(tmp) == true)
    {
      tmp.x = tail.x + 1;
      if (checkWall(tmp) == true)
	{
	  tmp.x = tail.x;
	  tmp.y = tail.y - 1;
	  if (checkWall(tmp) == false)
	    {
	      tmp.y = tail.y + 1;
	      if (checkWall(tmp) == false)
		this->_lib->gameOver(this->_score);
	      else
		tail.y = tmp.y;
	    }
	  else
	    tail.y = tmp.y;
	}
      else
	tail.x = tmp.x;
    }
  else
    tail.x = tmp.x;
  _snakeSize++;
this->_snake.push_back(tail);
}

void	Core::isOnFood()
{
  t_pos	head;

  head = getHead();
  if (head.x == this->_food.x &&
      head.y == this->_food.y)
    {
      this->_lib->soundEat();
      _isEaten = true;
      addPart();
      addItem(FOOD);
      this->_score += SCORE;
    }
}

void	Core::displaySnake()
{
  t_pos	bodyPart;
  int	i;
  std::deque<t_pos>::const_iterator it;  

  it = this->_snake.begin();
  i = 0;
  while (it != this->_snake.end())
    {
      bodyPart =  *it;
      if (i == 0)
	this->_lib->loadItem(bodyPart.x, bodyPart.y, HEAD);
      else if ((i + 1) == this->_snakeSize)
	this->_lib->loadItem(bodyPart.x, bodyPart.y, TAIL);
      else
	this->_lib->loadItem(bodyPart.x, bodyPart.y, BODY);
      ++it;
      i++;
    }
}

void Core::checkMove()
{
  if (this->_key == 2)
    {
      _turning = true;
      this->_key = -1;
      this->_direction = RIGHT;
    }
  else if (this->_key == 3)
    {
      _turning = true;
      this->_key = -1;
      this->_direction = LEFT;
    }
  else
    _turning = false;

}

void Core::handleKey()
{
  if (this->_key == 4)
    {
      this->_isRunning = false;
    }
  else
    checkMove();
}

void Core::run()
{
  if (this->_lib->initWindow(this->_width, this->_height) == EXIT_FAILURE)
    return ;
  initSnake();
  addItem(FOOD);
  displaySnake();
  while (this->_isRunning == true)
    {
      if ((this->_key = this->_lib->getKey()) != -1)
	handleKey();
      HandleDirection();
      this->_lib->clearScreen();
      addItem(FOOD); 
      displaySnake();
      isOnFood();
      usleep(50000);
    }
  this->_lib->gameOver(this->_score);
}

void	Core::setWidth(const int width)
{
  this->_width = width;
}

void	Core::setHeight(const int height)
{
  this->_height = height;
}
