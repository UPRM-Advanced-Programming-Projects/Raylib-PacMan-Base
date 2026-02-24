#pragma once

#include <iostream>
#include "raylib.h"

class ImageManager {
    public:

        static inline Texture2D spriteSheet;
        static inline Texture2D evilPacman;
        static inline Texture2D map;
        static inline Texture2D pacman;

        inline static void LoadImages() {
            spriteSheet = LoadTextureFromImage(LoadImage("images/sprite-sheet.png"));
            evilPacman = LoadTextureFromImage(LoadImage("images/evil-pacman.png"));
            map = LoadTextureFromImage(LoadImage("images/map.png"));
            pacman = LoadTextureFromImage(LoadImage("images/pacman.png"));
        }

        inline static void unloadImages() {
            UnloadTexture(spriteSheet);
            UnloadTexture(evilPacman);
            UnloadTexture(map);
            UnloadTexture(pacman);
        }
};