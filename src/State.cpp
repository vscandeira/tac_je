#include "State.h"

State::State() {
	GameObject* go = new GameObject();
	std::string s = "assets/img/ocean.jpg";
	bg = new Sprite(*go, s);
	bg->Render();
	go->AddComponent(bg);
	objectArray.emplace_back(go);
	std::string m = "assets/audio/stageState.ogg";
	music = new Music(m);
	quitRequested = false;
}

State::~State() {
	delete bg;
	delete music;
	delete &quitRequested;
	objectArray.clear();
}

void State::Input(){
	double PI = M_PI;
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	//SDL_PumpEvents();
	SDL_GetMouseState(&mouseX, &mouseY);
	std::cout<<"print state input 1: "<< mouseX << " - " << mouseY <<std::endl;
	AddObject(mouseX+200, mouseY+200);
	std::cout<<"print state input 2"<<std::endl;

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

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
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( (double) -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}
void State::AddObject(int mouseX, int mouseY){
	double PI = M_PI;
	Vec2 prov = Vec2( mouseX, mouseY );
	double ang = (double) -PI + PI*(rand() % 1001)/500.0;
	Vec2 rot = prov.GetRotated(ang);
	GameObject* go = new GameObject();
	std::string sp = "assets/img/penguinface.png";
	Sprite* spr = new Sprite(*go, sp);
	go->AddComponent(spr);
	Rect *r = new Rect( (float) mouseX/*-(spr->GetWidth()/2)*/, (float) mouseY/*-(spr->GetHeight()/2)*/, (float) spr->GetWidth(), (float) spr->GetHeight() );
	go->box = *r;
	std::string sd = "assets/audio/boom.wav";
	Sound* snd = new Sound(*go, sd);
	go->AddComponent(snd);
	Face* fc = new Face(*go);
	go->AddComponent(fc);
	objectArray.emplace_back(go);
	std::cout<<"print state addobject final"<<std::endl;
	std::cout<<go->IsDead()<<std::endl;
	std::cout<<objectArray.size()<<std::endl;
	return;
	std::cout<<"print state addobject final2"<<std::endl;
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
		GameObject* go = (GameObject*) objectArray[i].get();
		go->Update(dt);
	}
	for (int i=0; i<len; i++) {
		GameObject* go = (GameObject*) objectArray[i].get();
		if (go->IsDead()) {
			objectArray.erase(objectArray.begin()+i);
		}
	}
/*
	if (SDL_QuitRequested()) {
		quitRequested = true;
	}
*/
}
void State::Render(){
	int len = objectArray.size();
	for (int i=0; i<len; i++) {
		GameObject* go = (GameObject*) objectArray[i].get();
		go->Render();
	}
}
