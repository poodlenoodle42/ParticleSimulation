#include "game.hpp"
#include <iostream>
#include <vectorhelperfunctions.hpp>
Game::Game(const uint width, const uint height,const uint numberParticles,
           const std::string &windowHead)
    : width(width), height(height), blackHole(100000)
{
    renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(width,height),windowHead);
    screenImage.create(width,height);
    screenTexture.loadFromImage(screenImage);
    sprite.setTexture(screenTexture);

    for(uint i = 0; i < numberParticles; i++){
        particles.push_back(Particle(blackHole,100,randomVector(width,height)));
    }
    mainLoop();
}

void Game::mainLoop(){
    while(renderWindow->isOpen()){

        sf::Vector2i mousePos = sf::Mouse::getPosition(*renderWindow);
        if(mousePos.x < width && mousePos.y < height && mousePos.x > 0 && mousePos.y > 0){
            blackHole.pos = sf::Vector2f(mousePos.x,mousePos.y);
        }
        float deltaTime = clock.restart().asSeconds();
        std::cout << 1/deltaTime << "  FPS \n";
        sf::Event event;
        while (renderWindow->pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                renderWindow->close();
            }
        }
        //Update
        for (Particle &p : particles) {

            p.updatePos(deltaTime);
            p.updateSpeed(deltaTime);
        }
        //Rendering
        screenImage.create(width,height);
        for(const Particle &p : particles){
            sf::Vector2f pos = p.getPosition();
            if(pos.x < width && pos.y < height && pos.x > 0 && pos.y > 0)
                screenImage.setPixel(pos.x,pos.y,sf::Color(255,255,255,255));
        }
        screenTexture.loadFromImage(screenImage);
        renderWindow->draw(sprite);
        renderWindow->display();
    }
}
