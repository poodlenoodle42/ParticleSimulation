#include "particle.hpp"
#include "vectorhelperfunctions.hpp"
Particle::Particle(const GravityObject &gravs, const float mass, const sf::Vector2f pos)
    : gravityobject(gravs) , mass(mass) , position(pos), otherParticles(nullptr)
{

}
Particle::Particle(const GravityObject &gravs, const float mass, const sf::Vector2f pos,const std::vector<Particle> * otherParticles)
    : gravityobject(gravs) , mass(mass) , position(pos), otherParticles(otherParticles){}


void Particle::updatePos(const float deltaTime){
    position += speed * deltaTime;
}
void Particle::updateSpeed(const float deltaTime){
    sf::Vector2f direction = normalize(gravityobject.pos - position);
    float distanceF = distance(position, gravityobject.pos);
    float force = (mass * gravityobject.mass) / (distanceF * distanceF);
    speed += ((force / mass) * deltaTime) * direction;

}

void Particle::updateSpeedotherParticles(const float deltaTime, const float maxDistance){
    for(const Particle &p : *otherParticles){
        float distanceF = distance(position, p.position);
        if(&p != this && distanceF < maxDistance){
            sf::Vector2f direction = normalize(p.position - position);
            float force = (mass * p.mass) / (distanceF * distanceF);
            speed += ((force / mass) * deltaTime) * direction;
        }
    }
    sf::Vector2f direction = normalize(gravityobject.pos - position);
    float distanceF = distance(position, gravityobject.pos);
    float force = (mass * gravityobject.mass) / (distanceF * distanceF);
    speed += ((force / mass) * deltaTime) * direction;
}

sf::Vector2f Particle::getPosition() const
{
    return position;
}

sf::Vector2f Particle::getSpeed() const
{
    return speed;
}
