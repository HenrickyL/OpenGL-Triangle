#pragma once
#ifndef SCENE_H
#define SCENE_H
#include<GL/glew.h>

//virtual - interface
class Scene{
public:
    virtual ~Scene(){} 
    virtual void update()=0;
};


#endif