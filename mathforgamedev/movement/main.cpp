#include <iostream>

#include "Vector.h"
#include "Point.h"
#include "EulerAngle.h"

// ------------------------------------ Extra methods ------------------------------------
float approach(float goal, float current, float dt);




int main() {

    Vector a(0, 1, 0);
    Vector b(1, 0, 0);

    Vector v = b.cross(a);

    v.print();

    return 0;
}


// ------------------------------------ Extra methods ------------------------------------


// Lerp method
float approach(float goal, float current, float dt) {
    // How far is it left
    float diff = goal - current;

    // If dt is not enough to take us to the goal
    if (diff > dt) {
        return current + dt;
    }
    // If dt is not enough to take us to the goal in the negative direction
    // Enables to lerp down
    if (diff < -dt) {
        return current - dt;
    }
    
    // If we are at the goal
    return goal;
}
