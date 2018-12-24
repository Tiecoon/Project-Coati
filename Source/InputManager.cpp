//STD Headers
#include <memory>
#include <iostream>

//Library Headers


//Coati Headers
#include "InputManager.h"
#include "MessageBus.h"
#include "WindowManager.h"

//Ctors
InputManager::InputManager(
	std::shared_ptr<MessageBus> Bus, 
	std::shared_ptr<WindowManager> Window
	) : MessageBusNode(Bus)
{
	this->RegisterReciever();
	this->Window = Window;
	Window->SetWindowUser<InputManager>(this);
	
	//GLFWwindow* window;
	PublishMessage("Input Manager Initialized", Initialization);
}


InputManager::~InputManager() {
}




//Private Member Functions

//Public Member Functions
void InputManager::PollInput() {
	Window->PollInput();
}

void InputManager::HandleInput(int key, bool pressed) {
	//Lookup in Keybindings
	//Send message
	std::cout << "Got key: " << key;
}

void InputManager::RegisterReciever() {
	GameMessageBus->AddReciever(this, Initialization);
}

void InputManager::ReceiveMessage(Message message) {
	std::cout << "Input Manager Message Recieved: \n";
	std::cout << "\t" << message.getEvent() << "\n";
}
