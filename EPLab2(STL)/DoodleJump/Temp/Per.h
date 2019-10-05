#pragma once
#include<SFML/Graphics.hpp>
#include<cmath>
#include"Point.h"
#include"constants.h"

using namespace sf;

class Per {
	Point pos;
	float velocity;
public:
	Per() {
		pos.x = 100;
		pos.y = 100;
		velocity = 0;
	}
	void calcItDelta() {
		velocity += 0.4;
		pos.y += velocity;
	}
	void calcKeyboard() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) pos.x += 4;
		if (Keyboard::isKeyPressed(Keyboard::Left)) pos.x -= 4;
		//if (pos.x > wndW - perW / 2) {
		//	pos.x -= wndW;
		//}
		//if (pos.x < -1 * (perW / 2)) {
		//	pos.x += wndW;
		//} // проверка перехода за пределы экрана для простых смертных
		if (abs(pos.x + (perW - wndW) / 2) > wndW / 2) {
			pos.x += (-1) * abs(pos.x) / pos.x * wndW;
		} // проверка перехода за пределы экрана для извращенцев
	}
	int getV() {
		return velocity;
	}
	int getX() {
		return pos.x;
	}
	int getY() {
		return pos.y;
	}
	void setV(float _v) {
		velocity = _v;
	}
	void setY(int _y) {
		pos.y = _y;
	}
};