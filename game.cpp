#include "game.hpp"
#include "game.hpp"
#include <iostream>
Game::Game(const uint width, const uint height,const std::string &windowHead)
    : width(width), height(height)
{
    renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(width,height),windowHead);
    screenImage.create(width,height);
    screenBuffer = new sf::Uint8[width * height * 4];
    screenTexture.loadFromImage(screenImage);
    sprite.setTexture(screenTexture);
    srand(time(nullptr));
    mainLoop();
}

void Game::mainLoop(){
    while(renderWindow->isOpen()){
        float deltaTime = clock.restart().asSeconds();
        std::cout << 1/deltaTime << "  FPS \n";
        sf::Event event;
        while (renderWindow->pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                renderWindow->close();
            }
        }
        for(uint y = 0; y < height; y++){
            for(uint x = 0;x<width;x++){
                screenImage.setPixel(x,y,sf::Color(rand() % 255, rand() % 255, rand() % 255));
            }
        }
        //screenImage.create(width, height, screenBuffer);
        screenTexture.loadFromImage(screenImage);
        renderWindow->draw(sprite);
        renderWindow->display();
    }
}
