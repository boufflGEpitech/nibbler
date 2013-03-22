NAME=	nibbler

CXX=	g++ -g -Wall -Wextra -W -ldl

CC=	$(CXX)

OBJ=	src/main.o\
	src/Snake.o\
	src/Food.o\
	src/Collision.o\
	src/Game.o\
	src/Strategie.o\
	src/StratFact.o\

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CXX) $^ -o $@

	g++ -shared -lGL -lGLU -lSDL -o lib_nibbler_opengl.so opengl/src/Display.cpp  -fPIC
#	g++ -shared -lsfml-graphics -lsfml-window -lsfml-system -o lib_nibbler_sfml.so ./sfml/src/Display.cpp ./sfml/src/Sound.cpp -fPIC
#	g++ -shared -lncurses -o lib_nibbler_ncurses.so ./ncurses/src/Display.cpp -fPIC

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	rm -f lib_nibbler_sfml.so
	rm -f lib_nibbler_ncurses.so

re:	fclean all