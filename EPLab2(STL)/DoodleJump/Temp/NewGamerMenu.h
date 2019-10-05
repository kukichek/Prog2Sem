#pragma once
#include<string>
#include<map>
#include"constants.h"
#include"WndType.h"
#include"globalScore.h"

using namespace std;

class NewGamerMenu : public WndType {
	Texture tBackground, tEnter, tBack;
	Text text;
	Text emptyStr;
	Text existStr;
	bool isEmpty, isExisting;
public:
	NewGamerMenu() {
		tBackground.loadFromFile("images/background.png");
		tEnter.loadFromFile("images/enter.png");
		tBack.loadFromFile("images/escape.png");

		isEmpty = 0;
		isExisting = 0;
	}
	int launchWnd(RenderWindow &wnd) {
		string name;

		Sprite sBackground, sEnter, sBack;
		sBackground.setTexture(tBackground);
		sEnter.setTexture(tEnter);
		sEnter.setPosition(wndW - 200, wndH - 200);
		sBack.setTexture(tBack);
		sBack.setPosition(10, wndH - 70);

		Font font;
		font.loadFromFile("fonts/comic.ttf");
		text.setFont(font);
		text.setCharacterSize(30);
		text.setFillColor(Color::Black);

		emptyStr.setFont(font);
		emptyStr.setFillColor(Color::Red);
		emptyStr.setCharacterSize(30);
		emptyStr.setString("Name can't be empty");
		emptyStr.setPosition(200 - emptyStr.getLocalBounds().width / 2, 103);

		existStr.setFont(font);
		existStr.setFillColor(Color::Red);
		existStr.setCharacterSize(29);
		existStr.setString("This name is already exists");
		existStr.setPosition(200 - existStr.getLocalBounds().width / 2, 100);

		Event e;
		while (wnd.isOpen()) {
			wnd.clear(); 
			sBack.setColor(Color::White);
			wnd.draw(sBackground);
			if (isExisting) {
				wnd.draw(existStr);
			}
			if (isEmpty) {
				wnd.draw(emptyStr);
			}

			while (wnd.pollEvent(e)) {
				if (e.type == Event::Closed)
					return 4;

				if (e.type == sf::Event::TextEntered) {
					isEmpty = 0;
					isExisting = 0;
					int code = e.text.unicode;
					if ((code < 128) && (code > 32)) {
						if (name.size() < 15) {
							name += static_cast<char>(e.text.unicode);
						}
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					isExisting = 0;
					if (name.size() > 0) {
						name.erase(name.size() - 1);
					}
				}

				bool isEnterPressed = 0;
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (IntRect(wndW - 200, wndH - 200, 190, 190).contains(Mouse::getPosition(wnd))) {
						isEnterPressed = 1;
					}
				}
				if (e.type == Event::KeyReleased) {
					if (e.key.code == sf::Keyboard::Enter) {
						isEnterPressed = 1;
					}
				}
				if (isEnterPressed) {
					if (name.empty() || isEmpty) {
						isEmpty = 1;
						wnd.draw(emptyStr);
					} else {
					if (scoreTable.emplace(name, 0).second) {
						gamer = name;
						return 0;
						} else {
							isExisting = 1;
							wnd.draw(existStr);
						}
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return 0;
				}

				if (e.type == Event::MouseButtonReleased) {
					if (e.mouseButton.button == sf::Mouse::Left) {
						if (IntRect(10, wndH - 70, 60, 60).contains(Mouse::getPosition(wnd))) {
							return 0;
						}
					}
				}
			}
			if (IntRect(10, wndH - 70, 60, 60).contains(Mouse::getPosition(wnd))) {
				sBack.setColor(Color::Yellow);
			}

			text.setString(name);
			text.setPosition(200 - text.getLocalBounds().width / 2, 200);

			wnd.draw(sBack);
			wnd.draw(sEnter);
			wnd.draw(text);

			wnd.display();
		}
	}
};