// Include standard headers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

using namespace std;

GLuint m_VAO;
GLuint m_VBO;
GLuint renderingProgram;

int dimVertices;
int numberOfVertices;
unsigned nrVertices;

GLuint createShaderProgram() {
    // declares two shaders as character strings
    // Vertex Shader code
    static const char *vshaderSource =
    		"#version 330  \n"
    		"layout (location = 0) in vec3 vertex_position; \n"
    		"layout (location = 1) in vec3 vertex_color; \n"
    		"out vec3 vs_position; \n"
    		"out vec3 vs_color; \n"
    		"void main() { \n"
    		" vs_position = vertex_position;	\n"
    		" vs_color = vertex_color;	\n"
    		" gl_Position = vec4(vertex_position,1.f);	\n"
    		"}";

    // Fragment Shader
    static const char *fshaderSource =
    		"#version 330  \n"
    		"in vec3 vs_position; \n"
    		"in vec3 vs_color; \n"
    		"out vec4 fColor; \n"
    		 "void main(){ \n"
    		 " fColor = vec4(vs_color, 1.0f); \n"
    		  "}";

    // glCreateShader : generates the two shaders of types GL_VERTEX_SHADER and GL_FRAGMENT_SHADER
    // OpenGL creates each shader object, and returns an integer ID for each
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    // loads the GLSL code from the strings into the empty shader objects
    // glShaderSource(ShaderObject, NumberOfStrings : 1, ArrayOfPointers, -)
    glShaderSource(vShader, 1, &vshaderSource, NULL);
    glShaderSource(fShader, 1, &fshaderSource, NULL);

    // the shaders are each compiled
    glCompileShader(vShader);
    glCompileShader(fShader);

    // the integer ID of a program object
    GLuint vfProgram = glCreateProgram();

    // attatches each of the shaders to the program object
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);

    // requests that the GLSL compiler ensure that the shaders are compatible
    glLinkProgram(vfProgram);

    return vfProgram;
}

struct vertex{
	vec3 position;
	vec3 color;
};


void init(){
	renderingProgram = createShaderProgram();

	float t=1.0f;
	vertex verticesIniciales[3];

	//p0
	verticesIniciales[0].position=vec3(0.35,0.8,0.0);
	verticesIniciales[0].color= vec3(0.8f, 0.4f, 0.8f);

	//p1
	verticesIniciales[1].position= verticesIniciales[0].position + t * vec3(-1.15f,0.0f,0.0f);
	verticesIniciales[1].color= vec3(1.0,0.0,0.0);


	//p2
	verticesIniciales[2].position=verticesIniciales[1].position + t *vec3(0.3f,-0.9f,0.0f);
	verticesIniciales[2].color= vec3(0.0f, 0.6f, 0.0f);

	//p3

	verticesIniciales[3].position= verticesIniciales[2].position + t * vec3(0.6f,0.0f,0.0f);
	verticesIniciales[3].color= vec3(0.6f, 0.6f, 0.0f);


	vertex verticesXYZ[15];


	//vectores directores para generar triangulos
	vertex vd[2];
	vd[0].position=vec3(0.45f,-0.7f,0.0f);
	vd[0].color=vec3(0.8f, 0.4f, 0.8f);
	vd[1].position=vec3(-0.6f,0.0f,0.0f);
	vd[1].color=vec3(0.8f, 0.4f, 0.8f);


	vertex vd1[3];
	vd1[0].position=vec3(0.0f,0.0f,0.0f);
	vd1[0].color=vec3(1.0,.0,0.0);
	vd1[1].position=vec3(0.0f,-0.7f,0.0f);
	vd1[1].color=vec3(1.0,0.0,0.0);
	vd1[2].position=vec3(0.6f,0.0f,0.0f);
	vd1[2].color=vec3(1.0,0.0,0.0);


	vertex vd2[3];
	vd2[0].position=vec3(0.0f,0.0f,0.0f);
	vd2[0].color=vec3(0.0f, 0.6f, 0.0f);
	vd2[1].position=vec3(0.2f,-0.7f,0.0f);
	vd2[1].color=vec3(0.0f, 0.6f, 0.0f);
	vd2[2].position=vec3(-0.4f,0.0f,0.0f);
	vd2[2].color=vec3(0.0f, 0.6f, 0.0f);

	vertex vd3[6];
	vd3[0].position=vec3(0.0f,0.0f,0.0f);
	vd3[0].color=vec3(0.6f, 0.6f, 0.0f);
	vd3[1].position=vec3(0.8f,0.0f,0.0f);
	vd3[1].color=vec3(0.6f, 0.6f, 0.0f);
	vd3[2].position=vec3(0.0f,-0.7f,0.0f);
	vd3[2].color=vec3(0.6f, 0.6f, 0.0f);
	vd3[3].position=vec3(0.0f,0.0f,0.0f);
	vd3[3].color=vec3(0.6f, 0.6f, 0.0f);
	vd3[4].position=vec3(-0.8f,0.0f,0.0f);
	vd3[4].color=vec3(0.6f, 0.6f, 0.0f);
	vd3[5].position=vec3(0.0f,0.7f,0.0f);
	vd3[5].color=vec3(0.6f, 0.6f, 0.0f);


	verticesXYZ[0].position = verticesIniciales[0].position;
	verticesXYZ[0].color = verticesIniciales[0].color;


	for (int i = 1; i < 3; i++) {
		verticesXYZ[i].position = verticesXYZ[i-1].position + vd[i-1].position;
		verticesXYZ[i].color = vd[0].color;
	}


	vec3 aux = verticesIniciales[1].position;
	int j=0;
	for(int i=3; i<6; i++){
		verticesXYZ[i].position = aux + vd1[j].position;
		verticesXYZ[i].color = vd1[0].color;
		aux=verticesXYZ[i].position;
		j++;
	}

	vec3 aux2 = verticesIniciales[2].position;
	j=0;
	for(int i=6; i<9; i++){
			verticesXYZ[i].position = aux2 + vd2[j].position;
			verticesXYZ[i].color = vd2[0].color;
			aux2=verticesXYZ[i].position;
			j++;
	}

	vec3 aux3 = verticesIniciales[3].position;
	j=0;
	for(int i=9; i<12; i++){
		verticesXYZ[i].position = aux3 + vd3[j].position;
		verticesXYZ[i].color = vd3[0].color;
		aux3 =verticesXYZ[i].position;
		j++;
	}

	vec3 aux4 = verticesXYZ[11].position;
	j=3;
	for(int i=12; i<15; i++){
		verticesXYZ[i].position = aux4 + vd3[j].position;
		verticesXYZ[i].color = vd3[0].color;
		aux4 =verticesXYZ[i].position;
		j++;
	}


	nrVertices= sizeof(verticesXYZ)/sizeof(vertex);

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);


	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(verticesXYZ),
			verticesXYZ,
			GL_STATIC_DRAW
		);
	glVertexAttribPointer(
					0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
					3,                  // size
					GL_FLOAT,           // type
					GL_FALSE,           // normalized?
					sizeof(vertex),                  // stride
					(GLvoid*)offsetof(vertex,position)            // array buffer offset
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
				1,			// Lembra do (layout = 1 ) no vertex shader ? Esse valor indica qual atributo estamos indicando
				3,			// cada vertice é composto de 3 valores
				GL_FLOAT,	// cada valor do vértice é do tipo GLfloat
				GL_FALSE,	// Quer normalizar os dados e converter tudo pra NDC ? ( no nosso caso, já esta tudo correto, então deixamos como FALSE)
				sizeof(vertex),// De quantos em quantos bytes, este atributo é encontrado no buffer ? No nosso caso 3 floats pros vertices + 3 floats pra cor = 6 floats
				(GLvoid*)offsetof(vertex,color)	// Onde está o primeiro valor deste atributo no buffer. Nesse caso, 3 floats após o início do buffer
	);

	glEnableVertexAttribArray(1);


	glBindVertexArray(0);

}

void display(double currentTime) {
	glUseProgram(renderingProgram);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, nrVertices); // 3 indices starting at 0 -> number of Vertex
	glBindVertexArray(0);


}

int main( void )
 {
	// Initialise GLFW
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); 	// Resizable option.

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(800, 800, "Tarea Triangulos by Sebastian Asis Romero", NULL, NULL);

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	init();

	// Check if the window was closed
	while (!glfwWindowShouldClose(window)) {
		display(glfwGetTime());
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup VBO
	glDeleteBuffers(1, &m_VBO);
	glDeleteVertexArrays(1, &m_VAO);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

