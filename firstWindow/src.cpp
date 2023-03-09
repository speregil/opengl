#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/*
* Implementation of a simple window using OpenGL and GLFW
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    // Initializes the OpenGL context
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  //Min and max version of OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //Basic OpenGL profile

    //Creates the new window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Window Title", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //Initializes GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600); //Creates the viewport

    //Registers all the callback functions
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //Render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

/*
* Callback function for handling a windows rezise
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}