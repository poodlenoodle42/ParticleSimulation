#include "particle.hpp"
#include "vectorhelperfunctions.hpp"
Particle::Particle(const GravityObject &gravs, const float mass, const sf::Vector2f pos)
    : gravityobject(gravs) , mass(mass) , position(pos)
{

}

void Particle::updatePos(const float deltaTime){
    position += speed * deltaTime;
}

void Particle::updateSpeed(const float deltaTime){
    sf::Vector2f direction = normalize(position - gravityobject.pos);
    float distanceF = distance(position, gravityobject.pos);
    float force = (mass * gravityobject.mass) / (distanceF * distanceF);
    speed += (force / mass) * direction;
}
