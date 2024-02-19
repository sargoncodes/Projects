#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

int leftScore, rightScore = 0;

bool db = false;
bool title = true;

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

	int speed = 7;
	int ballSpeedx = speed;
	int ballSpeedy = speed;

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

	void edgeCollisions(Sound sound) {
		if ((y >= (window.height - r)) || y <= r) {
			ballSpeedy *= -1;
			PlaySound(sound);
		}
	}

	void paddleCollisions(Rectangle paddleRect, Sound sound) {
		if (CheckCollisionCircleRec(Vector2{ x, y }, r, paddleRect)) {
			ballSpeedx *= -1;
			PlaySound(sound);
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

	InitAudioDevice();

	SetTargetFPS(60);

	Sound hit_sound = LoadSound("Assets/boop.mp3");
	Sound ding = LoadSound("Assets/ching.mp3");

	ball.center();

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
		ball.edgeCollisions(hit_sound);
		ball.paddleCollisions(paddleLeft.getRectangle(), hit_sound);
		ball.paddleCollisions(paddleRight.getRectangle(), hit_sound);
		ball.update();

		if (IsKeyPressed(KEY_F3)) db = !db;

			// Score
			if (ball.x >= window.width) {
				ball.center();
				PlaySound(ding);
				WaitTime(1);
				leftScore += 1;
			}
			if (ball.x <= 0) {
				ball.center();
				PlaySound(ding);
				WaitTime(1);
				rightScore += 1;	
			}
			if ((ball.x <= 0) || (ball.x >= window.width)) {
				ball.center();
				WaitTime(1);
				ball.ballSpeedx *= -1;
			}

			// Controls
			if (IsKeyDown(KEY_UP) && (paddleRight.y > 10)) {
				paddleRight.y -= paddleRight.speed;
			}
			if (IsKeyDown(KEY_DOWN) && (paddleRight.y < 470)) {
				paddleRight.y += paddleRight.speed;
			}
			if (IsKeyDown(KEY_W) && (paddleLeft.y > 10)) {
				paddleLeft.y -= paddleLeft.speed;
			}
			if (IsKeyDown(KEY_S) && (paddleLeft.y < 470)) {
				paddleLeft.y += paddleLeft.speed;
			}

		// Draw
		BeginDrawing();

		window.draw();

		DrawLine(window.width/2, 0, window.width/2, window.height, WHITE);

		paddleLeft.draw(15);
		paddleRight.draw(window.width - 30);

		ball.draw();

		if (db) DrawFPS(10, 10);

		EndDrawing();

	}
	// De-initialize
	UnloadSound(ding);
	UnloadSound(hit_sound);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}