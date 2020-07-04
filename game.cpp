#include "game.hpp"
#include "game.hpp"
#include <iostream>
#include <SFML/OpenGL.hpp>
Game::Game(const uint width, const uint height,const std::string &windowHead)
    : width(width), height(height)
{
    renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(width,height),windowHead);
    renderWindow->setActive();
    srand(time(nullptr));
    buffer = new unsigned char[width * height * 4];
    mainLoop();
}

void Game::mainLoop(){
    glViewport(0,0,width,height);
    glEnable(GL_TEXTURE_2D);
    bool running = true;
    while(running){
        float deltaTime = clock.restart().asSeconds();
        std::cout << 1/deltaTime << "  FPS \n";
        sf::Event event;
        while (renderWindow->pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                running = false;
            }
        }
        renderWindow->clear();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for(uint x = 0; x<width ;x++){
            for(uint y = 0 ;y<height ; y++){
                buffer[(x + y*width) * 4] = rand() % 255;
                buffer[(x + y*width) * 4 + 1] = rand() % 255;
                buffer[(x + y*width) * 4 + 2] = rand() % 255;
                buffer[(x + y*width) * 4 + 3] = rand() % 255;
            }
        }
        glDrawPixels(width,height,GL_RGBA,GL_UNSIGNED_BYTE,buffer);


        renderWindow->display();
    }
    //renderWindow->close();
}
