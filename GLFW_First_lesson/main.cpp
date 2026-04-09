#include <iostream>
#include <GL/glew.h> // GLEW перед GLFW обязательно
#include <GLFW/glfw3.h>
#include <string>


int main() {
	// Инициализация GLFW
	glfwInit();
	// Настройка GLFW
	// Задается минимальная требуемая версия OpenGL. 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Установка профайла для которого создается контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	const char* aTitlebar = "FirstLesson FPS: ";

	// Создание GLFW окна
	GLFWwindow* window = glfwCreateWindow(800, 600, aTitlebar, 0, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to open GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Init GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to init GLEW" << std::endl;
		return -2;
	}

	// Viewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// Переменные для сохранения времени кадра
	double deltaTime = 0.0f;
	double lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		// Счетчик кадров
		double currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		int fps = 1 / deltaTime;

		std::string aTitlebar_new = aTitlebar + std::to_string(fps);

		glfwSetWindowTitle(window, aTitlebar_new.c_str() );
	}

	glfwTerminate();
	return 0;
}