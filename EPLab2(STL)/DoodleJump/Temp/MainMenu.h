#pragma once
#include<string>
#include<cmath>
#include"WndType.h"
#include"globalScore.h"
#include"DrawText.h"

using namespace std;

class MainMenu : public WndType {
	Texture tBackground, tStartGame, tChgGamer, tCrNewGamer, tExit;
	Sprite item[5];
	string gamer;
public:
	MainMenu() {
		tBackground.loadFromFile("images/background.png");
		tStartGame.loadFromFile("images/startGame.png");
		tChgGamer.loadFromFile("images/changeGamer.png");
		tCrNewGamer.loadFromFile("images/createNewGamer.png");
		tExit.loadFromFile("images/exit.png");

		Sprite sBackground(tBackground), sStartGame(tStartGame),
			sChgGamer(tChgGamer), sCrNewGamer(tCrNewGamer), sExit(tExit);
		item[0] = sBackground;
		item[1] = sStartGame;
		item[2] = sChgGamer;
		item[3] = sCrNewGamer;
		item[4] = sExit;
	}
	int launchWnd(RenderWindow &wnd) {
		int iMenu = 1;
		DrawText drawText;

		for (int i = 1; i < 5; ++i) {
			item[i].setPosition(0, 170 + i * 70);
		}

		while (wnd.isOpen()) {
			for (int i = 1; i < 5; ++i) {
				item[i].setColor(Color::White);
			}
			item[iMenu].setColor(Color::Yellow);
			wnd.draw(item[0]);

			Event e;
			while (wnd.pollEvent(e)) {
				if (e.type == Event::Closed)
					return 4;
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					iMenu -= 2;
					if (scoreTable.empty()) {
						iMenu %= 2;
						if (iMenu < 0) {
							iMenu += 2;
						}
						iMenu += 3;
					} else {
						iMenu %= 4;
						if (iMenu < 0) {
							iMenu += 4;
						}
						iMenu++;
					}
					item[iMenu].setColor(Color::Yellow);
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					if (scoreTable.empty()) {
						iMenu %= 2;
						iMenu += 3;
					} else {
						iMenu %= 4;
						iMenu++;
					}
					item[iMenu].setColor(Color::Yellow);
				}
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					return iMenu;
				}
			}

			if (scoreTable.empty()) {
				item[1].setColor(Color(150, 150, 150));
				item[2].setColor(Color(150, 150, 150));
				for (int i = 3; i < 5; ++i) {
					if (IntRect(0, 180 + i * 70, wndW, 50).contains(Mouse::getPosition(wnd))) {
						item[i].setColor(Color::Yellow);
						iMenu = i;
					}
				}
			} else {
				drawText.drawGamerName(wnd);
				for (int i = 1; i < 5; ++i) {
					if (IntRect(0, 180 + i * 70, wndW, 50).contains(Mouse::getPosition(wnd))) {
						item[i].setColor(Color::Yellow);
						iMenu = i;
					}
				}
			}

			for (int i = 1; i < 5; ++i) {
				wnd.draw(item[i]);
			}
			
			if (score != -1) {
				drawText.drawMenuScore(wnd, score, isHighScore);
			}

			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (IntRect(0, 180 + iMenu * 70, wndW, 50).contains(Mouse::getPosition(wnd))) {
					return iMenu;
				}
			}

			wnd.display();
		}
	}
};