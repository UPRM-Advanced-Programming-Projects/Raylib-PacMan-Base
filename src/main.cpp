#include "raylib.h"

#include "resource_dir.h"
#include "Program.hpp"

int main () {
	SearchAndSetResourceDir("resources");
    InitAudioDevice();

	raylib::Window window(1280, 800, "PacMan", FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(30);

	SoundManager::LoadSounds();
	ImageManager::LoadImages();
	Program program;
	SetMasterVolume(1);

	if (!IsWindowReady()) {
		TraceLog(LOG_ERROR, "Window failed to initialize!");
		return 1;
	}

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		Vector2 mousePos = GetMousePosition();

		program.Update();
		program.KeyPressed(GetKeyPressed());
		program.KeyReleased(GetKeyPressed());
		program.MousePressed(mousePos.x, mousePos.y, MOUSE_BUTTON_LEFT);
		program.Draw();

		EndDrawing();
	}

	program.Unload();
	CloseAudioDevice();
	window.Close();
	return 0;
}
