#include"../headers/window.hpp"
#include<iostream>
#include "../headers/scene.hpp"


Window::Window(int width, int height, const char* title){
    m_ShouldClose =true;
    //inicializar GLFW (janela)
    if(! glfwInit()){
        std::cout<< "<Erro ao iniciliar GLFW!>\n";
    }
    //Definição dos atributos do contexto OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,2);
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_FALSE);//sem perfil de compatibilidade(sem obsoleto)
    //permitir que o glfw avise erros
    glfwSetErrorCallback(Window::errorCallback);

    //criar janela
    m_Window = glfwCreateWindow(width,height,title, NULL,NULL);
    if(!m_Window){
        std::cerr <<"<Erro ao criar Janela!>\n";
        return;
    }
    
    //tranformar o contexto relacionado a Janela
    glfwMakeContextCurrent(m_Window);

    //Inicializar glew
    GLenum glewInitError = glewInit();
    if(glewInitError != GLEW_OK){
        std::cerr<<"<Erro ao inicializar GLEW:  "<<glewGetErrorString(glewInitError)<<">\n";
        return;
    }

    //mostrar dados do ambiente:
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout<<"{\n\t[Renderizador:"<<renderer<<" ]\n";
    std::cout<<"\t[Versão:"<<version<<" ]\n}\n";

    //cor
    glClearColor(0.5f,0.5f,1,0);
    //janela deve ser fechada?
    m_ShouldClose =false;

}   

Window::~Window(){
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
void Window::update(){
    
    glfwPollEvents();
    glfwSwapBuffers(m_Window); 


    verifyScenePtr();
    verifyWindowClose();


     
}

void  Window::errorCallback(int error, const char* description){
    std::cerr<< "<Erro "<<error<<" : "<<description<<">\n";
}

bool Window::shouldClose(){
    return m_ShouldClose;
}

void Window::setScene(std::unique_ptr<Scene> scene){
    this->m_Scene = std::move(scene);
}

void Window::verifyScenePtr(){
    if(m_Scene){
        m_Scene->update();
    }
}
void Window::verifyWindowClose(){
    if(!m_ShouldClose)
        m_ShouldClose = glfwWindowShouldClose(m_Window)==GL_TRUE;
}