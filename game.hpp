#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SFML/Graphics.hpp>
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
    sf::Image screenImage;
    sf::Sprite sprite;
    sf::Texture screenTexture;
    sf::Uint8 * screenBuffer;
    sf::Clock clock;
};

#endif // GAME_HPP
