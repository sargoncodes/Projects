#include <iostream>
#include <cstdlib>
#include <raylib.h>

Color BG = { 255, 223, 211, 255 };
Color HEADS = { 224, 187, 228, 255 };
Color TAILS = { 210, 145, 188, 255 };
Color TEXT = { 149, 125, 173, 255 };

bool isHeads = NULL;
bool showMenu = false;

int result, value, flipCounter, headsWins, tailsWins = 0;
float headsWinPercentage, tailsWinPercentage = 0.0f;

using namespace std;

static int flipCoin() {
	
	value = (rand() % 2 + 1);
	
	return value;
}

int main(void) {
	// Initialize
	InitWindow(600, 600, "Heads or Tails?");
	InitAudioDevice();
	SetTargetFPS(60);
	
	Sound ding = LoadSound("Assets/ching.mp3");

	while (!WindowShouldClose()) {
		// Update
		flipCoin();
		if (IsKeyPressed(KEY_SPACE)) {
			flipCounter++;
			PlaySound(ding);
			result = flipCoin();
			if (result == 1) {
				headsWins++;
			}
			else if (result == 2) {
				tailsWins++;
			}
		}

		if (IsKeyPressed(KEY_F3)) showMenu = !showMenu;

		headsWinPercentage = (static_cast<float>(headsWins) / flipCounter) * 100;
		tailsWinPercentage = (static_cast<float>(tailsWins) / flipCounter) * 100;

		// Draw
		BeginDrawing();

		ClearBackground(BG);

		if (result == 0) {
			DrawText("Press space", 135, 250, 50, TEXT);
			DrawText("to flip", 200, 300, 50, TEXT);
		}
		else if (result == 1) {
			DrawCircle(300, 300, 100, HEADS);
			DrawText("H", 250, 220, 175, TAILS);
			DrawText("Heads!", 230, 450, 50, TEXT);
		}
		else if (result == 2) {
			DrawCircle(300, 300, 100, TAILS);
			DrawText("T", 240, 230, 175, HEADS);
			DrawText("Tails!", 240, 450, 50, TEXT);
		}
		else {
			DrawText("ERROR", 150, 250, 50, RED);
			DrawText(TextFormat("Result: %d", flipCoin()), 150, 300, 50, RED);
		}

		if (showMenu) {
			if (headsWins != 0) DrawText(TextFormat("Heads wins: %d (%.0f%% win rate)", headsWins, headsWinPercentage), 10, 540, 25, TEXT);
			else DrawText("Heads wins: 0 (0% win rate)", 10, 540, 25, TEXT);
			if (tailsWins != 0) DrawText(TextFormat("Tails wins: %d (%.0f%% win rate", tailsWins, tailsWinPercentage), 10, 570, 25, TEXT);
			else DrawText("Tails wins: 0 (0% win rate)", 10, 570, 25, TEXT);
		}

		if (!(result == 0)) DrawText(TextFormat("Flips: %d", flipCounter), 215, 100, 50, TEXT);

		EndDrawing();
	}
	
	// Finish up
	UnloadSound(ding);
	CloseAudioDevice();
	CloseWindow();
}