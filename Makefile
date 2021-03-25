CXX = g++

EXEC = solarsys.exe

SOURCES = main.cpp

INCLUDES = -I/usr/local/include

LIBS = -L/usr/local/lib -lglfw -lglew -lassimp -framework OpenGL -framework Cocoa /usr/local/lib/libSOIL.a

COMPILER_FLAGS = -Wall -std=c++11

all :
	$(CXX) $(COMPILER_FLAGS) $(SOURCES) $(INCLUDES) $(LIBS) -o $(EXEC)

clean:
	rm -rf *.exe *.gdb *.o


