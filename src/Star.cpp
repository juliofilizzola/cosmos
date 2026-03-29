#include "Star.hpp"
#include <random>

StarField::StarField(const int count) : myStart(count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> x(0.f, 1200.f);
    std::uniform_real_distribution<float> y(0.f, 800.f);
    std::uniform_real_distribution<float> size(1.f, 3.f);
    std::uniform_real_distribution<float> spd(20.f, 100.f);

    for (auto&[shape, speed] : myStart) {
        shape.setRadius(size(gen));
        shape.setPosition({x(gen), y(gen)});
        shape.setFillColor(sf::Color::White);
        speed = spd(gen);
    }
}

void StarField::update(const sf::Time deltaTime) {
    float dt = deltaTime.asSeconds();
    for (auto& star : myStart) {
        star.shape.move({0.f, star.speed * dt});
        if (star.shape.getPosition().y > 800.f) {
            star.shape.setPosition(
                {static_cast<float>(rand() % 1200), -10.f}
            );
        }
    }
}

void StarField::render(sf::RenderWindow& window) {
    for (const auto&[shape, speed] : myStart) {
        window.draw(shape);
    }
}