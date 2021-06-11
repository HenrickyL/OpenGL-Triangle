#pragma once

#ifndef MYSCENE_H
#define MYSCENE_H

#include"scene.hpp"

class MyScene:public Scene{
private:
    GLuint m_ShaderProgram;
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLfloat* m_Vertices;
    GLuint m_VBO;
    GLuint m_VAO;
    int _tick=0;
    


public:
    MyScene();
    ~MyScene();
    void update() override;
};

#endif
