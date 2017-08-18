#pragma once
#include <SDL_opengl.h>
#include "vector2.h"
#include "main.h"

double convertColor(int rgbValue);
void drawRect(Vector2 position, int width, int height);
void drawRect(Vector2 position, int width, int height, int color[3]);
void drawLine(Vector2 a, Vector2 b);
void drawLine(Vector2 a, Vector2 b, int color[3]);
void drawCircle(Vector2 position, float radius);
void drawCircle(Vector2 position, float radius, int color[3]);
void drawTriangle(Vector2 position, int width, int height);
void drawTriangle(Vector2 position, int width, int height, double angle);