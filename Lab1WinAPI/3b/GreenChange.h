#pragma once
#include <cmath>

struct GreenChange {
	int operator() (double x) {
		return round(255 * 2 * abs(fmod(x, 1) - 0.5));
	}
};