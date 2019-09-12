// System headers
#include <iostream>
// Own headers
#include <ResourceMgr.h>

ResourceMgr::ResourceMgr() {

}

ResourceMgr::~ResourceMgr() {

}

void ResourceMgr::loadLevel(std::string fileName) {
    std::cout << "Loading <" << fileName.data() << "> ..." << std::endl;
}

