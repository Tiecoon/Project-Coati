//STD Headers
#include <iostream>

//Library Headers
#include "glad/glad.h"
#include "GLFW/glfw3.h"

//Coati Headers
#include "WindowManager.h"
#include "KeyboardInput.h"

namespace EngineCore {

	WindowManager::WindowManager(std::string GameName) {
		this->GameName = GameName;
		InitGLFW();
		InitGLAD();
	}


	WindowManager::~WindowManager() {
		glfwTerminate();
	}


	//Private Member Functions

	void WindowManager::InitGLFW() {
		if (!glfwInit()) {
			// Initialization failed
			return;
		}

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Window = std::shared_ptr<GLFWwindow>(
			glfwCreateWindow(640, 480, GameName.c_str(), nullptr, nullptr),
			DeleteWindow
			);

		if (Window.get() == nullptr) {
			glfwSetWindowShouldClose(Window.get(), GLFW_TRUE);
		}

		glfwMakeContextCurrent(Window.get());
		glfwSetFramebufferSizeCallback(Window.get(), ResizeFrameBuffer);
		glfwSetKeyCallback(Window.get(), DispatchKeyCallback);

	}

	void WindowManager::InitGLAD() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to initialize GLAD" << std::endl;
		}

		glViewport(0, 0, 800, 600);
	}

	//Public Member Functions

	std::shared_ptr<GLFWwindow> WindowManager::getWindow() {
		return Window;
	}

	void WindowManager::SwapBuffers() {
		glfwSwapBuffers(Window.get());
		glfwPollEvents();
	}

	void WindowManager::PollInput() {
		glfwPollEvents();
	}

	bool WindowManager::WindowTerminated() {
		return glfwWindowShouldClose(Window.get());
	}

}