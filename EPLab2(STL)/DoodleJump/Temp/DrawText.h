#pragma once
#include<SFML\Graphics.hpp>
#include<string>
#include"globalScore.h"

using namespace std;
using namespace sf;

class DrawText {
	Font font;
public:
	DrawText() {
		font.loadFromFile("fonts/comic.ttf");
	}
	void drawGameScore(RenderWindow &wnd, int score) {
		Text text;
		text.setFont(font);
		text.setString(to_string(score));
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold);
		text.setPosition(10, 10);
		wnd.draw(text);
	}
	void drawMenuScore(RenderWindow &wnd, int score, bool isHigh) {
		Text text;
		text.setFont(font);
		string outS;
		if (isHigh) {
			outS = "High score: " + to_string(score);
		} else {
			outS = "Your score: " + to_string(score);
		}
		text.setString(outS);
		text.setCharacterSize(45);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold);
		text.setPosition(200 - text.getLocalBounds().width / 2, 100);
		wnd.draw(text);
	}
	void drawGamerName (RenderWindow &wnd) {
		Text text;
		text.setFont(font);
		string outS = "Hello, " + gamer;
		text.setString(outS);
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold);
		text.setPosition(200 - text.getLocalBounds().width / 2, 20);
		wnd.draw(text);
	}
};