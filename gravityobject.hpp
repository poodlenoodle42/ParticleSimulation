#ifndef GRAVITYOBJECT_HPP
#define GRAVITYOBJECT_HPP

#include <SFML/System/Vector2.hpp>
struct GravityObject
{
public:
    GravityObject(const float mass);
    float mass;
    sf::Vector2f pos;
};

#endif // GRAVITYOBJECT_HPP
