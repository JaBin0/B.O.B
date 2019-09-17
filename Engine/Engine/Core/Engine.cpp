// System headers
#include <iostream>
#include <GLFW/glfw3.h>
// Own headers
#include <Engine.h>

Engine::Engine(int width, int height) 
    : m_resourceMgr {}
    , m_width(width)
    , m_height(height)
{
    init();
}

void Engine::init() {
    // Set up glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    m_window = glfwCreateWindow(m_width, m_height, "Test", NULL, NULL);
    if(!m_window) {
        std::cout << "Window was not created \n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);
    m_window->setTitle("Test 2");
}

ErrorCode Engine::startEngineRutine() {
    while(!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
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

