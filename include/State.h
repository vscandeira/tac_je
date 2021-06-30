#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

#define INCLUDE_SDL
#define cndaINCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Component.h"
#include "GameObject.h"
#include "Music.h"
#include "Sprite.h"
#include "Sound.h"
#include "Face.h"
#include "Vec2.h"
#include "Rect.h"

class State {
private:
	Sprite* bg;
	Music* music;
	bool quitRequested;
	std::vector<std::unique_ptr<GameObject>> objectArray;

	void Input();
	void AddObject(int mouseX, int mouseY);
public:
	State();
	~State();
	bool QuitRequested() const;
	void LoadAssets();
	void Update(float dt);
	void Render();
};

#endif /* STATE_H_ */
