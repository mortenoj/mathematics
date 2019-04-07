#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "point.h"

class Ball {
 public:
    Point pos;
    Point velocity;
    sf::Vector2f velocityGoal;
    float radius;
    sf::Color color;
    sf::Color colorGoal;

    Ball();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void init();

    void update(float dt);


    void intersect();

    void draw(sf::RenderWindow& w);

    float approach(float flGoal, float fCurrent, float dt);
    float lerp(float v0, float v1, float t);
    float lerp2(float a, float b, float t);
    void interpolate(float dt);
    void interpBezier(float dt);
    Point quadraticBezier(Point p0, Point p1, Point p2, float t);

private:
    // times since last downward movement
    float time;

};

Ball::Ball() {
    init();
}

void Ball::init() {
    pos.x = 5.0f;
    pos.y = 5.0f;

    velocity.x = 0.0f;
    velocity.y = 0.0f;

    velocityGoal.x = 0;
    velocityGoal.y = 0;

    colorGoal = sf::Color::White;

    radius = 50.0f;

    color = sf::Color(255, 255, 0, 255);
}

void Ball::draw(sf::RenderWindow& w) {
    sf::CircleShape shape;
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setFillColor(color);

    shape.setPosition(sf::Vector2f(
                            pos.x * radius*2 + radius*2 + velocity.x,
                            pos.y * radius*2 + radius*2 + velocity.y
                        ));

    w.draw(shape);
}

void Ball::update(float dt) {
    interpolate(dt);
    // interpBezier(dt);

    intersect();
}

void Ball::interpBezier(float dt) {
    Point p0 = Point(0.0f, 10.0f);
    Point p1 = Point(5.0f, 0.0f);
    Point p2 = Point(10.0f, 5.0f);

    pos = quadraticBezier(p0, p1, p2, dt);
}

void Ball::interpolate(float dt) {
    velocity.x = lerp(velocityGoal.x, velocity.x, dt * 65);
	velocity.y = lerp(velocityGoal.y, velocity.y, dt * 65);
    
    color.r = approach(colorGoal.r, color.r, dt / 100);
    color.g = approach(colorGoal.g, color.g, dt / 100);
    color.b = approach(colorGoal.b, color.b, dt / 100);

	pos = pos + velocity * dt;
    velocity = velocity * dt;
}

void Ball::intersect() {
    if (pos.x <= 0.0f) {
        pos.x = 0.0f;
    }
    if (pos.x >= 15.0f) {
        pos.x = 15.0f;
    }
    if (pos.y <= 0.0f) {
        pos.y = 0.0f;
    }
    if (pos.y >= 15.0f) {
        pos.y = 15.0f;
    }
}

void Ball::moveLeft() {
    velocityGoal.x = -15.0f;
    colorGoal = sf::Color::Blue;
}

void Ball::moveRight() {
    velocityGoal.x = 15.0f;
    colorGoal = sf::Color::Red;
}

void Ball::moveUp() {
    velocityGoal.y = -15.0f;
    colorGoal = sf::Color::Green;
}

void Ball::moveDown() {
    velocityGoal.y = 15.0f;
    colorGoal = sf::Color::Magenta;
}

// Precise method, which guarantees v = v1 when t = 1.
float Ball::lerp(float v0, float v1, float t) {
    return (1 - t) * v0 + t * v1;
}

// Linear approach interpolation
float Ball::approach(float goal, float current, float dt) {
    if (goal == 0.0f) return 0.0f;

    float diff = goal - current;

    if (diff < goal) {
        return current + dt;
    }

    if (diff > goal) {
        return current - dt;
    }

    return goal;
}

Point Ball::quadraticBezier(Point p0, Point p1, Point p2, float t) {
    Point pFinal = Point();
    pFinal.x = std::pow(1 - t, 2) * p0.x + (1 - t) * 2 * t * p1.x + t * t * p2.x;
    pFinal.y = std::pow(1 - t, 2) * p0.y + (1 - t) * 2 * t * p1.y + t * t * p2.y;
    return pFinal;
}