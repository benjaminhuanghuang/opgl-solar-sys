CXX = g++

EXEC = solarsys.exe

SOURCES = main.cpp SOIL2/*.c

INCLUDES = -I/usr/local/include 

LIBS = -L/usr/local/lib -lglfw -lglew -lassimp -framework OpenGL -framework Cocoa

COMPILER_FLAGS = -std=c++11 -g

all :
	$(CXX) $(COMPILER_FLAGS) $(SOURCES) $(INCLUDES) $(LIBS) -o $(EXEC)

clean:
	rm -rf *.exe *.gdb *.o


