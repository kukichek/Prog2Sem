#pragma once
#include<string>
#include"Per.h"
#include"Plats.h"
#include"WndType.h"
#include"DrawText.h"
#include"globalScore.h"

using namespace std;

class Game : public WndType {
	Texture tBackground, tPlat, tPers;
public:
	Game() {
		tBackground.loadFromFile("images/background.png");
		tPlat.loadFromFile("images/platform.png");
		tPers.loadFromFile("images/doodle.png");
	}
	int launchWnd(RenderWindow &wnd) {
		score = 0;
		wnd.setFramerateLimit(60);

		Sprite sBackground(tBackground), sPlat(tPlat), sPers(tPers);

		Plats plats;
		Per per;
		DrawText drawText;

		while (wnd.isOpen())
		{
			Event e;
			while (wnd.pollEvent(e))
			{
				if (e.type == Event::Closed)
					return 4;
			}

			per.calcKeyboard();
			per.calcItDelta();

			if (per.getY() > 500)  break;

			plats.reSpawn(per);
			score += plats.calcPlatCol(per);

			sPers.setPosition(per.getX(), per.getY());

			wnd.draw(sBackground);
			wnd.draw(sPers);
			for (int i = 0; i < 10; i++)
			{
				sPlat.setPosition(plats[i].x, plats[i].y);
				wnd.draw(sPlat);
			}

			drawText.drawGameScore(wnd, score);
			wnd.display();
		}

		if (score > scoreTable[gamer]) {
			scoreTable[gamer] = score;
			isHighScore = true;
		} else {
			isHighScore = false;
		}

		return 0;
	}
};