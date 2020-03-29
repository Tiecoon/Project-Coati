//STD Headers
#include <fstream>

//Library Headers

//Void Engine Headers
#include "rendering/Shader.h"
#include "utils/Logger.h"

namespace core {
	Shader::Shader(ShaderType type, const std::string& filePath) 
		: Resource(filePath), m_Type(type), m_ShaderHandle(-1) {
		Load();
	}

	Shader::~Shader() {
		//When the shader is no longer needed, instruct OpenGL to discard it
		glDeleteShader(m_ShaderHandle);
	}

	bool Shader::Load() {
		std::ifstream ifs;
		std::string sourceBuffer;
		std::string lineBuffer;

		ifs.open(ResourcePath);
		if (!ifs.is_open()) {
			utils::Logger::LogError("Shader " + ResourcePath.string() + "not found.");
			return false;
		}

		while (std::getline(ifs, lineBuffer)) {
			sourceBuffer += lineBuffer + "\n";
		}

		ifs.close();

		m_ShaderSource = sourceBuffer;
		return true;
	}
	
	bool Shader::LoadErrorResource() {
		m_ShaderSource = "";
		return false;
	}

	void Shader::Initialize() {
		//Attempt to compile shader
		const char* shaderCode = m_ShaderSource.c_str();
		m_ShaderHandle = glCreateShader(static_cast<GLuint>(m_Type));
		glShaderSource(m_ShaderHandle, 1, &shaderCode, NULL);
		glCompileShader(m_ShaderHandle);

		//Verify shader compilation
		int success;
		char infoBuffer[1024];
		glGetShaderiv(m_ShaderHandle, GL_COMPILE_STATUS, &success);

		if (!success) {
			ResourceValid = false;
			glGetShaderInfoLog(m_ShaderHandle, 1024, NULL, infoBuffer);
			std::stringstream errorStream;
			errorStream << "SHADER COMPILATION ERROR:\n";
			errorStream << "\tShader Location: " << ResourcePath << "\n";
			errorStream << infoBuffer;
			utils::Logger::LogError(errorStream.str());
		}

		IsInitialized = true;
	}
}