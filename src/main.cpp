#include	"../ncurses/headers/Display.hh"

int	main(int ac, char **av)
{
  if (ac == 4)
    {
      Game			*game = new Game(atoi(av[1]), atoi(av[2]));
      std::list<ISnake *>	tmp;
      std::list<IFood *>	tmpf;
      int			ret;
      maker_Display		pMaker;
      void			*hndl;
      void			*mkr;

      hndl = dlopen(av[3], RTLD_LAZY);
      if (hndl == NULL)
	return(0);// lance une exception quand la classe sera faite
      mkr = dlsym(hndl, "make_display");
      if (mkr == NULL)
	{
	  dlclose(hndl);
	  return (0);
	}
      pMaker = (maker_Display)mkr;
      Display *my_graph = pMaker();
      ret = 0;
      while (my_graph->Window() == true && ret != -1)
	{
	  tmp = game->getSList();
	  tmpf = game->getFList();
	  my_graph->Play(tmp, tmpf, game->getScore());
	  ret = game->checkCollision(tmp, tmpf);
	  if (ret == 1)
	    {
	      game->setScore();
	      game->updateSList(tmp);
	      game->updateFList(tmpf);
	    }
	  game->setSList(tmp);
	  game->setFList(tmpf);
	  game->analyseLevel();
	  usleep(game->getSpeed());
	}
      dlclose(hndl);
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl;
  return (0);
}
