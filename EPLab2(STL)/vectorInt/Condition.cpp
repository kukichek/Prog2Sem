#include"Condition.h"

bool Condition::operator() (int _i) {
	return _i % 2;
}