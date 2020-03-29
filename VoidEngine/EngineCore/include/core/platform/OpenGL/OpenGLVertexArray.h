#pragma once
//STD Headers
#include <memory>

//Library Headers

//Void Engine Headers
#include "core/rendering/VertexArray.h"

namespace core {

	class OpenGLVertexArray : public VertexArray {
	public:
		/**
		 * Constructor
		 */
		OpenGLVertexArray();

		/**
		 * Destructor
		 */
		virtual ~OpenGLVertexArray() {};

		/**
		 * Binds VertexArray in rendering pipeline
		 */
		void Bind() const override;

		/**
		 * Unbinds VertexArray in rendering pipeline
		 */
		void Unbind() const override;

		/**
		 * Links a VertexBuffer to the VertexArray
		 */
		void LinkVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) override;

		/**
		 * Links a IndexBuffer to the VertexArray
		 */
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer) override;

		/**
		 * Accessor for linked index buffer
		 */
		std::shared_ptr<const IndexBuffer> GetIndexBuffer() const override;

		/**
		 * Accessor for linked vertex buffers
		 */
		std::vector<std::shared_ptr<VertexBuffer>> GetVertexBuffers() const override;

	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;


	};

}