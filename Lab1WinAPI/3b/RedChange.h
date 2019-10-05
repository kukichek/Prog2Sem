#pragma once
#include <cmath>

struct RedChange {
	int operator() (double x) {
		return round(255 / 2 * (sin(x) + 1));
	}
};