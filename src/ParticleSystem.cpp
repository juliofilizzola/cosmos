//
// Created by Julio Filizzola on 28/03/26.
//

#include "ParticleSystem.hpp"
#include <random>

void ParticleSystem::reserve(int capacity) {
    myParticles.reserve(capacity);
}

void ParticleSystem::update(sf::Time deltaTime) {
    float delta = deltaTime.asSeconds();

    for (auto it = myParticles.begin(); it != myParticles.end();) {
        it->lifetime += delta;
        if (it->lifetime >= it->maxLifetime) {
            it = myParticles.erase(it);
        } else {
            float alpha = 1.f - (it->lifetime / it->maxLifetime);
            sf::Color color = it->shape.getFillColor();
            color.a = static_cast<std::uint8_t>(255 * alpha);
            it->shape.move(it->velocity * delta);
            ++it;
        }
    }
}

void ParticleSystem::render(sf::RenderWindow &window) {
    for (auto& particle : myParticles) {
        window.draw(particle.shape);
    }
}

void ParticleSystem::explode(sf::Vector2f position, int count, sf::Color color) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> angle(0.f, 360.f);
    std::uniform_real_distribution<float> speed(50.f, 200.f);
    std::uniform_real_distribution<float> size(1.f, 4.f);

    for (int i = 0; i < count; ++i) {
        Particle particle;
        particle.shape.setRadius(size(gen));
        particle.shape.setFillColor(color);
        particle.shape.setPosition(position);
        float a = angle(gen) * 3.14159f / 180.f;
        particle.velocity = {std::cos(a) * speed(gen), std::sin(a) * speed(gen)};
        particle.maxLifetime = 1.5f;
        myParticles.push_back(particle);
    }
}
