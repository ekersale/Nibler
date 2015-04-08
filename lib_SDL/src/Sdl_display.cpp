//
// Sdl_display.cpp for nibller in /home/kersal_e/projet_actuels/cpp_nibbler/sources
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Wed Mar 19 16:52:24 2014 Elliot Kersale
// Last update Sun Apr  6 23:28:35 2014 Elliot Kersale
//

#include		<SDL/SDL.h>
#include		"Sdl_display.hh"

Sdldisplay::Sdldisplay()
{
  quit = false;
  screen = NULL;
  sound_eat = NULL;
  sound_loose = NULL;
  sound_music = NULL;
  background  = NULL;

}

Sdldisplay::Sdldisplay(const Sdldisplay &cpy)
{
  quit = cpy.quit;
  screen = cpy.screen;
  sound_eat = cpy.sound_eat;
  sound_loose = cpy.sound_loose;
  sound_music = cpy.sound_music;
  background = cpy.background;
}

Sdldisplay::~Sdldisplay()
{

}

Sdldisplay	&Sdldisplay::operator=(const Sdldisplay &cpy)
{
  this->quit = cpy.quit;
  this->screen = cpy.screen;
  this->sound_eat = cpy.sound_eat;
  this->sound_loose = cpy.sound_loose;
  this->sound_music = cpy.sound_music;
  this->background = cpy.background;
  return (*this);
}

int		Sdldisplay::initWindow(const int x, const int y)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
      std::cerr << "Error on SDL initializing" << std::endl; 
      return (EXIT_FAILURE);
    }
  screen = SDL_SetVideoMode(x * 30, y * 30, 32, SDL_HWSURFACE);
  if (screen == NULL)
    {
      std::cerr << "Impossible to load video mode : " << SDL_GetError() << std::endl;
      return (EXIT_FAILURE);
    }
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  if ((background = IMG_Load(BACKGROUND)) == NULL)
    return (EXIT_FAILURE);
  clearScreen();
  music();
  return (0);
}

int		Sdldisplay::getKey()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  return (4);
	case SDL_KEYUP:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_RIGHT:
	      return (2);
	    case SDLK_LEFT:
	      return (3);
	    case SDLK_p:
	      return (5);
	    case SDLK_ESCAPE:
	      return (4);
	    default :
	      return (-1);
	    }
	}
    }
  return (-1);
}

int		Sdldisplay::gameOver(const int score)
{
  TTF_Font		*police = NULL;
  SDL_Surface		*text = NULL;
  SDL_Color		color;
  SDL_Rect		position;
  std::stringstream	conv;
  char			value[100];
  int			check = 0;

  color.r = 0;
  color.g = 150;
  color.b = 150;
  conv << score;
  conv >> value;
  clearScreen();
  if (TTF_Init() == -1)
    return (EXIT_FAILURE);
  if ((police = TTF_OpenFont(POLICE, 65)) == NULL)
    return (EXIT_FAILURE);
  text = TTF_RenderText_Blended(police, "Your", color);
  position.x = 10;
  position.y = 10;
  SDL_BlitSurface(text, NULL, screen, &position);
  text = TTF_RenderText_Blended(police, "score", color);
  position.x = 180;
  position.y = 10;
  soundLoose();
  SDL_BlitSurface(text, NULL, screen, &position);
  text = TTF_RenderText_Blended(police, value, color);
  position.x = 400;
  position.y = 10;
  if (text != NULL)
    SDL_BlitSurface(text, NULL, screen, &position);
  SDL_Flip(screen);
  TTF_CloseFont(police);
  TTF_Quit();
  while (check != 4)
    check = getKey();
  Mix_CloseAudio();
  exit(-1);
  return (EXIT_SUCCESS);
}

void		Sdldisplay::clearScreen()
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  if (screen != NULL)
    {
      SDL_BlitSurface(background, NULL, screen, &pos);
      SDL_Flip(screen);
    }
}

int		Sdldisplay::loadItem(const int x, const int y, const Item type)
{
  SDL_Surface	*new_s = NULL;
  SDL_Rect	pos;

  pos.x = x * 30;
  pos.y = y * 30;
  if (type == BODY)
    new_s = IMG_Load(DBODY);
  if (type == TAIL)
    new_s = IMG_Load(DBODY);
  if (type == HEAD)
    new_s = IMG_Load(DHEAD);
  if (type == FOOD)
    new_s = IMG_Load(DFOOD);
  if (new_s == NULL)
    {
      std::cerr << "Error on loading image." << std::endl;
      return (EXIT_FAILURE);
    }
  SDL_BlitSurface(new_s, NULL, screen, &pos);
  SDL_Flip(screen);
  return (EXIT_SUCCESS);
}

int		Sdldisplay::music()
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
                    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      fprintf(stderr, "%s\n", Mix_GetError());
      return (EXIT_FAILURE);
    }
  Mix_AllocateChannels(10);
  sound_eat = Mix_LoadWAV(EAT);
  sound_loose = Mix_LoadWAV(LOOSE);
  if (!sound_eat || !sound_loose)
    fprintf(stderr, "Mix_LoadWAV: %s\n", Mix_GetError());
  sound_music = Mix_LoadMUS(AMBIANCE);
  if (!sound_music)
    fprintf(stderr, "Mix_LoadMUS: %s\n", Mix_GetError());
  Mix_PlayMusic(sound_music, -1);
  return (EXIT_SUCCESS);
}

void		Sdldisplay::soundEat()
{
  if (sound_eat != NULL)
    Mix_PlayChannel(-1, sound_eat, 0);
}

void		Sdldisplay::soundLoose()
{
  if (sound_loose != NULL)
      Mix_PlayChannel(-1, sound_loose, 0);
}

extern "C"
{
  IDisplay      *create_nibbler() {return new Sdldisplay();}
}
