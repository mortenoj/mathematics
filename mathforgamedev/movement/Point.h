class Point {
public:
    // Values
    float x;
    float y;
    float z;

    // Constructors
    Point(float x, float y, float z);
    Point();

    // Operators
    Vector operator-(Point a);

    // Methods
    Point addVector(Vector v);
};

Point::Point() {

}

Point::Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Operator overloading
Vector Point::operator-(Point a) {
    return Vector(
        x - a.x,
        y - a.y,
        z - a.z
    );
}

// Methods
Point Point::addVector(Vector v) {
    return Point(
        x + v.x,
        y + v.y,
        z + v.z
    );
}