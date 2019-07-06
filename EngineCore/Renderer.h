#pragma once
//STD Headers
#include <memory>

//Library Headers

namespace EngineCore {

	//Forward Class declarations
	class WindowManager;

	class Renderer {
	public:
		///CTORS
		
		/**
		 * Constructor
		 * @param window The Window the renderer draws to
		 */
		Renderer(std::shared_ptr<WindowManager> window);

		/**
		 * Destructor
		 */
		~Renderer();

		///Public member functions
		
		/** 
		 * Draws to the sceen
		 */
		void Render();

	private:
		///Private member functions

		///Private class members
		
		/** Shared with the Input System, the render can draw to this window. */
		std::shared_ptr<WindowManager> Window;

	};

}