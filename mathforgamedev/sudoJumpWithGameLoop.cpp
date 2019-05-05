#include <iostream>

#include "Vector.h"
#include "Point.h"


void update(float dt) {
    position = position + velocity * dt;
    velocity = velocity + gravity * dt;
}

int main() {

    Point pos = Point(0, 0);
    Vector vel = Vector(2, 2);
    Vector gravity = Vector(0, -2);

    float flPreviousTime = 0;
    float flCurrentTime = getCurrentTime();

    while(true) {
        flPreviousTime = flCurrentTime;
        flCurrentTime = getCurrentTime();

        float dt = flCurrentTime - flPreviousTime;

        if (dt > 0.15)
            dt = 0.15;

        update(dt);
        draw();
    } 

    return 0;
}
