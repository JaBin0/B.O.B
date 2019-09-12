#ifndef __GAME__
#define __GAME__

// Forward declaration
class Engine;

class Game {
public:
    // Constructors && Destructor
    Game();
    ~Game();

    // Initialize game class
    void init();

    // Start the game
    void run();

private:
    // Instance of the game engine 
    Engine* m_engine;
};
#endif //__GAME__