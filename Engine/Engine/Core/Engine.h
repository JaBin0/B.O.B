#ifndef __ENGINE__
#define __ENGINE__
// Own headers
#include <ResourceMgr.h>

class Engine {
public: 
    Engine()=delete;
    Engine(int width, int height);
    ~Engine();
    
    void printSize();

    ResourceMgr& getResourceMgr();

private:
    // Manager which allow to load all resource related stuff
    ResourceMgr m_resourceMgr;

    int m_width;
    int m_height;
};

#endif //__ENGINE__