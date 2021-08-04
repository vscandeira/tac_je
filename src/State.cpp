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
	objectArray.push_back(std::unique_ptr<GameObject>(go));
	std::string m = "assets/audio/stageState.ogg";
	music = new Music(m);
	quitRequested = false;
}

State::~State() {
	delete bg;
	delete music;
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
			std::cout<<"\nState Input: SDL_MOUSEBUTTONDOWN - X: " <<mouseX << " - Y: "<<mouseY<< "\n";
			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
//				std::cout<<"State Input: SDL_MOUSEBUTTONDOWN - Percorrendo vetor de objetos - Objeto: " << i << "\n";
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains( {(float)mouseX, (float)mouseY} ) ) {
					std::cout<<"Hit"<<std::endl;
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						//face->Damage(std::rand() % 10 + 10);
						int damage = std::rand() % 10 + 10;
						face->Damage(std::rand() % 10 + 10);
						std::cout<<"Dano aplicado: "<<damage<<std::endl;
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
				std::cout<<"State Input: SDLK_ESCAPE\n";
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				std::cout<<"State Input: SDL else KEYDOWN\n";
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int mouseX, int mouseY){
	GameObject* go = new GameObject();

	std::string sp = "assets/img/penguinface.png";
	Sprite* spr = new Sprite(*go, sp);
	Rect* r = new Rect( (float) mouseX-(spr->GetWidth()/2), (float) mouseY-(spr->GetHeight()/2), (float) spr->GetWidth(), (float) spr->GetHeight() );
	go->AddComponent(spr);
	go->box = *r;

	std::string sd = "assets/audio/boom.wav";
	Sound* snd = new Sound(*go, sd);
	go->AddComponent(snd);

	Face* fc = new Face(*go);
	go->AddComponent(fc);
	objectArray.emplace_back(std::unique_ptr<GameObject>(go));
	std::cout<<"\nState AddObject: go emplaced\n";

	std::cout<<"State AddObject: boxX: "<<go->box.x<<" - boxY: "<<go->box.y<<" - boxW: "<<go->box.w<<" - boxW: "<<go->box.w<<"\n";
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
