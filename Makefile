CXX = g++

EXEC = solarsys.exe

SOURCES = *.cpp

#INCLUDE_PATHS = -I/usr/local/include
#LIBRARY_PATHS = -L/usr/local/lib

LIBS = -lglfw  -lGLEW -framework OpenGL

COMPILER_FLAGS = -Wall -std=c++11

all :
	$(CXX) $(COMPILER_FLAGS) $(SOURCES) $(LIBS) -o $(EXEC)

clean:
	rm -rf *.exe *.gdb *.o


