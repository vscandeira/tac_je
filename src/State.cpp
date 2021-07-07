#include <iostream>
#include <string>
#include <cmath>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "State.h"
#include "Sound.h"
#include "Face.h"
#include "Vec2.h"
#include "Rect.h"


State::State() {
	GameObject* go = new GameObject();
	std::string s = "assets/img/ocean.jpg";
	bg = new Sprite(*go, s);
	bg->Render();
	go->AddComponent(bg);
	objectArray.emplace_back(std::unique_ptr<GameObject>(go));
	std::string m = "assets/audio/stageState.ogg";
	music = new Music(m);
	quitRequested = false;
}

State::~State() {
	delete bg;
	delete music;
	delete &quitRequested;
	for (int i=objectArray.size(); i>0; i--) {
		objectArray[i-1].release();
		objectArray.erase(objectArray.begin() + i - 1);
	}
	objectArray.clear();
}

void State::Input(){
	double PI = M_PI;
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			std::cout<<"\nState Input: SDL_QUIT\n";
			quitRequested = true;
		}

		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			std::cout<<"\nState Input: SDL_MOUSEBUTTONDOWN\n";
			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains( {(float)mouseX, (float)mouseY} ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			std::cout<<"\nState Input: SDL_KEYDOWN\n";
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				std::cout<<"\nState Input: SDLK_ESCAPE\n";
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				std::cout<<"\nState Input: SDL else KEYDOWN\n";
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				std::cout<<"\nState Input: SDL else KEYDOWN Vec2 created\n";
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int mouseX, int mouseY){
	double PI = M_PI;
	Vec2 rot = Vec2( mouseX, mouseY ).GetRotated(-PI + PI*(rand() % 1001)/500.0);

	GameObject* go = new GameObject();
	std::cout<<"\nState AddObject: go created \n";

	std::string sp = "assets/img/penguinface.png";
	Sprite* spr = new Sprite(*go, sp);
	std::cout<<"\nState AddObject: sprite created \n";
	go->AddComponent(spr);
	std::cout<<"\nState AddObject: sprite added \n";
	Rect* r = new Rect( (float) mouseX/*-(spr->GetWidth()/2)*/, (float) mouseY/*-(spr->GetHeight()/2)*/, (float) spr->GetWidth(), (float) spr->GetHeight() );
	std::cout<<"\nState AddObject: rect created \n";
	go->box = *r;

	std::string sd = "assets/audio/boom.wav";
	Sound* snd = new Sound(*go, sd);
	std::cout<<"\nState AddObject: sound created \n";
	go->AddComponent(snd);
	std::cout<<"\nState AddObject: sound added \n";

	Face* fc = new Face(*go);
	std::cout<<"\nState AddObject: face created \n";
	go->AddComponent(fc);
	std::cout<<"\nState AddObject: face added \n";
	objectArray.emplace_back(std::unique_ptr<GameObject>(go));
	std::cout<<"\nState AddObject: go emplaced\n";

	std::cout<<"\nState AddObject: mouseX "<<mouseX<<" - mouse Y "<<mouseY<<"\n\n";
	return;
}

bool State::QuitRequested() const{
	return quitRequested;
}

void State::LoadAssets(){
	//bg->Open();
	//music->Open();
}

void State::Update(float dt){
	Input();
	int len = objectArray.size();
	for (int i=0; i<len; i++) {
		objectArray[i].get()->Update(dt);
	}
	for (int i=0; i<len; i++) {
		if (objectArray[i].get()->IsDead()) {
			objectArray[i].release();
			objectArray.erase(objectArray.begin()+i);
		}
	}
}

void State::Render(){
	int len = objectArray.size();
	for (int i=0; i<len; i++) {
		objectArray[i].get()->Render();
	}
}
