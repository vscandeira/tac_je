#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"


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
