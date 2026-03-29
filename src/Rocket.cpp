//
// Created by Julio Filizzola on 28/03/26.
//

#include "Rocket.hpp"

Rocket::Rocket() {
    myShape.setPointCount(3);
    myShape.setPoint(0, {-15.f, 20.f});
    myShape.setPoint(1, {0.f, -30.f});
    myShape.setPoint(2, {15.f, 20.f});
    myShape.setFillColor(sf::Color::Cyan);
    myShape.setOutlineColor(sf::Color::White);
    myShape.setOutlineThickness(2.f);
}

void Rocket::update(sf::Time deltaTime) {
    myVelocity.y += myAcceleration.y * deltaTime.asSeconds();
    myPosition += myVelocity * deltaTime.asSeconds();

    if (myPosition.x > 1200.f) {
        myPosition.x = 0.f;
    }

    if (myPosition.x < 0.f) {
        myPosition.x = 1200.f;
    }

    if (myPosition.y > 800.f) {
        myPosition.y = 0.f;
    }

    if (myPosition.y < 0.f) {
        myPosition.y = 800.f;
    }

    myShape.setPosition(myPosition);
}

void Rocket::setPosition(sf::Vector2f position) {
    myPosition = position;
}

void Rocket::setVelocity(sf::Vector2f velocity) {
    myVelocity = velocity;
}

void Rocket::render(sf::RenderWindow &window) {
    window.draw(myShape);
}

