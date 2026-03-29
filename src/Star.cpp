//
// Created by Julio Filizzola on 28/03/26.
//

#include "Star.hpp"
#include <random>


StarField::StarField(int count) : myStart(count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<float> x(0.f, 1200.f);
    std::uniform_int_distribution<float> y(0.f, 800.f);
    std::uniform_real_distribution<float> size(1.f, 3.f);
    std::uniform_real_distribution<float> speed(20.f, 100.f);

    for (auto& star : myStart) {
        star.shape.setRadius(size(gen));
        // star.shape.setPosition(x(gen), y(gen));
        star.shape.setFillColor(sf::Color::White);
        star.speed = speed(gen);
    }
}

void StarField::update(sf::Time deltaTime) {
    float delta = deltaTime.asSeconds();
    for (auto& star : myStart) {
        star.shape.move(0.f, star.speed * delta);
        if (star.shape.getPosition().y > 800.f) {
            star.shape.setPosition((rand() %1200), -10.f);
        }
    }
}


void StarField::render(sf::RenderWindow &window) {
    for (auto& star : myStart) {
        window.draw(star.shape);
    }
}