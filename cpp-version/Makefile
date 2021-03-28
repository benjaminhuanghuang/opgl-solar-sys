INCLUDES = -I/usr/local/include -Ilib/imgui -Ilib/stb_image -I.

LIBS = -L/usr/local/lib -lglfw  -lGLEW -lassimp -framework OpenGL

FILES = lib/imgui/*.cpp lib/stb_image/stb_image.cpp *.cpp

CXXFLAGS += -std=c++11 -g

solar : $(FILES)
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe

clean:
	rm -rf *.exe

