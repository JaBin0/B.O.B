class Engine {
public: 
    Engine()=delete;
    Engine(int width, int height);
    ~Engine();
    
    void printSize();

private:
    int m_width;
    int m_height;
};