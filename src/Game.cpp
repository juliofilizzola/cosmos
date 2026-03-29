#include "Game.hpp"

Game::Game() : myWindow(sf::VideoMode({1200u, 800u}), "Cosmos"), myStarField(200) {
    myWindow.setFramerateLimit(60);
    myRocket.setPosition({600.f, 600.f});
    myStarField = StarField(200);
    myParticleSystem.reserve(500);
}

void Game::run() {
    while (isRunning) {
        processEvents();
        update(myClock.restart());
        render();
    }
}

void Game::processEvents() {
    while (const auto event = myWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
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
    constexpr float speed = 200.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
        velocity.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
        velocity.y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
        velocity.x += speed;
    }

    myRocket.setVelocity(velocity);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)) {
        myParticleSystem.explode(myRocket.getPosition(), 50, sf::Color::Yellow);
    }
}

void Game::render() {
    myWindow.clear(sf::Color::Black);
    myStarField.render(myWindow);
    myRocket.render(myWindow);
    myParticleSystem.render(myWindow);
    myWindow.display();
}