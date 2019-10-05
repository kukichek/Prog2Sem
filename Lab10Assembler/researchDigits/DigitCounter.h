#pragma once

class DigitCounter {
	void countSignCharacters();
	void countOnBits();
	int num, offset, onbit;
public:
	DigitCounter(int n = 0);
	void set(int n);
	int getSignCharacters();
	int getOnBits();
};
