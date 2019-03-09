#include <SFML/Graphics.hpp>
int const dotRadius = 36;

class Shape {
public:
    sf::Color tiles[4][4];
    sf::Vector2i pos;

	// times since last downward movement
    float time;

    Shape();

	// reinitialise the shape: move to top and change shape
    void init();

	// move downwards once per second
    void update(float dt, float speed);

	// render the shape
    void draw(sf::RenderWindow& w);
    
	// rotate the shape
	void rotateLeft();
    void rotateRight();

    void shapeTiles();
};

void Shape::rotateLeft() {
    sf::Color tmp[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tmp[i][j]=tiles[j][3-i];
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tiles[i][j]=tmp[i][j];
        }
    }
}

void Shape::rotateRight() {
    rotateLeft();
    rotateLeft();
    rotateLeft();
}

Shape::Shape() {
    init();
}

void Shape::init() {
	// move to top and reset timer
    pos.y = 0;
    pos.x = 4;
	time = 0.0f;

	// fill with black tiles
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tiles[i][j] = sf::Color::Black;
        }
    }

    shapeTiles();
}

void Shape::update(float dt, float speed) {
    time += dt;
    if(time > (1.0f / speed)) {
        time = 0;
        pos.y += 1;
    }
}

void Shape::draw(sf::RenderWindow& w) {
    sf::CircleShape s;
    s.setRadius(dotRadius);
    s.setOrigin(dotRadius, dotRadius);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tiles[i][j] != sf::Color::Black) {
                s.setFillColor(tiles[i][j]);
                s.setPosition(sf::Vector2f(pos.x * dotRadius*2 + dotRadius*2 * i + 100,
                                           pos.y * dotRadius*2 + dotRadius*2 * j + 100));
                w.draw(s);
            }
        }
    }
}

void Shape::shapeTiles() {
    // two hardcoded shapes - this should be changed by you
    switch(rand() % 7) {
    // [0, 0, x, 0]
    // [0, 0, x, 0]
    // [0, 0, x, 0]
    // [0, 0, x, 0]
    case 0:
        tiles[2][0] = sf::Color::Cyan;
        tiles[2][1] = sf::Color::Cyan;
        tiles[2][2] = sf::Color::Cyan;
        tiles[2][3] = sf::Color::Cyan;
        break;

    // [0, 0, x, 0]
    // [0, x, x, 0]
    // [0, x, 0, 0]
    // [0, 0, 0, 0]
    case 1:
        tiles[0][2] = sf::Color::Red;
        tiles[1][2] = sf::Color::Red;
        tiles[1][1] = sf::Color::Red;
        tiles[2][1] = sf::Color::Red;
        break;

    // [0, x, x, 0]
    // [0, x, 0, 0]
    // [0, x, 0, 0]
    // [0, 0, 0, 0]
    case 2:
        tiles[0][2] = sf::Color::Blue;
        tiles[0][1] = sf::Color::Blue;
        tiles[1][1] = sf::Color::Blue;
        tiles[2][1] = sf::Color::Blue;
        break;

    // [0, x, x, 0]
    // [0, 0, x, 0]
    // [0, 0, x, 0]
    // [0, 0, 0, 0]
    case 3:
        tiles[0][1] = sf::Color(255,140,0); // Orange
        tiles[0][2] = sf::Color(255,140,0);
        tiles[1][2] = sf::Color(255,140,0);
        tiles[2][2] = sf::Color(255,140,0);
        break;
    
    // [0, 0, 0, 0]
    // [0, x, x, 0]
    // [0, x, x, 0]
    // [0, 0, 0, 0]
    case 4:
        tiles[1][1] = sf::Color::Yellow;
        tiles[1][2] = sf::Color::Yellow;
        tiles[2][1] = sf::Color::Yellow;
        tiles[2][2] = sf::Color::Yellow;
        break;
    
    // [0, x, 0, 0]
    // [0, x, x, 0]
    // [0, 0, x, 0]
    // [0, 0, 0, 0]

    case 5:
        tiles[0][1] = sf::Color::Green;
        tiles[1][1] = sf::Color::Green;
        tiles[1][2] = sf::Color::Green;
        tiles[2][2] = sf::Color::Green;
        break;

    // [0, x, 0, 0]
    // [0, x, x, 0]
    // [0, x, 0, 0]
    // [0, 0, 0, 0]
    case 6:
        tiles[0][1] = sf::Color::Magenta;
        tiles[1][1] = sf::Color::Magenta;
        tiles[1][2] = sf::Color::Magenta;
        tiles[2][1] = sf::Color::Magenta;
        break;
    }
}