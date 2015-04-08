//
// DLLoader.cpp for nibbler in /home/kersal_e/Dropbox/nib/rendu
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Sun Apr  6 21:38:56 2014 Elliot Kersale
// Last update Sun Apr  6 21:38:57 2014 Elliot Kersale
//

#include "DLLoader.hh"

DLLoader::DLLoader(std::string libName)
{
  if ((this->_dlhandler = dlopen(libName.c_str(), RTLD_NOW)) == NULL)
    {
      std::cerr<< dlerror() << std::endl;
      exit(0);
    }
  this->_NibblerLib = reinterpret_cast<IDisplay* (*)()>
    (dlsym(_dlhandler, "create_nibbler"));
  if (this->_NibblerLib == NULL)
    {
      std::cerr<< dlerror() << std::endl;
      dlclose(this->_dlhandler);
      exit (1);
    }
}

DLLoader::~DLLoader()
{
  dlclose(this->_dlhandler);
}

IDisplay	 *DLLoader::getLib()
{
  return ((*this->_NibblerLib)());
}
