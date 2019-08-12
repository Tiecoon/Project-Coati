//STD Headers
#include <memory>

//Library Headers
#include "glad/glad.h"

//Coati Headers
#include "Renderer.h"
#include "WindowManager.h"

namespace EngineCore {
	//CTORS
	Renderer::Renderer(
		std::shared_ptr<WindowManager> window, EngineInterfacePtr engineInterface, const std::string& configFile) 
		: Configurable(configFile, engineInterface->GetResourceManager()), 
		  VoidEngineInterface(std::move(engineInterface)),
		  Window(std::move(window)) {
		
		this->Window = Window;

	}


	Renderer::~Renderer() {
	}

	//Public Member Functions

	void Renderer::Render() {
		glClearColor(0.8f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Window->SwapBuffers();
	}

	void Renderer::Configure() {
		//TODO (MrLever): Leverage configuration settings
	}

	//Private Member Functions

}