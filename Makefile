all:
	g++ -IC:/Dev/SDL2-devel-2.0.22-mingw/SDL2-2.0.22/i686-w64-mingw32/include/SDL2 -IC:\Dev\SDL2_image-2.0.1\include -LC:/Dev/SDL2-devel-2.0.22-mingw/SDL2-2.0.22/i686-w64-mingw32/lib -LC:\Dev\SDL2_image-2.0.1\lib\x86 -o prog main.cpp Game.cpp TextureManager.cpp Map.cpp Entity.cpp Player.cpp EntityLife.cpp Monster.cpp Brick.cpp GameSettings.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image