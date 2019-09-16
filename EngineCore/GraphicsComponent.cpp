//STD Headers

//Library Headers

//Void Engine Headers
#include "GraphicsComponent.h"

namespace EngineCore {

	GraphicsComponent::GraphicsComponent(const std::vector<float>& model, const ShaderProgram& material)
	 : VAO(-1), IsValid(true), Vertices(std::move(model)), Material(std::move(material)) {
		
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		//Initialize this component's VAO
		glBindVertexArray(VAO);

		//Bind VBO to VAO
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Vertices.size(), Vertices.data(), GL_STATIC_DRAW);

		//Bind EBO to VAO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//Set Vertex Attributes for VAO
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}

	GraphicsComponent::~GraphicsComponent() {
	}

	void GraphicsComponent::Draw() {	
		//Specify shader program
		Material.Use();

		//Activate VAO
		glBindVertexArray(VAO);

		//Draw component
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

}