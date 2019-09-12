#ifndef __RESOURCE_MANAGER__
#define __RESOURCE_MANAGER__
// System headers
#include <string>

class ResourceMgr {
public:
    // Constructors && destructor
    ResourceMgr();
    ~ResourceMgr();

    // Load level model, parser is decide by file extension
    void loadLevel(std::string fileName);
};
#endif // __RESOURCE_MANAGER__