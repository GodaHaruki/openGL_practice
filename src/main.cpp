#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vertex_array/vertex_array.hpp"
#include "shader/shader.hpp"

int main(){
    if(!glfwInit()){
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1024, 768, "practice", NULL, NULL);

    if(window == NULL){
        std::cerr << "window creation failed" << std::endl;
    }

    glfwMakeContextCurrent(window);

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    static const GLfloat g_vertex_buffer_data2[] = {
        1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
    };

    
    // gladLoadGL();
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    vertex_array vbo1(g_vertex_buffer_data, 3);
    vertex_array vbo2(g_vertex_buffer_data2, 3);

    shader renderer(SIMPLE_VERTEX_SHADER_PATH, SIMPLE_FRAGMENT_SHADER_PATH);
    renderer.activate();

    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        vbo1.activate();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        vbo2.activate();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == GLFW_FALSE);
}