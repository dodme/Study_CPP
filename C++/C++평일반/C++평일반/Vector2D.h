#pragma once
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#pragma warning (disable : 4996)
using namespace std;

struct Vector2D
{
public:
	int x;
	int y;

	void SetVector(int x, int y);


	void PrintVector();

	double Distance(Vector2D pos1, Vector2D pos2);

};

