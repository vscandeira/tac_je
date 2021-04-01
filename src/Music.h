#ifndef MUSIC_H_
#define MUSIC_H_

#include <string>

#include "SDL.h"
#include "SDL_mixer.h"

//#include "Game.h"

class Music {
private:
	Mix_Music* music;
public:
	Music();
	Music(std::string file);
	~Music();
	void Play(int times=-1);
	void Stop(int msToStop=1500);
	void Open(std::string file);
	bool IsOpen() const;
};

#endif /* MUSIC_H_ */
