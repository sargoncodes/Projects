#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

int leftScore = 0;
int rightScore = 0;

class Window
{
public:
	const float height = 600;
	const float width = 900;
	const char* title = "Pong";

	Color color = BLACK;

	void initialize() {
		InitWindow(width, height, title);
	}

	void draw() {
		ClearBackground(color);
		DrawText(TextFormat("%i", leftScore), 100, 85, 150, WHITE);
		DrawText(TextFormat("%i", rightScore), 750, 85, 150, WHITE);
	}
};

class Ball
{
	Window window;

public:
	float x, y;
	float r = 15;

	int ballSpeedx = 7;
	int ballSpeedy = 7;

	Color color = WHITE;

	void draw() {
		DrawCircle(x, y, r, WHITE);
	}

	void update() {
		x += ballSpeedx;
		y += ballSpeedy;
	}

	void center() {
		x = window.width / 2;
		y = window.height / 2;
	}

	void edgeCollisions() {
		if ((y >= (window.height - r)) || y <= r) {
			ballSpeedy *= -1;
		}
	}

	void paddleCollisions(Rectangle paddleRect) {
		if (CheckCollisionCircleRec(Vector2{ x, y }, r, paddleRect)) {
			ballSpeedx *= -1;
		}
	}
};

class Paddle
{
	Window window;

public:
	float x;
	float y = window.height / 2 - 60;
	float w = 15;
	float h = 120;
	float speed = 10;
	Color color = WHITE;

	void draw(float z) {
		DrawRectangle(z, y, w, h, color);
	}

	Rectangle getRectangle() const {
		return Rectangle{ x, y, w, h };
	}
};

Window window;
Ball ball;
Paddle paddleLeft;
Paddle paddleRight;

int main() 
{

	// Initialize
	window.initialize();

	SetTargetFPS(60);

	ball.center();

	bool title = true;

	paddleLeft.x = 15;
	paddleRight.x = window.width - 30;

	// Game loop
	while (!WindowShouldClose())
	{
		while (title) {
			BeginDrawing();
			window.draw();
			DrawText("PRESS SPACE TO START", window.width / 6, window.height / 2, 45, WHITE);
			DrawLine(window.width / 2, 0, window.width / 2, window.height, WHITE);
			EndDrawing();

			if (IsKeyPressed(KEY_SPACE)) {
				title = false;
				break;
			}

			if (WindowShouldClose()) {
				return 0;
			}
		}

		// Update
		ball.edgeCollisions();
		ball.paddleCollisions(paddleLeft.getRectangle());
		ball.paddleCollisions(paddleRight.getRectangle());
		ball.update();

			// Score
			if (ball.x >= window.width) {
				ball.center();
				WaitTime(1);
				leftScore += 1;
			}
			if (ball.x <= 0) {
				ball.center();
				WaitTime(1);
				rightScore += 1;
			}

			// Controls
			if (IsKeyDown(KEY_UP)) {
				paddleRight.y -= paddleRight.speed;
			}
			if (IsKeyDown(KEY_DOWN)) {
				paddleRight.y += paddleRight.speed;
			}
			if (IsKeyDown(KEY_W)) {
				paddleLeft.y -= paddleLeft.speed;
			}
			if (IsKeyDown(KEY_S)) {
				paddleLeft.y += paddleLeft.speed;
			}

		// Draw
		BeginDrawing();

		window.draw();

		DrawLine(window.width/2, 0, window.width/2, window.height, WHITE);

		paddleLeft.draw(15);
		paddleRight.draw(window.width - 30);

		ball.draw();

		EndDrawing();

	}
	// De-initialize
	CloseWindow();



	return 0;
}