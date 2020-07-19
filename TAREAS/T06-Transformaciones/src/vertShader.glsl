

#version 330  
layout (location = 0) in vec3 pos; 
layout (location = 1) in vec3 vertex_color; 
uniform mat4 model;
out vec3 vs_position; 
out vec3 vs_color; 
void main() { 
	gl_Position = model * vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0);
    vs_position = pos;	
    vs_color = vertex_color;		
 }