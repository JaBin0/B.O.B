// System headers
#include <iostream>
// Own headers
#include <Engine.h>

Engine::Engine(int width, int height) 
    : m_width(width)
    , m_height(height)
{
}
Engine::~Engine() {
    std::cout << "Destructing Engine object" << std::endl;
}
    
void Engine::printSize() {
    std::cout << "Size of the engine: <" << m_width << "x" << m_height << ">" <<std::endl;
}

