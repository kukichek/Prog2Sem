#include <SFML/Graphics.hpp>
#include"WndType.h"
#include"NewGamerMenu.h"
#include"MainMenu.h"
#include"Game.h"
#include"ChangeGamerMenu.h"
#include"constants.h"
#include"LoadScoreTable.h"

using namespace sf;
using namespace std;

WndType *menuList[4];

int main()
{
	ProcessScoreTable::LoadScoreTable();

	MainMenu *startMenu = new MainMenu;
	Game *game = new Game;
	NewGamerMenu *newGamerMenu = new NewGamerMenu; 
	ChangeGamerMenu *changeGamerMenu = new ChangeGamerMenu;
	if (!scoreTable.empty()) {
		gamer = scoreTable.begin()->first;
	}

	menuList[0] = startMenu;
	menuList[1] = game;
	menuList[2] = changeGamerMenu;
	menuList[3] = newGamerMenu;

    srand(time(0));

    RenderWindow app(VideoMode(wndW, wndH), "Doodle Jump");
	int i = 0;
	do {
		i = menuList[i]->launchWnd(app);
	} while (i != 4);

	ProcessScoreTable::SaveScoreTable();

	app.close();

    return 0;
}
