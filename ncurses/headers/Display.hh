#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include	<cstdlib>
#include	<string>
#include	<ncurses.h>
#include	<unistd.h>
#include	<iostream>
#include	"../../headers/Game.hh"
#include	"../../ILib.hh"

class		Display :	public ILib
{
private:
  char				_direction;
  int				_maxheight;
  int				_maxwidth;
  char				_partchar;
  WINDOW			*_win;
public:
  Display();
  ~Display();
  virtual bool			Window() const;  
  virtual void			Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, int score);
  void				drawWall() const;
  void				dispFood(std::list<IFood *> list) const;
  void				displayOver();
  void				displayScore(int score);
  void				movesnake(std::list<ISnake *> &list, std::list<IFood *> &fList);
  void				start();
};

typedef Display *(*maker_Display)();

#endif
