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
#include "InputInterfaceManager.h"


namespace EngineCore {

	//Forward Class declarations
	class MessageBus;
	class InputEvent;


	class InputManager {
	private:


	public:
		///CTORS
		/**
		 * Constructor
		 * @param playerInterface the Engine's interface to all HID devices connected to the game
		 */
		InputManager(std::shared_ptr<InputInterfaceManager> playerInterface);

		/**
		 * Destructor
		 */
		~InputManager() = default;

		///Public member functions
		/**
		 * Polls and process all input events for the current frame
		 */
		void HandleInput();

	private:
		///Private member functions
		
		/**
		 * Loads keybindings from HDD
		 */
		void LoadKeybindings();

		/**
		 * Polls and processes keyboard events from the current frame
		 */
		void HandleKeyboard();

		/**
		 * Polls and processes mouse events from the current frame
		 */
		void HandleMouse();

		/**
		 * Polls and processes gamepad events fromt he current frame
		 */
		void HandleGamepad();


		///Private class members
		/** The keybindings currently used by the input manager */
		Keybindings Bindings;

		/** The engine's current input interface */
		std::shared_ptr<InputInterfaceManager> PlayerInterface;
	};

}