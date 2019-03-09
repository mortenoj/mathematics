#include <SFML/Graphics.hpp>
#include "shape.h"

int const boardHeight = 20;
int const boardWidth = 12;
sf::Color const frameColor = sf::Color::White;

class Board {
public:
    sf::Color tiles[boardWidth][boardHeight];

    Board();

	// add a shape to the board
    void add(Shape& shape);

	// check if a shape intersects with the board
    bool intersect(Shape& shape);

	// remove full lines - should be implemented by you
    void reduce(int row);

	// render board
    void draw(sf::RenderWindow& w);

    int hasFullLine();

private:
    bool rowIsFull(int j);
};

bool Board::rowIsFull(int j) {
    for(int i = 0; i < boardWidth; i++) {
        if (tiles[i][j] == sf::Color::Black) {
            return false;
        }
    }
    return true;
}

int Board::hasFullLine() {
    for(int row = 0; row < boardHeight - 1; row++) {
        if (rowIsFull(row)) {
            return row;
        }
    }
    return -1;
}

void Board::reduce(int row) {
    // Loop over all rows above the full row
    // swap the rows above one row down
    for(int i = boardWidth - 1; i > 0; i--){
        for(int j = row - 1; j > 1; j--){
            // (Redundant) Don't move the frame
            if (tiles[i][j+1] == frameColor || j+1 == boardHeight) continue;
            
            // Push row one down
            tiles[i][j+1] = tiles[i][j];

            // Color the full line black
            tiles[i][j] = sf::Color::Black;
            
        }
    }
}

bool Board::intersect(Shape& shape) {
    bool intersect = false;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tiles[i+shape.pos.x][j+shape.pos.y] != sf::Color::Black && shape.tiles[i][j] != sf::Color::Black)
               intersect = true;
        }
    }
    return intersect;
}

void Board::draw(sf::RenderWindow& w) {
    sf::CircleShape s;
    s.setRadius(dotRadius);
    s.setOrigin(dotRadius, dotRadius);
    for(int i = 0; i < boardWidth; i++) {
        for(int j = 0; j < boardHeight; j++) {
            s.setFillColor(tiles[i][j]);
            s.setPosition(sf::Vector2f(dotRadius*2 * i + 100, dotRadius*2*j + 100));
            w.draw(s);
        }
    }
}

void Board::add(Shape& shape) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(shape.tiles[i][j] != sf::Color::Black) {
                tiles[i + shape.pos.x][j + shape.pos.y] = shape.tiles[i][j];
            }
        }
    }
}


Board::Board() {
	// fill with black
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 12; j++) {
            tiles[j][i] = sf::Color::Black;
        }
    }

	// boundary
    for(int i = 0; i < 12; i++) {
        tiles[i][19] = frameColor;
    }

    for(int i = 0; i < 19; i++) {
        tiles[0][i] = frameColor;
        tiles[11][i] = frameColor;
    }
}