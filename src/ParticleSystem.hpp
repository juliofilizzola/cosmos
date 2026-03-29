//
// Created by Julio Filizzola on 28/03/26.
//

#ifndef COSMOS_PARTICLESYSTEM_HPP
#define COSMOS_PARTICLESYSTEM_HPP
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>


class ParticleSystem {
public:
    struct Particle {
        sf::CircleShape shape;
        float lifetime = 0.f;
        float maxLifetime = 1.f;
        sf::Vector2f velocity;
    };

    void update(sf::Time deltaTime);
    void render(sf::RenderWindow &window);
    void explode(sf::Vector2f position, int count, sf::Color color);
    void reserve(int capacity);

private:
    std::vector<Particle> myParticles;
};



#endif //COSMOS_PARTICLESYSTEM_HPP
