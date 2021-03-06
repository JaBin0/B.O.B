#ifndef __ENGINE__
#define __ENGINE__
// Own headers
#include <ResourceMgr.h>
#include <EngineBasicTypes.h>
// Forward declaration
class GLFWwindow;

class Engine {
public: 
    Engine()=delete;
    Engine(int width, int height);
    ~Engine();
    
    // Initialize engine
    void init();

    // Start main rutine of the engine,
    ErrorCode startEngineRutine();

    void printSize();

    ResourceMgr& getResourceMgr();

private:
    // Manager which allow to load all resource related stuff
    ResourceMgr m_resourceMgr;

    // Main window handler
    GLFWwindow* m_window;

    int m_width;
    int m_height;
};

#endif //__ENGINE__