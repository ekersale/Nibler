#ifndef _DLLOADER_HH_
#define _DLLOADER_HH_

#include <string>
#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include "IDisplay.hh"


class DLLoader
{
private:
  IDisplay		*(*_NibblerLib)();
  void			*_dlhandler;

public:
  DLLoader(std::string libName);
  ~DLLoader();

public:
  IDisplay		*getLib();
};

#endif
