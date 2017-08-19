#pragma once
#include "vector2.h"
#include "geometry.h"
#include "input.h"

struct Board {
	Vector2 position;
	float length = 40, width = 10;

	float velocity = 0;
	double rotation = 0;

	int turnSpeed = 75, slideSpeed = 50, pushSpeed = 75, breakSpeed = 100;
};
extern Board board;

void updateBoard(int elapsedTime);
void drawBoard();