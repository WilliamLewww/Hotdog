#include "board.h"

Board board;

void updateBoard(int elapsedTime) {
	float deltaTimeS = (float)(elapsedTime) / 1000;

	if (std::find(keyList.begin(), keyList.end(), SDLK_LEFT) != keyList.end()) { board.rotation += 50 * deltaTimeS; }
	if (std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) != keyList.end()) { board.rotation -= 50 * deltaTimeS; }
	if (std::find(keyList.begin(), keyList.end(), SDLK_LCTRL) != keyList.end()) { 
		if (board.velocity - 100 * deltaTimeS <= 0) { board.velocity = 0; }
		else { board.velocity -= 100 * deltaTimeS; }
	}
	if (std::find(keyList.begin(), keyList.end(), SDLK_SPACE) != keyList.end() && std::find(keyList.begin(), keyList.end(), SDLK_LCTRL) == keyList.end()) {
		if (board.velocity < 75) {
			board.velocity = 75;
		}
	}
	else {
		board.velocity += 25 * deltaTimeS;
	}

	Vector2 direction = Vector2((float)cos((-board.rotation * M_PI) / 180), sin((-board.rotation * M_PI) / 180));
	direction.Normalize();
	board.position += (direction * deltaTimeS) * board.velocity;
}

void drawBoard() {
	drawRect(board.position, board.length, board.width, board.rotation);
}