#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include "particle.hpp"
#include <vector>
#include <thread>
typedef unsigned int uint;
class Game
{
public:
    Game(const uint width, const uint height, const uint numberParticles,
         const std::string &windowHead);
private:
    void mainLoop();
    uint width;
    uint height;
    std::unique_ptr<sf::RenderWindow> renderWindow;
    sf::Image screenImage;
    sf::Sprite sprite;
    sf::Texture screenTexture;
    sf::Clock clock;
    sf::Clock simulationClock;
    std::thread simulationThread;
    bool simulate = true;

    GravityObject blackHole;

    std::vector<Particle> particles;

    inline sf::Color colorFromSpeed(float in);

};

#endif // GAME_HPP
