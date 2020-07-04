#include "game.hpp"
#include <iostream>
#include <vectorhelperfunctions.hpp>
Game::Game(const uint width, const uint height,const uint numberParticles,
           const std::string &windowHead)
    : width(width), height(height), blackHole(10000)
{
    renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(width,height),windowHead);
    screenImage.create(width,height);
    screenTexture.loadFromImage(screenImage);
    sprite.setTexture(screenTexture);

    for(uint i = 0; i < numberParticles; i++){
        particles.push_back(Particle(blackHole,10,randomVector(width,height)));
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
            if(pos.x < width && pos.y < height && pos.x > 0 && pos.y > 0){
                float speed = lenght(p.getSpeed());
                screenImage.setPixel(pos.x,pos.y,colorFromSpeed(speed));
            }
        }
        screenTexture.loadFromImage(screenImage);
        renderWindow->draw(sprite);
        renderWindow->display();
    }
}

sf::Color Game::colorFromSpeed(float a){

    a /= 3.0f;
    a -= 6.0f;
    float b = -6.0;
    int c = 0;
    if(a<=b){
        return sf::Color(255,0,128);
    }
    if(a < -2.175f){
        for(float i=-6.0 ; i<-2.175f;i+=0.015f){
            b=i;
            if(i>=a){
                return sf::Color(0,c,128+(c/2));
            }
            c++;
        }
    }
    else if(a < 1.65f){
        for(float i=-2.175f ; i<1.65f;i+=0.015f){
            b=i;
            if(i>=a){
                return sf::Color(c,255,255-c);
            }
            c++;
        }
    }
    else if(a < 5.475f){
        for(float i=1.65f ; i<5.475f;i+=0.015f){
            if(i>=a){
                return sf::Color(255,255-c,c);
            }
            c++;
        }
    }
    return sf::Color(255,0,255);
}
