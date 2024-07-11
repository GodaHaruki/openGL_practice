#include <iostream>
#include <GLFW/glfw3.h>

int main(){
    if(!glfwInit()){
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(1024, 768, "practice", NULL, NULL);

    if(window == NULL){
        std::cerr << "window creation failed" << std::endl;
    }

    glfwMakeContextCurrent(window);

    do{
        std::cout << "render" << std::endl;
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == GLFW_FALSE);
}