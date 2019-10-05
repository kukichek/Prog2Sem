#pragma once
#include <cmath>

struct BlueChange {
	int operator() (double x) {
		return round(255 / 2 * (cos(x) + 1));
	}
};