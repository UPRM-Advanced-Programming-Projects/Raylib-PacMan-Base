#pragma once

#include <iostream>
#include "raylib.h"

class SoundManager {
    public:

        static inline Sound eatFruit;
        static inline Sound eatGhost;
        static inline Sound chomp;
        static inline Sound startup;

        inline static void LoadSounds() {
            eatFruit = LoadSound("audio/EatFruit.mp3");
            eatGhost = LoadSound("audio/EatGhost.mp3");
            chomp = LoadSound("audio/PacChomp.mp3");
            startup = LoadSound("audio/PacmanStartup.mp3");
        }

        inline static void unloadSounds() {
            UnloadSound(eatFruit);
            UnloadSound(eatGhost);
            UnloadSound(chomp);
            UnloadSound(startup);
        }
};