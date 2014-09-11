#ifndef SDLWINDOW_HPP
#define SDLWINDOW_HPP

#include<SDL2/SDL.h>
#include<4u/exception/exception.hpp>

#include"rawsdlwindow.hpp"

class SDLWindow : public Window {
private:

public:
	SDLWindow(const char *name = "SDL Window", const Window::Size &size = Window::Size(800,600), unsigned int flags = 0)
		: RawSDLWindow(name,size,flags)
	{

	}

private:

};

#endif // SDLWINDOW_HPP
