//============================================================================
// Name        : Rotate Triangle Object
// Professor   : Herminio Paucar
// Version     :
// Description :
//============================================================================

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include "Utils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

const float toRadians = 3.14159265f / 180.0f;

GLuint renderingProgram;

GLfloat* m_Vertices;
GLuint n_Vertices;
GLuint m_VBO;
GLuint m_VAO;

int dimVertices;

float curAngle = 0.0f;

void init (GLFWwindow* window) {

	// Utils
	renderingProgram = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");

	// Cria um ID na GPU para um array de  buffers
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	//-----------------
							GLfloat x = 0;
							GLfloat y = 0;
							GLfloat z = 0;
							GLfloat radius = 0.15;
							GLint numberOfSides = 50; // 50
							n_Vertices = numberOfSides+2; // points + one center point.
							GLfloat twicePi = 2.0f * M_PI;

							GLfloat verticesX[n_Vertices*14];
							GLfloat verticesY[n_Vertices*14];
							GLfloat verticesZ[n_Vertices*14];

							verticesX[0] = x;
							verticesY[0] = y;
							verticesZ[0] = z;

							GLfloat colorsX[n_Vertices*14];
							GLfloat colorsY[n_Vertices*14];
							GLfloat colorsZ[n_Vertices*14];

							colorsX[0] = 0;
							colorsY[0] = 0;
							colorsZ[0] = 0;


							for (int i = 1; i < n_Vertices; i++) {
								verticesX[i] = x + (radius * cos(i * twicePi / numberOfSides));
								verticesY[i] = y + (radius * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
								//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}
							dimVertices = (n_Vertices*14) * 3 *2;
							GLfloat m_Vertices[dimVertices];

							for (int i = 0; i < n_Vertices; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}

							glGenBuffers(1, &m_VBO);
							glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
							glBufferData(
									GL_ARRAY_BUFFER,
									dimVertices * sizeof(GLfloat),
									m_Vertices,
									GL_STATIC_DRAW
								);

							// 1rst attribute buffer : vertices
							glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
							glVertexAttribPointer(
								0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
								3,                  // size
								GL_FLOAT,           // type
								GL_FALSE,           // normalized?
								0,                  // stride
								(void*) 0            // array buffer offset
							);
							GLfloat x1 = 0.75;
							GLfloat y1 = 0.55;
							GLfloat z1 = 0;
							GLfloat radius1 = 0.2;

							verticesX[52] = x1;
							verticesY[52] = y1;
							verticesZ[52] = z1;

							colorsX[52] = 0;
							colorsY[52] = 0;
							colorsZ[52] = 0;

							for (int i = 53; i < n_Vertices*2; i++) {
								verticesX[i] = x1 + (radius1 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y1 + (radius1 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z1;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 52; i < n_Vertices*2; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
									//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}


							//-----------------


							//-----------------
							GLfloat x2 = -0.75;
							GLfloat y2 = 0.55;
							GLfloat z2 = 0;
							GLfloat radius2 = 0.2;

							verticesX[104] = x2;
							verticesY[104] = y2;
							verticesZ[104] = z2;

							colorsX[104] = 0;
							colorsY[104] = 0;
							colorsZ[104] = 0;

							for (int i = 105; i < n_Vertices*3; i++) {
								verticesX[i] = x2 + (radius2 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y2 + (radius2 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z2;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
								//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 104; i < n_Vertices*3; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}


							//-----------------

							//-----------------
							GLfloat x3 = 0;
							GLfloat y3 = -0.95;
							GLfloat z3 = 0;
							GLfloat radius3 = 0.2;

							verticesX[156] = x3;
							verticesY[156] = y3;
							verticesZ[156] = z3;

							colorsX[156] = 0;
							colorsY[156] = 0;
							colorsZ[156] = 0;

							for (int i = 157; i < n_Vertices*4; i++) {
								verticesX[i] = x3 + (radius3 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y3 + (radius3 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z3;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 156; i < n_Vertices*4; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
									//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}
							//-----------------

							GLfloat x4 = 0;
							GLfloat y4 = 0;
							GLfloat z4 = 0;
							GLfloat radius4 = 1.5;

							verticesX[208] = x4;
							verticesY[208] = y4;
							verticesZ[208] = z4;

							colorsX[208] = 0;
							colorsY[208] = 0;
							colorsZ[208] = 0;

							for (int i = 209; i < n_Vertices*5; i++) {
								verticesX[i] = x4 + (radius4 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y4 + (radius4 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z4;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 208; i < n_Vertices*5; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
									//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}


							//-----------------
							GLfloat x5 = 0;
							GLfloat y5 = 0;
							GLfloat z5 = 0;
							GLfloat radius5 = 1.4;

							verticesX[260] = x5;
							verticesY[260] = y5;
							verticesZ[260] = z5;

							colorsX[260] = 0.68;
							colorsY[260] = 0.17;
							colorsZ[260] = 0.17;

							for (int i = 261; i < n_Vertices*6; i++) {
								verticesX[i] = x5 + (radius5 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y5 + (radius5 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z5;
								colorsX[i] = 0.68;
								colorsY[i] = 0.17;
								colorsZ[i] = 0.17;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 260; i < n_Vertices*6; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
									//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}


							//-----------------
							GLfloat x6 = 0;
							GLfloat y6 = 0;
							GLfloat z6 = 0;
							GLfloat radius6 = 1.02;

							verticesX[312] = x6;
							verticesY[312] = y6;
							verticesZ[312] = z6;

							colorsX[312] = 0.61;
							colorsY[312] = 0.12;
							colorsZ[312] = 0.12;

							for (int i = 313; i < n_Vertices*7; i++) {
								verticesX[i] = x6 + (radius6 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y6 + (radius6 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z6;
								colorsX[i] = 0.61;
								colorsY[i] = 0.12;
								colorsZ[i] = 0.12;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 312; i < n_Vertices*7; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
									//cout<<" P["<<i<<"]"<<": ("<<m_Vertices2[i * 3]<<","<<m_Vertices2[i * 3+1]<<","<<m_Vertices2[i * 3+2]<<") \n";
							}


							//-----------------
							GLfloat x7 = 0;
							GLfloat y7 = 0;
							GLfloat z7 = 0;
							GLfloat radius7 = 0.9;

							verticesX[364] = x7;
							verticesY[364] = y7;
							verticesZ[364] = z7;

							colorsX[364] = 0.68;
							colorsY[364] = 0.17;
							colorsZ[364] = 0.17;

							for (int i = 365; i < n_Vertices*8; i++) {
								verticesX[i] = x7 + (radius7 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y7 + (radius7 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z7;
								colorsX[i] = 0.68;
								colorsY[i] = 0.17;
								colorsZ[i] = 0.17;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 364; i < n_Vertices*8; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}

//-------
							GLfloat x8 = 0.79;
							GLfloat y8 = 0.61;
							GLfloat z8 = 0;
							GLfloat radius8 = 0.25;

							verticesX[416] = x8;
							verticesY[416] = y8;
							verticesZ[416] = z8;

							colorsX[416] = 0;
							colorsY[416] = 0;
							colorsZ[416] = 0;

							for (int i = 417; i < n_Vertices*9; i++) {
								verticesX[i] = x8 + (radius8 * cos(i * twicePi / numberOfSides/2));
								verticesY[i] = y8 + (radius8 * sin(i * twicePi / numberOfSides/2));
								verticesZ[i] = z8;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 416; i < n_Vertices*9; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}


							//-----------------
							//-------
							GLfloat x9 = 0.85;
							GLfloat y9 = 0.794;
							GLfloat z9 = 0;
							GLfloat radius9 = 0.067;

							verticesX[468] = x9;
							verticesY[468] = y9;
							verticesZ[468] = z9;

							colorsX[468] = 0.68;
							colorsY[468] = 0.17;
							colorsZ[468] = 0.17;

							for (int i = 469; i < n_Vertices*10; i++) {
								verticesX[i] = x9 + (radius9 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y9 + (radius9 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z9;
								colorsX[i] = 0.68;
								colorsY[i] = 0.17;
								colorsZ[i] = 0.17;
								//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 468; i < n_Vertices*10; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}


				//---------------------------------------
							GLfloat x10 = -0.8;
							GLfloat y10 = 0.60;
							GLfloat z10 = 0;
							GLfloat radius10 = 0.25;

							verticesX[520] = x10;
							verticesY[520] = y10;
							verticesZ[520] = z10;

							colorsX[520] = 0;
							colorsY[520] = 0;
							colorsZ[520] = 0;

							for (int i = 521; i < n_Vertices*11; i++) {
								verticesX[i] = x10 + (radius10 * cos(190 + i * twicePi / numberOfSides/2));
								verticesY[i] = y10 + (radius10 * sin(190 + i * twicePi / numberOfSides/2));
								verticesZ[i] = z10;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 520; i < n_Vertices*11; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}


							//-----------------
							//-------
							GLfloat x11 = -1;
							GLfloat y11 = 0.65;
							GLfloat z11 = 0;
							GLfloat radius11 = 0.067;

							verticesX[572] = x11;
							verticesY[572] = y11;
							verticesZ[572] = z11;

							colorsX[572] = 0.68;
							colorsY[572] = 0.17;
							colorsZ[572] = 0.17;

							for (int i = 573; i < n_Vertices*12; i++) {
								verticesX[i] = x11 + (radius11 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y11 + (radius11 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z11;
								colorsX[i] = 0.68;
								colorsY[i] = 0.17;
								colorsZ[i] = 0.17;
								//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 572; i < n_Vertices*12; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}


				//---------------------------------------
							GLfloat x12 = 0.03;
							GLfloat y12 = -1.02;
							GLfloat z12 = 0;
							GLfloat radius12 = 0.25;

							verticesX[624] = x12;
							verticesY[624] = y12;
							verticesZ[624] = z12;

							colorsX[624] = 0;
							colorsY[624] = 0;
							colorsZ[624] = 0;

							for (int i = 625; i < n_Vertices*13; i++) {
								verticesX[i] = x12 + (radius12 * cos(179 +i * twicePi / numberOfSides/2));
								verticesY[i] = y12 + (radius12 * sin(179 +i * twicePi / numberOfSides/2));
								verticesZ[i] = z12;
								colorsX[i] = 0;
								colorsY[i] = 0;
								colorsZ[i] = 0;
									//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 624; i < n_Vertices*13; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}


							//-----------------
							//-------
							GLfloat x13 = 0.05;
							GLfloat y13 = -1.21;
							GLfloat z13 = 0;
							GLfloat radius13 = 0.067;

							verticesX[676] = x13;
							verticesY[676] = y13;
							verticesZ[676] = z13;

							colorsX[676] = 0.68;
							colorsY[676] =0.17;
							colorsZ[676] =0.17;

							for (int i = 677; i < n_Vertices*14; i++) {
								verticesX[i] = x13 + (radius13 * cos(i * twicePi / numberOfSides));
								verticesY[i] = y13 + (radius13 * sin(i * twicePi / numberOfSides));
								verticesZ[i] = z13;
								colorsX[i] = 0.68;
								colorsY[i] = 0.17;
								colorsZ[i] = 0.17;
								//cout<<" P["<<i<<"]"<<": ("<<verticesX[i]<<","<<verticesY[i]<<","<<verticesZ[i]<<") \n";
							}

							for (int i = 676; i < n_Vertices*14; i++) {
								m_Vertices[i * 6] = verticesX[i];
								m_Vertices[i * 6 + 1] = verticesY[i];
								m_Vertices[i * 6 + 2] = verticesZ[i];
								m_Vertices[i * 6 + 3] =colorsX[i];
								m_Vertices[i * 6 + 4] =colorsY[i];
								m_Vertices[i * 6 + 5] =colorsZ[i];
								//cout<<" P["<<i<<"]"<<": ("<<m_Vertices[i * 6]<<","<<m_Vertices[i * 6+1]<<","<<m_Vertices[i * 6+2]<<m_Vertices[i * 6+3]<<m_Vertices[i * 6+4]<<m_Vertices[i * 6+5]<<") \n";
							}


				//---------------------------------------



	// Cria um ID na GPU para nosso buffer
	glGenBuffers(1, &m_VBO);

	// Cria um ID na GPU para um array de  buffers
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	// Reserva memoria na GPU para um TARGET receber dados
	// Copia esses dados pra essa área de memoria
	glBufferData(
			GL_ARRAY_BUFFER,	// TARGET associado ao nosso buffer
			dimVertices * sizeof(GLfloat),	// tamanho do buffer
			m_Vertices,			// Dados a serem copiados pra GPU
			GL_STATIC_DRAW		// Política de acesso aos dados, para otimização
		);

	glVertexAttribPointer(
			0,			// Lembra do (layout = 0 ) no vertex shader ? Esse valor indica qual atributo estamos indicando
			3,			// cada vertice é composto de 3 valores
			GL_FLOAT,	// cada valor do vértice é do tipo GLfloat
			GL_FALSE,	// Quer normalizar os dados e converter tudo pra NDC ? ( no nosso caso, já esta tudo correto, então deixamos como FALSE)
			6 * sizeof(GLfloat),// De quantos em quantos bytes, este atributo é encontrado no buffer ? No nosso caso 3 floats pros vertices + 3 floats pra cor = 6 floats
			(GLvoid*) 0	// Onde está o primeiro valor deste atributo no buffer. Nesse caso, está no início do buffer
		);

	glVertexAttribPointer(
					1,			// Lembra do (layout = 1 ) no vertex shader ? Esse valor indica qual atributo estamos indicando
					3,			// cada vertice é composto de 3 valores
					GL_FLOAT,	// cada valor do vértice é do tipo GLfloat
					GL_FALSE,	// Quer normalizar os dados e converter tudo pra NDC ? ( no nosso caso, já esta tudo correto, então deixamos como FALSE)
					6 * sizeof(GLfloat),// De quantos em quantos bytes, este atributo é encontrado no buffer ? No nosso caso 3 floats pros vertices + 3 floats pra cor = 6 floats
					(GLvoid*) (3 * sizeof(GLfloat))	// Onde está o primeiro valor deste atributo no buffer. Nesse caso, 3 floats após o início do buffer
	);

	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(0);	// Habilita este atributo



	glBindVertexArray(0);
}

void display(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);

	GLuint uniformModel = glGetUniformLocation(renderingProgram, "model");

	curAngle += 0.5f;
	if (curAngle >= 360)
	{
		curAngle -= 360;
	}

	// Matriz con elementos de valor 1
	glm::mat4 model(1.0f);
	//Giro Antihorario
	model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));

	//Usando UniformMatrix
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	//Usando ProgramUniform
	//glProgramUniformMatrix4fv(renderingProgram, uniformModel, 1, GL_FALSE, glm::value_ptr(model));

	// Use este VAO e suas configurações
	glBindVertexArray(m_VAO);
	//glPointSize(20.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 208,n_Vertices);
	glDrawArrays(GL_TRIANGLE_FAN, 260,n_Vertices);
	glDrawArrays(GL_TRIANGLE_FAN, 312,n_Vertices);
	glDrawArrays(GL_TRIANGLE_FAN, 364,n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0,n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 52, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 104, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 156, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 416, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 468, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 520, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 572, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 624, n_Vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 676, n_Vertices);

	glBindVertexArray(0);
	glUseProgram(0);
}

int main(void) {
    if (!glfwInit()) {
    	exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            //
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); 	// Resizable option.

    GLFWwindow* window = glfwCreateWindow(800, 800, "Asis Romero, Sebastian Alexander", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
    	exit(EXIT_FAILURE);
    }
    glfwSwapInterval(1);

    init(window);

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
