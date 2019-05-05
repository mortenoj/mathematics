#include <math.h>       /* sqrt */
#include <iostream>

class Vector {
public:
    // Values
    float x;
    float y;
    float z;

    // Constructors
    Vector();
    Vector(float x, float y, float z);

    // Operators
    Vector operator *(float s) const;
    Vector operator /(float s) const;
    Vector operator +(const Vector& v) const;
    Vector operator -(const Vector& v) const;

    // Methods
    float length() const;
    float lengthSqr() const;
    Vector normalized() const;
    float dot(const Vector& v) const;
    Vector cross(const Vector& v) const;
    void print() const;

    // Static methods
    static Vector up();
    static Vector down();
    static Vector left();
    static Vector right();
    static Vector forward();
    static Vector backward();
};

// Constructors
Vector::Vector() {}
Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Operators
Vector Vector::operator *(float s) const {
    return Vector(x*s, y*s, z*s);
}

Vector Vector::operator /(float s) const {
    return Vector(x/s, y/s, z/s);
}

Vector Vector::operator +(const Vector& v) const {
    return Vector(
        x + v.x,
        y + v.y,
        z + v.z
    );
}

Vector Vector::operator -(const Vector& v) const {
    return Vector(
        x - v.x,
        y - v.y,
        z - v.z
    );
}

// Methods
float Vector::length() const {
    return sqrt(x*x + y*y + z*z);
}

float Vector::lengthSqr() const {
    return (x*x + y*y + z*z);
}

Vector Vector::normalized() const {
    return (*this) / length();
}

float Vector::dot(const Vector& v) const {
    return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector Vector::cross(const Vector& v) const {
    return Vector(
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x
    );
}

void Vector::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}

// Static methods
Vector Vector::up() { return Vector(0, 1, 0); }
Vector Vector::down() { return Vector(0, -1, 0); }
Vector Vector::left() { return Vector(-1, 0, 0); }
Vector Vector::right() { return Vector(1, 0, 0); }
Vector Vector::forward() { return Vector(0, 0, 1); }
Vector Vector::backward() { return Vector(0, 0, -1); }
