//STD Headers
#include <iostream>

//Library Headers


//Coati Headers
#include "World.h"
#include "MessageBus.h"

World::World(std::shared_ptr<MessageBus> bus){
	this->GameMessageBus = GameMessageBus;
	
	currentLevel = std::make_unique<Level>(Level(1));

	levelList.push_back(*currentLevel);

	std::cout << "Hello world!\n";
}


World::~World(){
	std::cout << "Goodbye world!\n";
}

void World::Update(double deltaSeconds){

}


void World::SwitchLevel(int levelID) {

	//reset the currentLevel pointer
	currentLevel.reset();
	
	bool levelAlreadyGenerated = false;
	for (int i = 0; i < levelList.size(); i++) {
		if (levelList[i].GetID() == levelID) {
			currentLevel = std::make_unique<Level>(levelList.at(i));
			levelAlreadyGenerated = true;
		}
	}

	if (!levelAlreadyGenerated) {
		currentLevel = std::make_unique<Level>(Level(levelID));
		levelList.push_back(*currentLevel);
	}

}

void World::Tick() {

	for (int i = 0; i < levelList.size(); i++) {
		levelList[i].Tick();
	}

}