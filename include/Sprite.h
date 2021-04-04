#ifndef SPRITE_H_
#define SPRITE_H_

#include <iostream>
#include <string>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"


class Sprite : public Component {
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
public:
	Sprite(GameObject& associated);
	Sprite(GameObject& associated,std::string file);
	~Sprite();
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render();
	int GetWidth() const;
	int GetHeight() const;
	bool IsOpen() const;
};

#endif /* SPRITE_H_ */
