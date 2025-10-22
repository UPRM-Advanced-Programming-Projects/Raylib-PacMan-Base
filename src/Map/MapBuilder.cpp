#include "MapBuilder.hpp"

MapBuilder::MapBuilder() {
	entityManager = new EntityManager();
	pixelMultiplier = 16;

	boundBlockColor = (Color){0, 0, 0, 255};
	pacman = (Color){255,255, 0, 255};
	ghostC = (Color){25, 255,0, 255};
	dotC = (Color){255, 10, 0, 255};
	bigDotC = (Color){167, 0, 150, 255};

	pacmanSpriteSheet = LoadImage("images/Background.png");
	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){603, 18, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){615, 37, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){635, 37, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){655, 37, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){655, 57, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){655, 75, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){656, 116, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){656, 136, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){655, 174, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){655, 155, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){655, 192, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){664, 232, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){479, 191, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){494, 191, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){479, 208, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));

	tempBound =  ImageFromImage(pacmanSpriteSheet, (Rectangle){479, 223, 16, 16});
	bound.push_back(LoadTextureFromImage(tempBound));
}

Map* MapBuilder::createMap(Texture2D mapImage) {
	int xOffset = (GetScreenWidth() - mapImage.width * pixelMultiplier) / 2;
	int yOffset = (GetScreenHeight() - mapImage.height * pixelMultiplier) / 2;

    Color* pixelColors = LoadImageColors(LoadImageFromTexture(mapImage));
	Map* mapInCreation =  new Map(entityManager);

    for (int i = 0; i < mapImage.width; i++) {
        for (int j = 0; j < mapImage.height; j++) {
            Color currentPixel = pixelColors[j * mapImage.width + i];
            int xPos = i * pixelMultiplier + xOffset;
            int yPos = j * pixelMultiplier + yOffset;

            if (ColorIsEqual(currentPixel, boundBlockColor)) {
                BoundBlock* block = new BoundBlock(xPos, yPos, pixelMultiplier, pixelMultiplier, getSprite(LoadImageFromTexture(mapImage), i, j));
                mapInCreation->addBoundBlock(block);

            } else if (ColorIsEqual(currentPixel, pacman)) {
                Player* EvilPacMan = new Player(xPos, yPos, pixelMultiplier, pixelMultiplier, entityManager, LoadImage("images/evil-pacman.png"));
				Player* PacMan = new Player(xPos, yPos, pixelMultiplier, pixelMultiplier, entityManager, LoadImage("images/pacman.png"));
				mapInCreation->setPlayer(PacMan);
				mapInCreation->setAltPlayer(EvilPacMan);

            } else if(ColorIsEqual(currentPixel, ghostC)) {
                GhostSpawner* ghostSpawn = new GhostSpawner(xPos, yPos, pixelMultiplier, pixelMultiplier, entityManager, pacmanSpriteSheet);
                mapInCreation->setGhostSpawner(ghostSpawn);

            } else if(ColorIsEqual(currentPixel, dotC)) {
				int randNum = GetRandomValue(0, 100);

                if (randNum == 20) {
                    Cherry* cherry = new Cherry(xPos, yPos, pixelMultiplier, pixelMultiplier, pacmanSpriteSheet);
                    mapInCreation->addEntity(cherry);

                } else if (randNum == 30) {
                    Strawberry* strawberry = new Strawberry(xPos,yPos,pixelMultiplier,pixelMultiplier, pacmanSpriteSheet);
                    mapInCreation->addEntity(strawberry);

                } else if (randNum == 10) {
                    Apple* apple = new Apple(xPos,yPos,pixelMultiplier,pixelMultiplier, pacmanSpriteSheet);
                    mapInCreation->addEntity(apple);

                } else {
					Dot* dot = new Dot(xPos,yPos,pixelMultiplier,pixelMultiplier, pacmanSpriteSheet);
					mapInCreation->addEntity(dot);
				}

            } else if (ColorIsEqual(currentPixel, bigDotC)) {
                BigDot* bigDot = new BigDot(xPos,yPos,pixelMultiplier,pixelMultiplier, pacmanSpriteSheet);
                mapInCreation->addEntity(bigDot);
            }
        }
    }

    return mapInCreation;

}

Image MapBuilder::getSprite(Image mapImage, int i, int j) {
	Color currentPixel = boundBlockColor;
	Color* pixels = LoadImageColors(mapImage);

	Color leftPixel;
	Color rightPixel;
	Color upPixel;
	Color downPixel;

	if (i > 0) {
		leftPixel = pixels[j * mapImage.width + i - 1];
	} else {
		leftPixel = pacman;
	}

	if (i < mapImage.width - 1) {
		rightPixel = pixels[j * mapImage.width + i + 1];
	} else {
		rightPixel= pacman;
	}

	if (j > 0) {
		upPixel = pixels[(j - 1) * mapImage.width + i];
	} else {
		upPixel = pacman;
	}

	if (j < mapImage.height - 1) {
		downPixel = pixels[(j + 1) * mapImage.width + i];
	} else {
		downPixel = pacman;
	}

	if (!ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
        !ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[0]); // single dot

	} else if (!ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[2]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
               !ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[3]);

	} else if (!ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               !ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[4]);

	} else if (!ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[5]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
               !ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[6]);

	} else if (!ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               !ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[7]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               !ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[8]);

	} else if (!ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[9]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[10]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[11]);

	} else if (!ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[12]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && !ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[13]);

	} else if (ColorIsEqual(currentPixel, leftPixel) && !ColorIsEqual(currentPixel, upPixel) && 
               ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[14]);

    } else if (ColorIsEqual(currentPixel, leftPixel) && ColorIsEqual(currentPixel, upPixel) && 
               !ColorIsEqual(currentPixel, downPixel) && ColorIsEqual(currentPixel, rightPixel)) {
		return LoadImageFromTexture(bound[15]);

	} else {
		return LoadImageFromTexture(bound[1]);
	}
}