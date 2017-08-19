#include "board.h"

Board board;

bool slideLeft = false, slideRight = false;
double startSlideAngle = 0;
void updateBoard(int elapsedTime) {
	float deltaTimeS = (float)(elapsedTime) / 1000;

	if (std::find(keyList.begin(), keyList.end(), SDLK_LEFT) != keyList.end() && std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) == keyList.end()) {
		if (std::find(keyList.begin(), keyList.end(), SDLK_LALT) != keyList.end()) { board.rotation += board.slideSpeed * deltaTimeS; slideLeft = true; }
		else { 
			slideLeft = false;
			if (slideRight == false) {
				startSlideAngle = board.rotation;
			}
		}
		if (board.velocity > board.turnSpeed) {
			board.rotation += board.turnSpeed * deltaTimeS;
		}
		else {
			board.rotation += board.velocity * deltaTimeS;
		}
	}
	else {
		slideLeft = false;
	}
	if (std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) != keyList.end() && std::find(keyList.begin(), keyList.end(), SDLK_LEFT) == keyList.end()) {
		if (std::find(keyList.begin(), keyList.end(), SDLK_LALT) != keyList.end()) { board.rotation -= board.slideSpeed * deltaTimeS; slideRight = true; }
		else { 
			slideRight = false; 
			if (slideLeft == false) {
				startSlideAngle = board.rotation;
			}
		}
		if (board.velocity > board.turnSpeed) {
			board.rotation -= board.turnSpeed * deltaTimeS;
		}
		else {
			board.rotation -= board.velocity * deltaTimeS;
		}
	}
	else {
		slideRight = false;
	}
	if (std::find(keyList.begin(), keyList.end(), SDLK_LCTRL) != keyList.end()) {
		if (board.velocity - board.breakSpeed * deltaTimeS <= 0) { board.velocity = 0; }
		else { board.velocity -= board.breakSpeed * deltaTimeS; }
	}
	if (std::find(keyList.begin(), keyList.end(), SDLK_SPACE) != keyList.end() && std::find(keyList.begin(), keyList.end(), SDLK_LCTRL) == keyList.end()) {
		if (board.velocity < board.pushSpeed) {
			board.velocity = board.pushSpeed;
		}
		else { board.velocity += 50 * deltaTimeS; }
	}
	else {
		board.velocity += 10 * deltaTimeS;
	}

	std::cout << board.rotation - startSlideAngle << std::endl;

	if (slideLeft == true || slideRight == true) {
		Vector2 direction = Vector2((float)cos(((-board.rotation + ((board.rotation - startSlideAngle) / 2)) * M_PI) / 180), sin(((-board.rotation + ((board.rotation - startSlideAngle) / 2)) * M_PI) / 180));
		direction.Normalize();
		board.position += (direction * deltaTimeS) * board.velocity;
		if (board.velocity - (board.breakSpeed / 4) * deltaTimeS <= 0) { board.velocity = 0; }
		else { board.velocity -= (board.breakSpeed / 4) * deltaTimeS; }
	}
	else {
		Vector2 direction = Vector2((float)cos((-board.rotation * M_PI) / 180), sin((-board.rotation * M_PI) / 180));
		direction.Normalize();
		board.position += (direction * deltaTimeS) * board.velocity;
	}
}

void drawBoard() {
	drawRect(board.position, board.length, board.width, board.rotation);
}