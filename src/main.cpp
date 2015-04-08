//
// main.cpp for nibbler in /home/girard_g/Dropbox/nib/rendu
// 
// Made by Clement Girard
// Login   <girard_g@epitech.net>
// 
// Started on  Sun Apr  6 20:43:47 2014 Clement Girard
// Last update Sun Apr  6 22:28:35 2014 Clement Girard
//

#include <cstdlib>
#include <dlfcn.h>
#include <exception>
#include <iostream>
#include <sstream>
#include "DLLoader.hh"
#include "Core.hh"
#include "IDisplay.hh"

int		my_atoi(char *value, int max)
{
  int		i;
  std::stringstream conv;

  conv << value;
  conv >> i;
  if (i > max)
    i = max;
  return (i);
}

int		startGame(IDisplay *lib, char **av)
{
  Core		core(lib);


  srandom(time(NULL));
  core.setWidth(my_atoi(av[1], 63));
  core.setHeight(my_atoi(av[2], 34));
  core.run();
  return (0);
}

bool	checkSize(std::string value)
{
  std::istringstream	iss(value);
  int	i;
	
  iss >> i;
  if (i < 20)
    {
      std::cerr << "Error: [WIDTH] and [HEIGHT] must > 30" << std::endl;
      return (false);
    }
  return (true);
}

bool	checkValue(const std::string value)
{
  unsigned int	i;
  
  i = 0;
  while (i < value.size())
    {
      if (value[i] < '0' || value[i] > '9')
	{
	  std::cerr << "Error: [WIDTH] and [HEIGHT] must be numeric" << std::endl;
	  return (false);
	}
      i++;
    }
  if (checkSize(value) != true)
    return (false);
  return (true);
}

bool	checkArgs(const char *width, const char *height, const int ac)
{
  if (ac <= 3)
    return (false);
  if (checkValue(width) != true || checkValue(height) != true)
    return (false);
  return (true);
}

int		main(int ac, char **av)
{
  if (checkArgs(av[1], av[2], ac) != true)
    std::cerr << "Usage: ./nibbler [MAP_WIDTH] [MAP_HEIGHT] [LIBRARY]" << std::endl;
  else
    {
      DLLoader		loader(av[3]);
      IDisplay		*lib;

      lib = loader.getLib();
      startGame(lib, av);
    }
  return (0);
}
