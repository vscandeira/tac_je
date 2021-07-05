#ifndef STATE_H_
#define STATE_H_

#include <vector>
#include <memory>

#include "GameObject.h"
#include "Music.h"
#include "Sprite.h"

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
