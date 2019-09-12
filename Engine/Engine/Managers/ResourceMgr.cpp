// System headers
#include <iostream>
// Own headers
#include <ResourceMgr.h>
#include <XmlNode.h>

ResourceMgr::ResourceMgr() {

}

ResourceMgr::~ResourceMgr() {

}

void ResourceMgr::loadLevel(std::string fileName) {
    std::cout << "Loading <" << fileName.data() << "> ..." << std::endl;
    // Get extension of the file
    auto comaIndex = fileName.find_last_of('.');
    if(comaIndex == -1) {
        std::cout << "Error: file <" << fileName.data() << "> does not have proper extension" << std::endl;
        return;
    }

    std::string extension = fileName.substr(comaIndex + 1, fileName.size() - comaIndex);
    if("dae" == extension) {
        XmlNode* root = parseXml(fileName);
    }

    std::cout << extension.data() << std::endl;
    // Decide which parser should be used
    // Parse model
}

XmlNode* ResourceMgr::parseXml(std::string fileName) {
    
}
