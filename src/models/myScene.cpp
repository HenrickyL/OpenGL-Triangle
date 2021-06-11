#include "../headers/myScene.hpp"
#include<iostream>
#include<GL/glew.h>
#include<sstream>
#include "../headers/util.hpp"


GLint checkShaderCompilation(GLuint shader){
    GLint sucess=0;
    GLchar infoLog[512];
    glGetShaderiv(shader,GL_COMPILE_STATUS, &sucess);

    if(!sucess){
         glGetShaderInfoLog(shader, sizeof(infoLog),NULL,infoLog);
        std::cerr<< infoLog<<std::endl;
    }
    return sucess;
}

GLint checkProgramLink(GLuint program){
    GLint sucess=0;
    GLchar infoLog[512];
    glGetShaderiv(program,GL_LINK_STATUS, &sucess);

    if(!sucess){
         glGetProgramInfoLog(program, sizeof(infoLog),NULL,infoLog);
        std::cerr<< infoLog<<std::endl;
    }
    return sucess;
}


MyScene::MyScene(){
    std::stringstream vertexSourceStream;
    std::stringstream fragmentSourceStream;

    loadFile("src/files/vertex.vs",vertexSourceStream);
    loadFile("src/files/fragment.fs",fragmentSourceStream);

    std::string vertexSource = vertexSourceStream.str();
    std::string fragmentSource = fragmentSourceStream.str();

    const char* buff;

    //criar shader 
    m_ShaderProgram = glCreateProgram();
    
    //vertex shader
    buff = vertexSource.c_str();
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_VertexShader,1,&buff,NULL);
    //compilar shader
    glCompileShader(m_VertexShader);
    checkShaderCompilation(m_VertexShader);
    glAttachShader(m_ShaderProgram,m_VertexShader);
    glDeleteShader(m_VertexShader);

    //fragment Shader
    buff = fragmentSource.c_str();
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_FragmentShader,1,&buff,NULL);
    //compilar shader
    glCompileShader(m_FragmentShader);
    checkShaderCompilation(m_FragmentShader);
    glAttachShader(m_ShaderProgram,m_FragmentShader);
    glDeleteShader(m_FragmentShader);


    //linking
    glLinkProgram(m_ShaderProgram);
    checkProgramLink(m_ShaderProgram);


    // //pronto para ser usado
    // glUseProgram(m_ShaderProgram);

    m_Vertices = new GLfloat[18]{
        -0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f,
        0.5f,-0.5f,0.0f,0.0f,1.0f,0.0f,
        0.0f,0.5f,0.0f,0.0f,0.0f,1.0f
    };

    


    //vertexBufferObject
    glGenBuffers(1, &m_VBO);

    //vertex Array Object
      //Criar um ID na GPUpara um array de buffers
      glGenVertexArrays(1,&m_VAO);
      glBindVertexArray(m_VAO);

      glBindBuffer(GL_ARRAY_BUFFER,m_VBO);


    glBufferData(GL_ARRAY_BUFFER, 
        18*sizeof(GL_FLOAT),
        m_Vertices,
        GL_STATIC_DRAW
    );
    //vertices
    glVertexAttribPointer(0,
        3,GL_FLOAT,
        GL_FALSE,
        6*sizeof(GLfloat),
        (GLvoid*)0
     );
     //Cores
    glVertexAttribPointer(1,
        3,GL_FLOAT,
        GL_FALSE,
        6*sizeof(GLfloat),
        (GLvoid*)(3*sizeof(GLfloat))
     );

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);


    // glClearColor(0.5f,0.5f,1.0f,0);
}   
MyScene::~MyScene(){
    glDeleteProgram(m_ShaderProgram);
}
void MyScene::update(){
//afeta o resltado final
    //limpar o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //pronto para ser usado
    glUseProgram(m_ShaderProgram);
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
    glBindVertexArray(0);


    


}