//STD Headers

//Library Headers

//Void Engine Headers
#include "utils/Logger.h"

#include "platform/OpenGL/OpenGLIndexBuffer.h"

#include "rendering/IndexBuffer.h"
#include "rendering/Renderer.h"

namespace core {
	
	std::shared_ptr<IndexBuffer> IndexBuffer::Create(const uint32_t* indices, uint32_t size) {
		switch (Renderer::GetRendererAPI()) {
			case RenderDevice::API::OPENGL:
				return std::make_shared<OpenGLIndexBuffer>(indices, size);
		}

		VE_ASSERT(false, "Index buffer does not support selected rendering API: ERROR");
		return nullptr;
	}

}