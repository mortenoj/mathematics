#include <cmath>

class EulerAngle {
public:
    float pitch;
    float yaw;
    float roll;

    EulerAngle();
    EulerAngle(float pitch, float yaw, float roll);
    Vector toVector();
    void normalize();
};


EulerAngle::EulerAngle() {
    pitch = yaw = roll = 0;
}

EulerAngle::EulerAngle(float pitch, float yaw, float roll) {
    this->pitch = pitch;
    this->yaw = yaw;
    this->roll = roll;
}

Vector EulerAngle::toVector() {
    return Vector(
        cos(yaw) * cos(pitch),
        sin(pitch),
        sin(yaw) * cos(pitch)
    );
}

void EulerAngle::normalize() {
    if (pitch > 89)
        pitch = 89;
    if (pitch < -89)
        pitch = -89;
    
    while(yaw < -180)
        yaw += 360;
    while(yaw > 180)
        yaw -= 360;
}