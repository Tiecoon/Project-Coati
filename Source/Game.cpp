//STD Headers
#include <iostream>

//Library Headers


//Coati Headers
#include "Game.h"
#include "MessageBus.h"
#include "WindowManager.h"
#include "World.h"
#include "Renderer.h"
#include "InputManager.h"
#include "AudioManager.h"

//CTORS
Game::Game(std::string name) : GameName(name) {

	//Init Higher Level Game Objects
	InitGame();

	//Start game loop
	ExecuteGameLoop();

}

Game::~Game(){

}

//Private Functions

//Initialize higher level game objects
void Game::InitGame(){
	GameMessageBus = std::make_shared<MessageBus>();
	Window = std::make_shared<WindowManager>(GameName);

	GameWorld = std::make_unique<World>(GameMessageBus);
	GameRenderer = std::make_unique<Renderer>(Window);
	GameInputManager = std::make_unique<InputManager>(GameMessageBus, Window);
	GameAudioManager = std::make_unique<AudioManager>(GameMessageBus);

}

void Game::ProcessInput(){
	GameInputManager->PollInput();
}

void Game::Update(double deltaSeconds){
	//Triggers Events
	GameMessageBus->DispatchMessages();

	//Ticks actors
	GameWorld->Update(deltaSeconds);
}

void Game::Render(){
	GameRenderer->Render();
}


void Game::ExecuteGameLoop(){
	auto previousTime = Timer::now();
	while (true) {
		//Get current time
		auto currentTime = Timer::now();
		std::chrono::duration<double> deltaSeconds = currentTime - previousTime;

		ProcessInput();
		Update(deltaSeconds.count());
		Render();

		//Update previous time
		previousTime = Timer::now();
	}
	return;
}