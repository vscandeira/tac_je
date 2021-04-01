#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>

#include "SDL.h"
#include "SDL_image.h"

//#include "Game.h"


class Sprite {
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
public:
	Sprite();
	Sprite(std::string file);
	~Sprite();
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);
	int GetWidth() const;
	int GetHeight() const;
	bool IsOpen() const;
};

#endif /* SPRITE_H_ */
