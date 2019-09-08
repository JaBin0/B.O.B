// System headers
#include<iostream>
#include<Engine.h>

int main () {
    std::cout << "Game B.o.B"<<std::endl;
    Engine engine(1024,800);
    engine.printSize();
    return 0;
}