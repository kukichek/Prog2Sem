#pragma once
#include<string>
#include<map>
#include"constants.h"
#include"WndType.h"
#include"globalScore.h"
#include"tableOut.h"

class ChangeGamerMenu : public WndType {
	Texture tBackground, tArrowUp, tArrowDown, tBack;
public:
	ChangeGamerMenu() {
		tBackground.loadFromFile("images/background.png");
		tArrowUp.loadFromFile("images/arrowUp.png");
		tArrowDown.loadFromFile("images/arrowDown.png");
		tBack.loadFromFile("images/escape.png");
	}
	int launchWnd(RenderWindow &wnd) {
		Sprite sBackground, sArrowUp, sArrowDown, sBack;
		sBackground.setTexture(tBackground);
		sArrowUp.setTexture(tArrowUp);
		sArrowDown.setTexture(tArrowDown);
		sBack.setTexture(tBack);
		sArrowUp.setPosition(wndW / 2 - 30, 15);
		sArrowDown.setPosition(wndW / 2 - 30, 370);
		sBack.setPosition(10, wndH - 70);
		TableOut tableOut;

		Event e;
		while (wnd.isOpen()) {
			sArrowUp.setColor(Color::White);
			sArrowDown.setColor(Color::White);
			sBack.setColor(Color::White);
			wnd.clear();
			wnd.draw(sBackground);

			while (wnd.pollEvent(e)) {
				if (e.type == Event::Closed)
					return 4;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					tableOut.scrollDown();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					tableOut.scrollUp();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return 0;
				}
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (IntRect(wndW / 2 - 30, 15, 60, 37).contains(Mouse::getPosition(wnd))) {
						tableOut.scrollUp();
					}
					if (IntRect(wndW / 2 - 30, 379, 60, 37).contains(Mouse::getPosition(wnd))) {
						tableOut.scrollDown();
					}
					if (tableOut.SetGamer(wnd)) {
						return 0;
					}
				}
				if (e.type == Event::MouseButtonReleased) {
					if (e.mouseButton.button == sf::Mouse::Left) {
						if (IntRect(10, wndH - 70, 60, 60).contains(Mouse::getPosition(wnd))) {
							return 0;
						}
					}
				}
			}

			if (IntRect(wndW / 2 - 30, 15, 60, 37).contains(Mouse::getPosition(wnd))) {
				sArrowUp.setColor(Color::Yellow);
			}
			if (IntRect(wndW / 2 - 30, 379, 60, 37).contains(Mouse::getPosition(wnd))) {
				sArrowDown.setColor(Color::Yellow);
			}
			if (IntRect(10, wndH - 70, 60, 60).contains(Mouse::getPosition(wnd))) {
				sBack.setColor(Color::Yellow);
			}

			tableOut.setColored(wnd);
			wnd.draw(sBack);
			wnd.draw(sArrowUp);
			wnd.draw(sArrowDown);
			tableOut(wnd);
			wnd.display();
		}
	}
};