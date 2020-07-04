#ifndef VECTORHELPERFUNCTIONS_HPP
#define VECTORHELPERFUNCTIONS_HPP
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <random>
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
    sf::Vector2f inP = makePositive(in);
    float lenght = std::sqrt((inP.x * inP.x) + (inP.y + inP.y));
    return sf::Vector2<T>(in.x/lenght, in.y/lenght);
}

inline sf::Vector2f randomVector(const float maxX , const float maxY){
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_real_distribution<float> randomX(0,maxX);
    std::uniform_real_distribution<float> randomY(0,maxY);
    return sf::Vector2f(randomX(mt),randomY(mt));
}

//returns distance and direction
template<typename T>
inline std::pair<float, sf::Vector2<T>> distanceDirection(const sf::Vector2<T> &from, const sf::Vector2<T> &to ){
    sf::Vector2<T> delta = to - from;
    sf::Vector2<T> deltaP = makePositive(delta);
    float lenght = std::sqrt((deltaP.x * deltaP.x) + (deltaP.y * deltaP.y));
    return std::make_pair(lenght,sf::Vector2<T>(delta.x/lenght,delta.y/lenght));
}
template<typename T>
inline T lenght(sf::Vector2<T> in){
    in = makePositive(in);
    return std::sqrt((in.x * in.x) + (in.y + in.y));
}

#endif // VECTORHELPERFUNCTIONS_HPP
