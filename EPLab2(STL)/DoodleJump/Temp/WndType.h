#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class WndType {
public:
	virtual int launchWnd(RenderWindow &wnd) = 0;
};