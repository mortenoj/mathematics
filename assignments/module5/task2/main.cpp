// g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> // for string class 

#include "boid.h"

int const windowHeight = 1600;
int const windowWidth = 1600;

void drawSfText(std::string txt, int posX, int posY, int fontSize, sf::RenderWindow &w) {
    // Load the font from a file
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "error loading file\n";
    }

    sf::Text text(txt, font, fontSize);
    text.setPosition(posX, posY);
    
    w.draw(text);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Task1");

    sf::Clock clock;
    clock.restart();

    Boid boid;
    std::vector<Boid> flock;

    flock.push_back(Boid());

    // window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        float dt = clock.restart().asSeconds();
        // Keep dt from growing too large.
		// if (dt > 0.1f)
		// 	dt = 0.1f;

		// ball.update(dt);

        float framerate = 1.0f / dt;

        window.clear(sf::Color::Black);
        // ball.draw(window);

        for (auto boid : flock) {
            boid.update();
            boid.draw(window);
        }

        drawSfText("Task2", windowWidth*0.5, windowHeight * 0.1, 100, window);
        drawSfText("FPS: " + std::to_string(framerate), windowWidth*0.5, windowHeight * 0.2, 30, window);
        window.display();
    }

    return 0;
}

