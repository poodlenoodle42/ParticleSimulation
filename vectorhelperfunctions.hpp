#ifndef VECTORHELPERFUNCTIONS_HPP
#define VECTORHELPERFUNCTIONS_HPP
#include <SFML/System/Vector2.hpp>
#include <cmath>
template<typename T>
inline sf::Vector2<T> makePositive(const sf::Vector2<T> &in){
    sf::Vector2<T> out = in;
    if(out.x < 0)
        out.x *= -1;
    if(out.y < 0)
        out.y *= -1;
    return out;
}

template<typename T>
inline float distance(const sf::Vector2<T> &from , const sf::Vector2<T> &to){
    sf::Vector2<T> delta = to - from;
    delta = makePositive(delta);
    return std::sqrt((delta.x * delta.x) + (delta.y * delta.y));
};

template<typename T>
inline sf::Vector2<T> normalize(const sf::Vector2<T> &in){
    float lenght = std::sqrt((in.x * in.x) + (in.y + in.y));
    return sf::Vector2<T>(in.x/lenght, in.y/lenght);
}

#endif // VECTORHELPERFUNCTIONS_HPP
