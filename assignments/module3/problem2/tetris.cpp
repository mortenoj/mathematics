
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string> // for string class 

#include "board.h"

int const windowHeight = 1600;
int const windowWidth = 1600;
int const textFontSize = 60;

float speed = 1.0f;
float displaySpeed = 100.0f;
float speedTimer = 0.0f;

int score = 0;
int combo = 1;

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
    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Tetris");
    
    sf::Clock clock;
    clock.restart();

    sf::Clock clock2;
    clock2.restart();
    
    bool lastBlockComplete = false;
    
    Shape shape;

    Board board;

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Left) {
                    shape.pos.x -= 1;
                    // Intersect left
					if (board.intersect(shape)) {
						shape.pos.x += 1;
					}
                }
                if(event.key.code == sf::Keyboard::Right) {
                    shape.pos.x += 1;
                    // Intersect right
                    if(board.intersect(shape)) {
						shape.pos.x -= 1;
					}
                }
                if(event.key.code == sf::Keyboard::Down) {
                    shape.pos.y += 1;
                    // Intersect down
                    if(board.intersect(shape)) {
						shape.pos.y -= 1;
					}
                }
                if(event.key.code == sf::Keyboard::Up) {
                    shape.rotateLeft();
                    // Intersect rotate
                    if(board.intersect(shape)) {
						shape.rotateRight();
					}
                }
            }
        }
            
		float dt = clock.restart().asSeconds();
		
        shape.update(dt, speed);

        

        if(board.intersect(shape)) {
            shape.pos.y -= 1;
            board.add(shape);
            shape.init();
            if (board.hasFullLine() != -1 && lastBlockComplete) {
                lastBlockComplete = true;
                combo *= 2;
            } else {
                combo = 1;
                lastBlockComplete = false;
            }
            if(board.intersect(shape)) {
                std::cout << "GAME OVER" << std::endl;
                break;
            }
        }

        // Removes all all full lines and updates score
        if (board.hasFullLine() != -1) {
            lastBlockComplete = true;
            score += 100 * combo;
            board.reduce(board.hasFullLine());
        }

        // increase speed of the game every x seconds
        speedTimer += clock2.restart().asSeconds();
        if (speedTimer > 50.0f) {
            speedTimer = 0.0f;
            speed += 1;
            displaySpeed += 1.0f/speed*100;
        }

        window.clear(sf::Color::Black);

        board.draw(window);
        shape.draw(window);

        std::string cScore = std::to_string(score);
        std::string cCombo = std::to_string(combo);
        std::string cSpeed = std::to_string(static_cast<int>(displaySpeed));

        
        drawSfText("TETRIS GAME!", windowWidth*0.6, windowHeight * 0.2, 100, window);
        drawSfText("Speed: " + cSpeed + "%", windowWidth*0.6, windowHeight * 0.4, textFontSize, window);
        drawSfText("Score: " + cScore, windowWidth*0.6, windowHeight * 0.5, textFontSize, window);
        drawSfText("Combo: " + cCombo, windowWidth*0.6, windowHeight * 0.6, textFontSize, window);

        window.display();
    }

    return 0;
}


