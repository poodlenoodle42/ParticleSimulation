#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <memory>
typedef unsigned int uint;
class Game
{
public:
    Game(const uint width, const uint height,const std::string &windowHead);
private:
    void mainLoop();
    uint width;
    uint height;
    std::unique_ptr<sf::RenderWindow> renderWindow;
    sf::Clock clock;
    unsigned char * buffer;

};

#endif // GAME_HPP
