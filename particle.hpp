#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <SFML/System/Vector2.hpp>
#include "gravityobject.hpp"
#include <vector>
#include <limits>
class Particle
{
public:
    Particle(const GravityObject &gravs, const float mass, const sf::Vector2f pos);
    Particle(const GravityObject &gravs, const float mass, const sf::Vector2f pos,const std::vector<Particle> * otherParticles);
    void updatePos(const float deltaTime);
    void updateSpeed(const float deltaTime);

    //verySlow
    void updateSpeedotherParticles(const float deltaTime,const float maxDistance = std::numeric_limits<float>::max());

    void updateSpeedBasedOnOtherParticle(const float delatTime, Particle &p);

    sf::Vector2f getPosition() const;
    sf::Vector2f getSpeed() const;

private:
    sf::Vector2f position;
    sf::Vector2f speed;
    float mass;
    const GravityObject &gravityobject;
    const std::vector<Particle> * otherParticles;
};

#endif // PARTICLE_HPP
