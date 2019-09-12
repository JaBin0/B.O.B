// System headers
#include <iostream>
// Own headers
#include <Engine.h>

Engine::Engine(int width, int height) 
    : m_resourceMgr {}
    , m_width(width)
    , m_height(height)
{
}
Engine::~Engine() {
    std::cout << "Destructing Engine object" << std::endl;
}

ResourceMgr& Engine::getResourceMgr() {
    return m_resourceMgr;
}
    
void Engine::printSize() {
    std::cout << "Size of the engine: <" << m_width << "x" << m_height << ">" <<std::endl;
}

