#version 460

in vec3 VertexPosition;
in vec3 VertexColor;

out vec3 Color;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjMatrix;

void main()
{
	Color = VertexColor;
	gl_Position = ViewMatrix * ModelMatrix * vec4(VertexPosition,1.0);
}