// System header
#include <iostream>
// Own headers
#include <Game.h>
#include <GameCfg.h>
#include <Engine.h>
#include <ResourceMgr.h>

Game::Game() {
    std::cout << "Game B.o.B - v0.001.2a"<<std::endl;
    init();
}

Game::~Game() {
    delete m_engine;
}

void Game::init() {
    m_engine = new Engine(1024,800);
    ResourceMgr& resourceMgr = m_engine->getResourceMgr();
    resourceMgr.loadLevel(GameCfg::LevelMap);
}

void Game::run() {
    
}
