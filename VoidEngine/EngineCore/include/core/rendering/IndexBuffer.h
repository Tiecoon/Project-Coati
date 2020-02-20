#pragma once
//STD Headers
#include <cstdint>

//Library Headers

//Void Engine Headers

namespace core {

	class IndexBuffer {
	public:
		/**
		 * Factory method to create a index buffer appropriate for the current
		 * rendering pipeline.
		 */
		static IndexBuffer* Create(uint32_t* indices, uint32_t size);

		/**
		 * Destructor
		 */
		virtual ~IndexBuffer() {};

		/**
		 * Binds VertexBuffer in rendering pipeline
		 */
		virtual void Bind() const = 0;

		/**
		 * Unbinds VertexBuffer in rendering pipeline
		 */
		virtual void Unbind() const = 0;

	};

}