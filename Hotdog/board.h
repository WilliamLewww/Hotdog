#pragma once
#include "vector2.h"
#include "geometry.h"
#include "input.h"

struct Board {
	Vector2 position;
};
extern Board board;

void updateBoard(int elapsedTime);
void drawBoard();