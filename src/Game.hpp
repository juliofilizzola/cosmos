//
// Created by Julio Filizzola on 28/03/26.
//

#ifndef COSMOS_GAME_HPP
#define COSMOS_GAME_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include "Rocket.hpp"
#include "Star.hpp"
#include "ParticleSystem.hpp"

class Game {
    public:
        Game();
        void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handleInput();

    sf::RenderWindow myWindow;
    Rocket myRocket;
    StarField myStarField;
    ParticleSystem myParticleSystem;
    sf::Clock myClock;
    bool isRunning{true};
};



#endif //COSMOS_GAME_HPP
