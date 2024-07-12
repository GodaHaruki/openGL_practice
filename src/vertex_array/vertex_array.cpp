#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vertex_array.hpp"

vertex_array::vertex_array(const float *vertices, unsigned int num_vertices)
: _num_vertices(num_vertices){
    glGenVertexArrays(1, &_vertex_array);
    glBindVertexArray(_vertex_array);

    glGenBuffers(1, &_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, _num_vertices * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );
}

vertex_array::~vertex_array(){}

void vertex_array::activate(){
    glBindVertexArray(_vertex_array);
}
