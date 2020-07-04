#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <SFML/System/Vector2.hpp>
#include "gravityobject.hpp"
#include <vector>
class Particle
{
public:
    Particle(const GravityObject &gravs, const float mass, const sf::Vector2f pos);
    void updatePos(const float deltaTime);
    void updateSpeed(const float deltaTime);
private:
    sf::Vector2f position;
    sf::Vector2f speed;
    float mass;
    const GravityObject &gravityobject;
};

#endif // PARTICLE_HPP
