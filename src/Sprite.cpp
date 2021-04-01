#include "Sprite.h"
#include "Game.h"

Sprite::Sprite() {
	texture = nullptr;
}
Sprite::Sprite(std::string file){
	texture = nullptr;
	Open(file);
}
Sprite::~Sprite() {
	if(IsOpen()){
		SDL_DestroyTexture(texture);
	}
}

void Sprite::Open(std::string file){
	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
	SDL_Texture* sdl = IMG_LoadTexture(renderer, file.c_str());
	if ( sdl == nullptr) {
		printError(SDL_GetError(),"Sprite");
		return;
	} else {
		int a = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
		if (a < 0) {
			printError(SDL_GetError(),"Sprite");
			std::cout<< "w: " <<width<< " - h: " << height<< " - retorno: " << a << "\n" ;
			return;
		}
		SetClip(0,0,width,height);
	}
}
void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}
void Sprite::Render(int x, int y){
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}

	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = clipRect.w;
	dstRect.h = clipRect.h;

	SDL_RenderCopy(renderer, texture, &clipRect, &dstRect);
}
int Sprite::GetWidth() const{
	return width;
}
int Sprite::GetHeight() const {
	return height;
}
bool Sprite::IsOpen() const{
	bool flag = false;
	if (texture != nullptr) {
		flag = true;
	}
	return flag;
}
