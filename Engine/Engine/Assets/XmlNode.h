#ifndef __XML_NODE__
#define __XML_NODE__
// System headers
#include <string>
#include <vector>
#include <unordered_map>

class XmlNode {
public:
    // Consturctors && destructor
    XmlNode(const std::string name, XmlNode* parent = nullptr);
    ~XmlNode();

    // Return name of the node
    std::string getName() const;

    // Return parent of the node
    XmlNode* getParent() const;

    // Getter return list of node children
    std::vector<XmlNode*> children();

    // Add child to the node
    void addChildNode(XmlNode* child);

    // Create new child to the node and return pointer to that child
    XmlNode* createNewChildNode(const std::string name);

   // Return node property
    std::string getProperty(const std::string name);

    // Set Node property
    void setProperty(const std::string name, const std::string value);

    // Return value of the node
    std::string getValue() const;

    // Set value of node
    void setValue(const std::string value);

    // Print node and his children with the given offset
    void print(uint16_t offset = 0);

private:
    // Name of the node
    std::string m_name;

    // Parent of the node
    XmlNode* m_parent;

    // Value of node
    std::string m_value;

    // Children vector for this node
    std::vector<XmlNode*> m_children;

    // Map for node properties
    std::unordered_map<std::string, std::string> m_properties;
};

#endif // __XML_NODE__