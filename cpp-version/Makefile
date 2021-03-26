INCLUDES = -I/usr/local/include -Ilib/imgui -Ilib/stb_image

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

FILES = lib/imgui/*.cpp lib/stb_image/stb_image.cpp main.cpp SolarSystem.cpp Display.cpp Gui.cpp InputHandler.cpp

CXXFLAGS += -std=c++11 -g

solar : $(FILES)
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./solar.exe

clean:
	rm -rf *.exe

