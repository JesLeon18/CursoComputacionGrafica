#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Perez Leon Jesus Omar - Modelado geometrico", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {
		-0.5f, -0.5f, 0.5f, 0.831f, 0.729f,0.671f,//Cubo Carne		0, 36
		0.5f, -0.5f, 0.5f,  0.831f, 0.729f,0.671f,
		0.5f,  0.5f, 0.5f,  0.831f, 0.729f,0.671f,
		0.5f,  0.5f, 0.5f,  0.831f, 0.729f,0.671f,
		-0.5f,  0.5f, 0.5f, 0.831f, 0.729f,0.671f,
		-0.5f, -0.5f, 0.5f, 0.831f, 0.729f,0.671f,
		
	    -0.5f, -0.5f,-0.5f, 0.831f, 0.729f,0.671f,
		 0.5f, -0.5f,-0.5f, 0.831f, 0.729f,0.671f,
		 0.5f,  0.5f,-0.5f, 0.831f, 0.729f,0.671f,
		 0.5f,  0.5f,-0.5f, 0.831f, 0.729f,0.671f,
	    -0.5f,  0.5f,-0.5f, 0.831f, 0.729f,0.671f,
	    -0.5f, -0.5f,-0.5f, 0.831f, 0.729f,0.671f,
		
		 0.5f, -0.5f,  0.5f, 0.861f, 0.71f,0.671f, //Lateral izquierdo
		 0.5f, -0.5f, -0.5f, 0.861f, 0.71f,0.671f,
		 0.5f,  0.5f, -0.5f, 0.861f, 0.71f,0.671f,
		 0.5f,  0.5f, -0.5f, 0.861f, 0.71f,0.671f,
		 0.5f,  0.5f,  0.5f, 0.861f, 0.71f,0.671f,
		 0.5f,  -0.5f, 0.5f, 0.861f, 0.71f,0.671f,
      
		-0.5f,  0.5f,  0.5f,  0.801f, 0.74f,0.671f, //Lateral derecho
		-0.5f,  0.5f, -0.5f,  0.801f, 0.74f,0.671f,
		-0.5f, -0.5f, -0.5f,  0.801f, 0.74f,0.671f,
		-0.5f, -0.5f, -0.5f,  0.801f, 0.74f,0.671f,
		-0.5f, -0.5f,  0.5f,  0.801f, 0.74f,0.671f,
		-0.5f,  0.5f,  0.5f, 0.801f, 0.74f,0.671f,
		
		-0.5f, -0.5f, -0.5f, 0.831f, 0.729f,0.671f,
		0.5f, -0.5f, -0.5f,  0.831f, 0.729f,0.671f,
		0.5f, -0.5f,  0.5f,  0.831f, 0.729f,0.671f,
		0.5f, -0.5f,  0.5f,  0.831f, 0.729f,0.671f,
		-0.5f, -0.5f,  0.5f, 0.831f, 0.729f,0.671f,
		-0.5f, -0.5f, -0.5f, 0.831f, 0.729f,0.671f,
		
		-0.5f,  0.5f, -0.5f, 0.831f, 0.729f,0.671f,
		0.5f,  0.5f, -0.5f,  0.831f, 0.729f,0.671f,
		0.5f,  0.5f,  0.5f,  0.831f, 0.729f,0.671f,
		0.5f,  0.5f,  0.5f,  0.831f, 0.729f,0.671f,
		-0.5f,  0.5f,  0.5f, 0.831f, 0.729f,0.671f,
		-0.5f,  0.5f, -0.5f, 0.831f, 0.729f,0.671f,

		-0.5f, -0.5f, 0.5f, 0.78f, 0.729f,0.698f,//Cubo cafe		36, 72
		0.5f, -0.5f, 0.5f,  0.78f, 0.729f,0.698f,
		0.5f,  0.5f, 0.5f,  0.78f, 0.729f,0.698f,
		0.5f,  0.5f, 0.5f,  0.78f, 0.729f,0.698f,
		-0.5f,  0.5f, 0.5f, 0.78f, 0.729f,0.698f,
		-0.5f, -0.5f, 0.5f, 0.78f, 0.729f,0.698f,

		-0.5f, -0.5f,-0.5f, 0.702f, 0.655f,0.624f,
		 0.5f, -0.5f,-0.5f, 0.702f, 0.655f,0.624f,
		 0.5f,  0.5f,-0.5f, 0.702f, 0.655f,0.624f,
		 0.5f,  0.5f,-0.5f, 0.702f, 0.655f,0.624f,
		-0.5f,  0.5f,-0.5f, 0.702f, 0.655f,0.624f,
		-0.5f, -0.5f,-0.5f, 0.702f, 0.655f,0.624f,

		 0.5f, -0.5f,  0.5f, 0.612f, 0.549f,0.514f,
		 0.5f, -0.5f, -0.5f, 0.612f, 0.549f,0.514f,
		 0.5f,  0.5f, -0.5f, 0.612f, 0.549f,0.514f,
		 0.5f,  0.5f, -0.5f, 0.612f, 0.549f,0.514f,
		 0.5f,  0.5f,  0.5f, 0.612f, 0.549f,0.514f,
		 0.5f,  -0.5f, 0.5f, 0.612f, 0.549f,0.514f,

		-0.5f,  0.5f,  0.5f,  0.81f, 0.759f,0.74f,
		-0.5f,  0.5f, -0.5f,  0.81f, 0.759f,0.74f,
		-0.5f, -0.5f, -0.5f,  0.81f, 0.759f,0.74f,
		-0.5f, -0.5f, -0.5f,  0.81f, 0.759f,0.74f,
		-0.5f, -0.5f,  0.5f,  0.81f, 0.759f,0.74f,
		-0.5f,  0.5f,  0.5f,  0.81f, 0.759f,0.74f,

		-0.5f, -0.5f, -0.5f, 0.612f, 0.549f,0.514f,
		0.5f, -0.5f, -0.5f,  0.612f, 0.549f,0.514f,
		0.5f, -0.5f,  0.5f,  0.612f, 0.549f,0.514f,
		0.5f, -0.5f,  0.5f,  0.612f, 0.549f,0.514f,
		-0.5f, -0.5f,  0.5f, 0.612f, 0.549f,0.514f,
		-0.5f, -0.5f, -0.5f, 0.612f, 0.549f,0.514f,

		-0.5f,  0.5f, -0.5f, 0.612f, 0.549f,0.514f,
		0.5f,  0.5f, -0.5f,  0.612f, 0.549f,0.514f,
		0.5f,  0.5f,  0.5f,  0.612f, 0.549f,0.514f,
		0.5f,  0.5f,  0.5f,  0.612f, 0.549f,0.514f,
		-0.5f,  0.5f,  0.5f, 0.612f, 0.549f,0.514f,
		-0.5f,  0.5f, -0.5f, 0.612f, 0.549f,0.514f,

		-0.5f, -0.5f, 0.5f, 0.7f, 0.424f,0.369f,//Cubo rojito		72, 108
		0.5f, -0.5f, 0.5f,  0.7f, 0.424f,0.369f,
		0.5f,  0.5f, 0.5f,  0.7f, 0.424f,0.369f,
		0.5f,  0.5f, 0.5f,  0.7f, 0.424f,0.369f,
		-0.5f,  0.5f, 0.5f, 0.7f, 0.424f,0.369f,
		-0.5f, -0.5f, 0.5f, 0.7f, 0.424f,0.369f,

		-0.5f, -0.5f,-0.5f, 0.7f, 0.424f,0.369f,
		 0.5f, -0.5f,-0.5f, 0.7f, 0.424f,0.369f,
		 0.5f,  0.5f,-0.5f, 0.7f, 0.424f,0.369f,
		 0.5f,  0.5f,-0.5f, 0.7f, 0.424f,0.369f,
		-0.5f,  0.5f,-0.5f, 0.7f, 0.424f,0.369f,
		-0.5f, -0.5f,-0.5f, 0.7f, 0.424f,0.369f,

		 0.5f, -0.5f,  0.5f, 0.729f, 0.369f,0.298f,
		 0.5f, -0.5f, -0.5f, 0.729f, 0.369f,0.298f,
		 0.5f,  0.5f, -0.5f, 0.729f, 0.369f, 0.298f,
		 0.5f,  0.5f, -0.5f, 0.729f, 0.369f, 0.298f,
		 0.5f,  0.5f,  0.5f, 0.729f, 0.369f, 0.298f,
		 0.5f,  -0.5f, 0.5f, 0.729f, 0.369f, 0.298f,

		-0.5f,  0.5f,  0.5f, 0.871f, 0.678f, 0.639f,
		-0.5f,  0.5f, -0.5f, 0.871f, 0.678f, 0.639f,
		-0.5f, -0.5f, -0.5f, 0.871f, 0.678f, 0.639f,
		-0.5f, -0.5f, -0.5f, 0.871f, 0.678f, 0.639f,
		-0.5f, -0.5f,  0.5f, 0.871f, 0.678f, 0.639f,
		-0.5f,  0.5f,  0.5f, 0.871f, 0.678f, 0.639f,

		-0.5f, -0.5f, -0.5f, 0.7f, 0.424f, 0.369f,
		0.5f, -0.5f, -0.5f,  0.7f, 0.424f, 0.369f,
		0.5f, -0.5f,  0.5f,  0.7f, 0.424f, 0.369f,
		0.5f, -0.5f,  0.5f,  0.7f, 0.424f, 0.369f,
		-0.5f, -0.5f,  0.5f, 0.7f, 0.424f, 0.369f,
		-0.5f, -0.5f, -0.5f, 0.7f, 0.424f, 0.369f,

		-0.5f,  0.5f, -0.5f, 0.7f, 0.424f, 0.369f,
		0.5f,  0.5f, -0.5f,  0.7f, 0.424f, 0.369f,
		0.5f,  0.5f,  0.5f,  0.7f, 0.424f, 0.369f,
		0.5f,  0.5f,  0.5f,  0.7f, 0.424f, 0.369f,
		-0.5f,  0.5f,  0.5f, 0.7f, 0.424f, 0.369f,
		-0.5f,  0.5f, -0.5f, 0.7f, 0.424f, 0.369f,



		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 0.0f,//Cubo negro	108, 144
		0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,		0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,

		0.5f, -0.5f, 0.5f,		0.2f, 0.2f, 0.2f,
		0.5f, -0.5f, -0.5f, 0.2f, 0.2f, 0.2f,
		0.5f, 0.5f, -0.5f, 0.2f, 0.2f, 0.2f,
		0.5f, 0.5f, -0.5f, 0.2f, 0.2f, 0.2f, 
		0.5f, 0.5f, 0.5f, 0.2f, 0.2f, 0.2f,
		0.5f, -0.5f, 0.5f, 0.2f, 0.2f, 0.2f,

		-0.5f, 0.5f, 0.5f,		0.2f, 0.2f, 0.2f,
		-0.5f, 0.5f, -0.5f, 0.2f, 0.2f, 0.2f,
		-0.5f, -0.5f, -0.5f, 0.2f, 0.2f, 0.2f,
		-0.5f, -0.5f, -0.5f, 0.2f, 0.2f, 0.2f,
		-0.5f, -0.5f, 0.5f, 0.2f, 0.2f, 0.2f,
		-0.5f, 0.5f, 0.5f, 0.2f, 0.2f, 0.2f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,//Cubo gris	144, 180
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,

		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,

		0.5f, -0.5f, 0.5f, 0.4f, 0.4f, 0.4f,
		0.5f, -0.5f, -0.5f, 0.4f, 0.4f, 0.4f,
		0.5f, 0.5f, -0.5f, 0.4f, 0.4f, 0.4f,
		0.5f, 0.5f, -0.5f, 0.4f, 0.4f, 0.4f,
		0.5f, 0.5f, 0.5f, 0.4f, 0.4f, 0.4f,
		0.5f, -0.5f, 0.5f, 0.4f, 0.4f, 0.4f,

		-0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,

		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,

		-0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,

		-0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,//Cubo gris fuerte	180, 216
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,

		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,

		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,

		-0.5f, 0.5f, 0.5f, 0.35f, 0.35f, 0.35f,
		-0.5f, 0.5f, -0.5f, 0.35f, 0.35f, 0.35f,
		-0.5f, -0.5f, -0.5f, 0.35f, 0.35f, 0.35f,
		-0.5f, -0.5f, -0.5f, 0.35f, 0.35f, 0.35f,
		-0.5f, -0.5f, 0.5f, 0.35f, 0.35f, 0.35f,
		-0.5f, 0.5f, 0.5f, 0.35f, 0.35f, 0.35f,

		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f,

		-0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, 0.5f, 0.3f, 0.3f, 0.3f,
		-0.5f, 0.5f, -0.5f, 0.3f, 0.3f, 0.3f,
	};




	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.925f, 0.988f, 0.984f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	

		glBindVertexArray(VAO);
		
		//Cabeza
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
		model = glm::translate(model, glm::vec3(0.0f, -0.55f, 1.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Trompa
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		model = glm::translate(model, glm::vec3(0.0f, -1.65f, 1.6f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Trompa2
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.2f));
		model = glm::translate(model, glm::vec3(0.0f, -3.8f, 1.7f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 36, 72);

		//Nariz
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.2f));
		model = glm::translate(model, glm::vec3(0.0f, -2.8f, 1.7f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);

		//Ojito1
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		model = glm::translate(model, glm::vec3(1.6f, -2.8f, 4.2f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//Ojito2
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		model = glm::translate(model, glm::vec3(-1.6f, -2.8f, 4.2f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//Oreja1
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.2f));
		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 6.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//Oreja2
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.2f));
		model = glm::translate(model, glm::vec3(1.0f, 0.0f, 6.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//Cabeza detalles
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.3f, 0.9f));
		model = glm::translate(model, glm::vec3(0.0f, -0.45f, 1.35f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 36, 72);

		//Cuerpo
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.8f));
		model = glm::translate(model, glm::vec3(0.0f, -0.45f, 1.35f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 190);

		//Detalles Cuerpo1
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.05f, 1.05f, 0.4f));
		model = glm::translate(model, glm::vec3(0.0f, -0.40f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);

		//Detalles Cuerpo2
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.05f, 1.05f, 0.4f));
		model = glm::translate(model, glm::vec3(0.0f, -0.40f, 7.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);


		//Pata1		Negro
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(0.8f, -5.2f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//			Gris
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(0.8f, -6.0f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 190);

		//			Rojito
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(0.8f, -7.0f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);

		//Pata2		Negro
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-0.8f, -5.2f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//			Gris
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-0.8f, -6.0f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 190);

		//			Rojito
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-0.8f, -7.0f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);

		//Pata3		Negro
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-0.8f, -5.2f, 7.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//			Gris
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-0.8f, -6.0f, 7.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 190);

		//			Rojito
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-0.8f, -7.0f, 7.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);

		//Pata4		Negro
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(0.8f, -5.2f, 7.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);

		//			Gris
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(0.8f, -6.0f, 7.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 190);

		//			Rojito
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.2f, 0.4f));
		model = glm::translate(model, glm::vec3(0.8f, -7.0f, 7.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);

		//Cola
		model = glm::mat4(1.0f);
		model = glm::rotate(model, 0.52f, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 2.0f));
		model = glm::translate(model, glm::vec3(0.0f, 3.1, 1.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);



		glBindVertexArray(0);
				

		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		 movY += 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		 movY -= 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.2f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.2f;
 }
