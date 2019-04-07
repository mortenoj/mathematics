#include <iostream>

class Point {
public:
    float x;
    float y;
    
    Point(float xVal, float yVal) {
        x = xVal;
        y = yVal;
    }
    Point() {}

    Point operator *(float scalar) { 
        return Point(x*scalar, y*scalar);
    }

    Point operator +(Point p2) { 
        return Point(x+p2.x, y+p2.y);
    }

    Point operator +=(Point p2) { 
        x += p2.x;
        y += p2.y;
    }
};

