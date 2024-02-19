#include <iostream>
#include <raylib.h>

using namespace std;

int framesCounter = 0;
bool db = false;

Rectangle textBox = { 10, 570, 780, 30 };

// TODO: void draw_startn() {};

void draw_game() {
	DrawText("C:/", 10, 575, 25, WHITE);
};

// TODO: void draw_exit() {};

static void db_menu() {
	DrawFPS(0,0);
}

int main(void) {
	// Initialize
	InitWindow(800, 600, "Terminal");
	InitAudioDevice();

	SetTargetFPS(60);
	SetExitKey(KEY_NULL);

	while (!WindowShouldClose()) {
		// Update
		if (IsKeyPressed(KEY_F3)) db = !db;
		framesCounter++;



		// Draw
		BeginDrawing();

		ClearBackground(BLACK);
		if (db) db_menu();

		draw_game();

		EndDrawing();
	}

	// Cleanup
	CloseAudioDevice();
	CloseWindow();

	return 0;
}