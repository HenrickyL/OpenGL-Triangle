#include<iostream>
#include <memory>
#include "./headers/window.hpp"
#include "./headers/myScene.hpp"
using namespace std;


int main(){
    Window w(800,600,"Intro OpenGL -hck");
    w.setScene(std::unique_ptr<Scene>(new MyScene()));
    while(!w.shouldClose()){
        w.update();
    }
    return 0;
}