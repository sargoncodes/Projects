#include<iostream>
#include<raylib.h>

using namespace std;

int counter, seconds, minutes = 0;

int main(void) {

	InitWindow(600,600,"Game Clock");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		if (!(counter < 60)) {
			seconds += 1;
			counter = 0;
		}
		else if (!(seconds < 60)) {
			minutes += 1;
			seconds = 0;
		}
		else {
			counter++;
		}

		BeginDrawing();

		ClearBackground(WHITE);

		DrawText(TextFormat("%d:%d", minutes, seconds), 250, 300, 100, BLACK);
		DrawFPS(0, 0);

		EndDrawing();

	}

	return 0;
}