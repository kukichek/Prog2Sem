#pragma once
#include<SFML/Graphics.hpp>
#include<map>
#include<utility>
#include<string>
#include<vector>
#include"constants.h"
#include"globalScore.h" 

using namespace std;
using namespace sf;

class TableOut {
	vector<pair<string, int> > gamerName;
	int lastI, firstI;
	Font font;
	int coloredI;
	const int spaceH = 60;
	const int spaceW = 30;
public:
	TableOut() {
		if (scoreTable.size() < 11) {
			for (auto i : scoreTable) {
				gamerName.push_back(i);
			}
		}
		else {
			map<string, int>::iterator it = scoreTable.begin();
			for (int i = 0; i < 10; ++i) {
				gamerName.push_back(*it);
				it++;
			}
		}
		firstI = 0;
		lastI = gamerName.size() - 1;
		coloredI = -1;

		font.loadFromFile("fonts/comic.ttf");
	}
	void operator() (RenderWindow &wnd) {
		int yPos = spaceH;
		Text text;
		text.setFont(font);
		text.setCharacterSize(30);
		for (int i = 0; i < gamerName.size(); ++i) {
			text.setString(gamerName[i].first);
			text.setPosition(spaceW, yPos);
			if (i == coloredI) {
				text.setFillColor(Color(113, 198, 33));
			} else {
				text.setFillColor(Color::Black);
			}
			wnd.draw(text);
			
			text.setString(to_string(gamerName[i].second));
			text.setPosition(wndW - spaceW - text.getLocalBounds().width, yPos);
			wnd.draw(text);

			yPos += 30;
		}
	}
	void scrollUp() {
		if (firstI > 0) {
			for (int i = gamerName.size() - 1; i > 0; --i) {
				gamerName[i] = gamerName[i - 1];
			}
			firstI--;
			lastI--;
			
			auto it = scoreTable.begin();
			for (int i = 0; i < firstI; ++i) {
				it++;
			}
			gamerName[0] = *it;
		}
	}
	void scrollDown() {
		if (lastI < scoreTable.size() - 1) {
			for (int i = 1; i < gamerName.size(); ++i) {
				gamerName[i - 1] = gamerName[i];
			}
			firstI++;
			lastI++;

			auto it = scoreTable.begin();
			for (int i = 0; i < lastI; ++i) {
				it++;
			}
			gamerName[gamerName.size() - 1] = *it;
		}
	}
	void setColored(RenderWindow &wnd) {
		for (int i = 0; i < gamerName.size(); ++i) {
			if (IntRect(spaceW, spaceH + 30 * i, 30 * gamerName[i].first.size(), 30).contains(Mouse::getPosition(wnd))) {
				gamer = gamerName[i].first;
				coloredI = i;
				return;
			}
		}
		coloredI = -1;
		return;
	}
	bool SetGamer(RenderWindow &wnd) {
		for (int i = 0; i < gamerName.size(); ++i) {
			if (IntRect(spaceW, spaceH + 30 * i, 30 * gamerName[i].first.size(), 30).contains(Mouse::getPosition(wnd))) {
				gamer = gamerName[i].first;
				return 1;
			}
		}
		return 0;
	}
};