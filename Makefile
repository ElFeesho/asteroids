OBJS=main.o ship.o number.o gamescene.o bullet.o asteroid.o powerup.o gameover.o score.o shrapnel.o clusterbullet.o
LIBS=`pkg-config --libs sdl SDL_gfx` -L../sge -lsge
CFLAGS=`pkg-config --cflags sdl SDL_gfx` -g -O0 -I../sge
PROG=asteroids

all:$(OBJS)
	g++ -o $(PROG) $(OBJS) $(LIBS)

%o:%cpp
	g++ $(CFLAGS) $< -c

clean:
	rm -f $(OBJS) $(PROG)
