#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class StarField {
public:
    explicit StarField(int count);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow &window);

private:
    struct Star {
        sf::CircleShape shape;
        float speed{};
    };

    std::vector<Star> myStart;
};
