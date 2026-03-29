//
// Created by Julio Filizzola on 28/03/26.
//

#include "Game.hpp"

Game::Game() : myWindow(sf::VideoMode(1200, 800), "Cosmos") {
    myWindow.setFramerateLimit(60);
    myRocket.setPosition({600.f, 600.f});
    myStarField = StarField(200);
    myParticleSystem.reserve(500);
}


void Game::run() {
    sf::Event event;
    while (myWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
        }
    }
}


void Game::update(sf::Time deltaTime) {
    handleInput();
    myRocket.update(deltaTime);
    myStarField.update(deltaTime);
    myParticleSystem.update(deltaTime);
}

void Game::handleInput() {
    sf::Vector2f velocity{0.f, 0.f};
    constexpr  float speed = 200.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.y -= speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocity.y += speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += speed;
    }
    myRocket.setVelocity(velocity);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        myParticleSystem.explode(myRocket.sprite.getPosition(), 50, sf::Color::Yellow);
    }
}

void Game::render() {
    myWindow.clear(sf::Color::Black);
    myStarField.render(myWindow);
    myRocket.render(myWindow);
    myParticleSystem.render(myWindow);
    myWindow.display();
}
