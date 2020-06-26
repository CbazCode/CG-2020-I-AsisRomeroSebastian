//============================================================================
// Name        : Program 1, Drawing one Point
// Professor   : Herminio Paucar
// Version     :

// Description : Display my first point
//============================================================================

// Include standard headers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

using namespace std;

GLuint VAO;
GLuint VBO;

int dimVertices;
int numberOfVertices;

void init(){
	// Create vertices
	dimVertices = 3;
	numberOfVertices = 13;
	GLfloat m_Vertices[] = {
			0.7f, 0.1f, 0.0f,
			0.7f, 0.6f, 0.0f,
			0.3f, 0.1f, 0.0f,
			0.3f, 0.6f, 0.0f,
			0.5f, 0.35f, 0.0f,
			0.0f, 0.0f, 0.0f,
			-0.3f, 0.1f, 0.0f,
			-0.7f, 0.1f, 0.0f,
			-0.7f, 0.6f, 0.0f,
			-0.5f,-0.5f, 0.0f,
			0.35f,-0.55f,0.0f,
			0.40f,-0.50f,0.0f,
			0.45f,-0.45f,0.0f


	};


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(m_Vertices),
			m_Vertices,
			GL_STATIC_DRAW
		);
}

void display(double currentTime) {
	// Clear the screen
	// Dark blue background
	glClearColor(0.4f, 0.0f, 0.8f, 0.0f);
	glClear( GL_COLOR_BUFFER_BIT);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);//Habilita el vertex array 0
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(
			0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
			dimVertices,        // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride (Desde donde inicia)
			(void*) 0            // array buffer offset (no hay salto de busqueda de elemento)
	);
	glPointSize(20.0f);
	// Draw the primitive GL_POINTS
	glDrawArrays(GL_POINTS, 0, numberOfVertices); // 3 indices starting at 0 -> number of Vertex
	glDisableVertexAttribArray(0);
}

int main( void ){
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
	window = glfwCreateWindow(800, 800, "Asis Romero Sebastian Alexander", NULL, NULL);

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
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

