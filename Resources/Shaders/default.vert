#version 450 core
precision highp float;

//Uniforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalMatrix;

//Inputs
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexPos;

//Outputs
out vec2 texCoord;
out vec3 normal;
out vec3 fragmentPosition;

void main(){
    texCoord = aTexPos;
    normal = normalize(normalMatrix * aNormal);
    
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    fragmentPosition = vec3(model * vec4(aPos, 1.0));
}