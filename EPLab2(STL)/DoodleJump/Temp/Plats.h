#pragma once
#include"Point.h"
#include"constants.h" 
#include"Per.h"

class Plats {
	Point plat[10];
public:
	Plats() {
		plat[0].x = 100;
		plat[0].y = wndH - platH - rand() % 50;
		for (int i = 1; i < 10; i++) {
			plat[i].x = rand() % wndW - platW / 2;
			plat[i].y = rand() % wndH;
		}
	}
	void reSpawn(Per &per) {
		if (per.getY() < upperBar) {
			for (int i = 0; i < 10; i++)
			{
				per.setY(upperBar);
				plat[i].y = plat[i].y - per.getV();
				if (plat[i].y > wndH) {
					plat[i].y = 0;
					plat[i].x = rand() % wndW - platW / 2;
				}
			}
		}
	}
	int calcPlatCol(Per &per) {
		for (int i = 0; i < 10; ++i) {
			if ((per.getX() + 50 > plat[i].x) && (per.getX() + 20 < plat[i].x + platW)
				&& (per.getY() + 70 > plat[i].y) && (per.getY() + 70 < plat[i].y + platH) && (per.getV() > 0)) {
				per.setV(-15);
				return 1;
			}
		}
		return 0;
	}
	Point operator[] (int i) {
		return plat[i];
	}
};
