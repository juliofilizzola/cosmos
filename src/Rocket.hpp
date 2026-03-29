#progma once
#include <SFML/Graphics.hpp>

class Rocket {
    public:
    Rocket();
    void update(sf::Time deltaTime);
    void setPosition(sf::Vector2f position);
    void setVelocity(sf::Vector2f velocity);
    sf::Sprite sprite;
    void render(sf::RenderWindow &window);

    private:
    sf::ConvexShape myShape;
    sf::Vector2f myPosition;
    sf::Vector2f myVelocity{0.f, 0.f};
    sf::Vector2f myAcceleration{0.f, 0.f};
};
