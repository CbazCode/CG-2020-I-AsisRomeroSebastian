
#version 330  
in vec3 vs_position; 
in vec3 vs_color; 
out vec4 fColor; 
void main(){
   fColor = vec4(vs_color, 1.0f); 
  }