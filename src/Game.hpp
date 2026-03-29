#pragma once
#include <SFML/Graphics.hpp>
#include "Rocket.hpp"
#include "Star.hpp"  // ou Star.hpp
#include "ParticleSystem.hpp"

class Game {
public:
    Game();
    void run();
    void update(sf::Time deltaTime);
    void render();

private:
    void processEvents();
    void handleInput();

    sf::RenderWindow myWindow;
    Rocket myRocket;
    StarField myStarField;
    ParticleSystem myParticleSystem;
    sf::Clock myClock;
    bool isRunning = true;
};