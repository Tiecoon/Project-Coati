#version 450 core
//Uniforms
uniform float desiredColor;
uniform sampler2D space;
uniform sampler2D bricks;

//Inputs
in vec2 texCoord;

//Outputs

void main(){
    gl_FragColor = 
        vec4(1,1,1,0) * mix(
            texture(space, texCoord), texture(bricks, texCoord), 0.2
        );
}