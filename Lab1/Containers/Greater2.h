#pragma once

struct Greater2 {
	bool operator() (int n);
};

bool Greater2::operator() (int n) {
	return n > 2;
}