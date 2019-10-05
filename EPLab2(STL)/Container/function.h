#pragma once
#include<iostream>
#include"Student.h"

using namespace std;

bool CompName(const Student &first, const Student &last);

bool CompGroupName(const Student &first, const Student &last);

bool CompAvBall(const Student &first, const Student &last);

double getBall();

int getGroup();