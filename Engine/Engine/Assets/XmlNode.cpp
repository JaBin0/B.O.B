// System headers
#include <iostream>
// Own headers
#include <XmlNode.h>

XmlNode::XmlNode(const std::string name, XmlNode* parent) 
    : m_name {name}
    , m_parent {parent}
    , m_value {}
    , m_children {}
    , m_properties {}
{
    // Add this node to the parent
    if(nullptr != m_parent) {
        m_parent->addChildNode(this);
    }
}

XmlNode::~XmlNode() {
    for(auto child : m_children) {
        delete child;
    }
}

std::string XmlNode::getName() const {
    return m_name;
}

XmlNode* XmlNode::getParent() const {
    return m_parent;
}

std::vector<XmlNode*> XmlNode::children() {
    return m_children;
}

void XmlNode::addChildNode(XmlNode* child) {
    bool isAlreadyIn = false;
    for(auto nodeChild : m_children) {
        if(nodeChild == child) {
            isAlreadyIn = true;
            break;
        }
    }

    if(!isAlreadyIn) {
        m_children.push_back(child);
    }
}

XmlNode* XmlNode::createNewChildNode(const std::string name) {
    m_children.push_back(new XmlNode(name, this));
    return m_children.back();
}

std::string XmlNode::getProperty(const std::string name) {
    return m_properties[name];
}

void XmlNode::setProperty(const std::string name, const std::string value) {
    m_properties[name] = value;
}

std::string XmlNode::getValue() const {
    return m_value;
}

void XmlNode::setValue(const std::string value) {
    if(value != m_value) {
        m_value = value;
    }
}

void XmlNode::print(uint16_t offset) {
    std::string stringOffset(offset, ' ');
    std::cout << stringOffset.data() << "<" << m_name;
    for (auto property : m_properties) {
        std::cout << " "<< property.first.data() << "=\"" << property.second.data() << "\"";
    }

    if(m_children.size() == 0 && m_value.length() == 0)  {
        std::cout << "/>" <<std::endl;
    }
    else {
        std::cout << ">";
        if(m_value.length() != 0) {
            std::cout << m_value.data();
        }
        else {
            std::cout << std::endl;
            for (auto child : m_children) {
                child->print(offset + 2);
            }
            std::cout << stringOffset;
        }
        std::cout << "</" << m_name << ">" <<std::endl;
    }
}