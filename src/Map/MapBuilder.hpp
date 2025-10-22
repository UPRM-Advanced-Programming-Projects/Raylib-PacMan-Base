#pragma once

#include "raylib.h" 
#include "Map.hpp"
#include "Dot.hpp"
#include "BigDot.hpp"
#include "Ghost.hpp"
#include "AppleSprite.hpp"

class MapBuilder {
    private:
        int pixelMultiplier;
        std::vector<Texture2D> bound;
        EntityManager* entityManager;

        Color boundBlockColor;
        Color pacman;
        Color ghostC;
        Color dotC;
        Color bigDotC;

        Image pacmanSpriteSheet;
        Image tempBound;
        Image getSprite(Image, int, int);

    public:
        MapBuilder();
	    Map* createMap(Texture2D mapImage);

};