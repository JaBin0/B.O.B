// System headers
#include <iostream>
#include <fstream>
// Own headers
#include <ResourceMgr.h>
#include <XmlNode.h>

ResourceMgr::ResourceMgr() {

}

ResourceMgr::~ResourceMgr() {

}

void ResourceMgr::loadLevel(std::string fileName) {
    std::cout << "Loading <" << fileName.data() << "> ... ";
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

    //std::cout << extension.data() << std::endl;
    // Decide which parser should be used
    // Parse model
}

XmlNode* ResourceMgr::parseXml(std::string fileName) {
    std::ifstream file;
    file.open(fileName, std::fstream::in);
    if(!file.is_open()) {
        std::cout << "Error" << std::endl << "<" << fileName.data() << "> could not be opened" << std::endl;
        return nullptr;
    }

    uint8_t namePos =  fileName.find_last_of('/') + 1;
    std::string name = fileName.substr(namePos, fileName.length() - namePos);
    XmlNode* root = new XmlNode(name);
    std::string line;

    while(!file.eof()) {
        std::getline(file, line, '\n');
        if(line.empty()) {
            continue;
        }

        std::string content;
        for(auto c=line.begin(); c != line.end(); ++c) {
            switch(*c) {
                case '<':
                    std::cout << "Start of the Tag: " << (*(++c)) << std::endl;
                break;
                default:
                    content+=*c;
                break;
            }
        }

        line.erase(0, line.find_first_not_of(' '));
        std::cout << line.data() << std::endl;

    }
}
