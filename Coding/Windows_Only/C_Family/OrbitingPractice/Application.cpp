#include "raylib.h"
#include <cmath>

using namespace std;

class Window {
public:
	int width = 800;
	int height = 600;
	const char* title = "Orbiter";
	Color color = BLACK;

	void initialize() {
		InitWindow(width, height, title);
	}

	void draw() {
		ClearBackground(color);
	}
};

class Body {
public:
	int x;
	int y;
	int r;
	Color color;

	void draw() {
		DrawCircle(x, y, r, color);
	}

	void update() {

	}
};

Window window;
Body planet;
Body moon;

int main() {

	// Initialize
	SetTargetFPS(60);

	window.initialize();

	planet.x = window.width / 2;
	planet.y = window.height / 2;
	planet.r = 90;
	planet.color = BLUE;

	float speed = 2;
	float angle = 0;

	// Game loop
	while (!WindowShouldClose())
	{

		// Update
		float dt = GetFrameTime();
		angle += dt * speed;

		moon.x = planet.x + 150 * cos(angle);
		moon.y = planet.y + 150 * sin(angle);
		moon.r = 15;
		moon.color = GRAY;

		// Draw
		BeginDrawing();

		window.draw();

		planet.draw();

		moon.draw();

		EndDrawing();

	}

	// De-initialize
	CloseWindow();

	return 0;
}