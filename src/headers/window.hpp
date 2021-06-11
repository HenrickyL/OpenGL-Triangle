#pragma once

#ifndef WINDOW_H
#define WINDOW_H
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<memory>//unique
class Scene;

class Window{
public:
    Window(int width=800, int height=600, const char* title="OpenGL");
    ~Window();
    void update();
    bool shouldClose();
    void setScene(std::unique_ptr<Scene> scene);
private:
    GLFWwindow* m_Window;
    std::unique_ptr<Scene> m_Scene = nullptr;
    bool m_ShouldClose;
    static void  errorCallback(int error, const char* description);
    void verifyScenePtr();
    void verifyWindowClose();


};

#endif