CXX = g++

EXEC = solarsys.exe

SOURCES = main.cpp Stars.cpp SolarSystem.cpp

#INCLUDE_PATHS = -I/usr/local/include
#LIBRARY_PATHS = -L/usr/local/lib

LIBS = -lglfw  -lGLEW -framework OpenGL

COMPILER_FLAGS = -Wall

all :
	$(CXX) $(COMPILER_FLAGS) $(SOURCES) $(LIBS) -o $(EXEC)

clean:
	rm -rf *.exe *.gdb *.o


