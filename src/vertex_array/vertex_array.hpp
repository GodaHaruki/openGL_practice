#pragma once 

// vertexシェーダーにモデル変換行列を渡して座標を変更するからVboは変更する必要ないらしい

class vertex_array {
    public:
    vertex_array(const float *vertices, unsigned int num_vertices);
    ~vertex_array();
    void activate();

    private:
    const unsigned int _num_vertices;
    GLuint _vertex_array;
    GLuint _vertex_buffer;
};