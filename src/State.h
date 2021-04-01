#ifndef STATE_H_
#define STATE_H_

#include "Music.h"
#include "Sprite.h"

//class Music;
//class Sprite;

class State {
private:
	Sprite* bg;
	Music* music;
	bool quitRequested;
public:
	State();
	~State();
	bool QuitRequested() const;
	void LoadAssets();
	void Update(float dt);
	void Render();
};

#endif /* STATE_H_ */
