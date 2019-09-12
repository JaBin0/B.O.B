#ifndef __GAMECFG__
#define __GAMECFG__
// System headers
#include <string>

class GameCfg {
public: 
    GameCfg() = delete;
    
    // Path to the model of the level 0.1
    static const std::string LevelMap;
};
#endif // __GAMECFG__