#include <iostream>
#include <raylib.h>

// Define and intialize variables
int FPS = 60;

int windowWidth = 800;
int windowHeight = 600;

int clicks, autoClicks, money = 0;

int counter, seconds = 0;

double multiplier = 1;

bool db = false;
bool justStart = true;
bool gameContinue = true;
bool exitRequest = false;

//class Button {
//public:
//	Vector2 position;
//	Vector2 dimensions;
//	Color color;
//	Rectangle rect;
//
//	int cost;
//};
//Button multiplierUpgrade;

struct {
	Vector2 position;
	Vector2 dimensions;
	Rectangle body;

	int cost;
}multiplierButton, autoClickerButton;

// Define functions
static void gameClock(float dt) {
	if (!(counter < FPS)) {
		seconds += 1;
		counter = 0;
	}
	else {
		counter++;
	}
}
static bool canAfford(int cost) {
	if (money < cost) {
		return false;
	}
	else {
		return true;
	}
}

static void startMenu() {
	DrawText("Press space to start", (windowWidth / 2 - 250), windowHeight / 2, 48, BLACK);
}
static void gamePlay() {
	DrawText(TextFormat("%d", money), (windowWidth / 2 - 72), (windowHeight / 2 - 72), 72, GREEN);


	/*---------------------------Playground-----------------------------*/

	multiplierButton.position = { 300, 300};
	multiplierButton.dimensions = { 120, 60 };
	multiplierButton.body = { multiplierButton.position.x, multiplierButton.position.y, multiplierButton.dimensions.x, multiplierButton.dimensions.y };
	multiplierButton.cost = 10;
	

	if (!CheckCollisionPointRec(GetMousePosition(), multiplierButton.body)) {
		DrawRectangle(multiplierButton.body.x, multiplierButton.body.y, multiplierButton.body.width, multiplierButton.body.height, BLACK);
	}
	else {
		DrawRectangle(multiplierButton.body.x, multiplierButton.body.y, multiplierButton.body.width, multiplierButton.body.height, RED);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && canAfford(multiplierButton.cost)) {
			multiplier += 1;
		//	multiplierButton.cost += 10; // WTF??
		}
	}


	/*-------------------------------------------------------------------*/
}
static void endConfirm() {
	DrawRectangle((windowWidth / 2 - 300), (windowHeight / 2 - 50), 550, 200, RED);
	DrawText("Are you sure?", (windowWidth / 2 - 200), windowHeight / 2, 48, WHITE);
	DrawText("Y/N", (windowWidth / 2 - 100), (windowHeight / 2 + 68), 48, WHITE);

	if (IsKeyPressed(KEY_Y)) gameContinue = false;
	else if (IsKeyPressed(KEY_N)) exitRequest = false;
}

static void dbMenu() {
	DrawFPS(10, 10);
	DrawText(TextFormat("Clicks: %d", clicks), 10, 30, 20, DARKGREEN);
	DrawText(TextFormat("Multiplier: %.0f", multiplier), 10, 50, 20, DARKGREEN);
	DrawText(TextFormat("Multiplier cost: $%d", multiplierButton.cost), 10, 70, 20, DARKGREEN);
	DrawText(TextFormat("Seconds elapsed: %.0d", seconds), 10, 90, 20, DARKGREEN);
	
}

int main(void) {

	// Initialize
	InitWindow(windowWidth, windowHeight, "Clicker");
	SetTargetFPS(FPS);

	while (gameContinue) {
		// Update
		
		float dt = GetFrameTime();
		clicks += autoClicks;
		money = clicks * multiplier;
		gameClock(dt);
		
		if (WindowShouldClose()) exitRequest = true;
		
		if (IsKeyPressed(KEY_F3)) db = !db; // Tab enables debug mode

		if (justStart && IsKeyPressed(KEY_SPACE)) justStart = false;

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !justStart) clicks++;

		// Draw
		BeginDrawing();

		ClearBackground(WHITE);

		if (db) dbMenu();

		if (justStart) startMenu();
		if (!justStart) gamePlay();
		if (exitRequest) endConfirm();

		EndDrawing();

	}
	// TODO: handle saving

	// Clean up
	CloseWindow();

	return 0;
}