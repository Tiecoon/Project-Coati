#pragma once
//STD Headers
#include <memory>
#include <unordered_map>
#include <unordered_set>

//Library Headers

//Coati Headers
#include "MessageBusNode.h"
#include "KeyboardInput.h"
#include "Keybindings.h"
#include "InputInterface.h"


namespace EngineCore {

	//Forward Class declarations
	class MessageBus;
	class InputEvent;


	class InputManager : MessageBusNode {
	private:
		//Private class members
		Keybindings Bindings;
		std::shared_ptr<InputInterface> PlayerInterface;

	public:
		//CTORS
		InputManager(
			std::shared_ptr<MessageBus> GameMessageBus, 
			std::shared_ptr<InputInterface> inputInterface
		);
		~InputManager();

	private:
		virtual void RegisterReciever() override;
		void RegisterEvents() override;

		//Private member functions
		void LoadKeybindings();
		void HandleMouse();
		void HandleInput();

	public:
		//Public member functions
		void AddKeyBinding(KeyboardInput input, Message message);
		void HandleKeyboard();
		void ReceiveMessage(Message message) override;
	};

}