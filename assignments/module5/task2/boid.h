#include <SFML/Graphics.hpp>
#include <iostream>

const float radius = 10.0f;
const sf::Color color = sf::Color::White;

class Boid {
private:
    /* data */
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    // Methods
    Boid();
    void draw(sf::RenderWindow& w);
    void update();
};

Boid::Boid() {
    position = sf::Vector2f(5.0f, 5.0f);
    velocity = sf::Vector2f(1.0f, 1.0f);
    acceleration = sf::Vector2f(1.0f, 1.0f);
}

void Boid::update() {
    position = sf::Vector2f(
        position.x + velocity.x,
        position.y + velocity.y
    );
    velocity += acceleration;

    std::cout << position.x << " " << position.y <<std::endl;
}

void Boid::draw(sf::RenderWindow& w) {
    sf::CircleShape shape;
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setFillColor(color);

    shape.setPosition(sf::Vector2f(
                            position.x * radius*2 + radius*2,
                            position.y * radius*2 + radius*2
                        ));

    w.draw(shape);
}
