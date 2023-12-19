#include "raylib.h"

using namespace std;

int main() {

	// Initialize
	const int windowHeight = 800;
	const int windowWidth = 600;

	InitWindow(windowHeight, windowWidth,"Empty project");
	
	SetTargetFPS(60);

	// Game loop
	while (!WindowShouldClose())
	{

		// Update

		// Draw
		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();

	}

	// De-initialize
	CloseWindow();

	return 0;
}