INCLUDES = -I/usr/local/include -Ilib/imgui

LIBS = -L/usr/local/lib -lglfw  -lGLEW -lassimp -framework OpenGL

FILES = lib/imgui/*.cpp *.cpp

CXXFLAGS += -std=c++11 -g

solar : $(FILES)
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./solar.exe

clean:
	rm -rf *.exe

