#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Represents a 3D point
struct Point3D {
    double x, y, z;

    // Constructor
    Point3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
};

// Represents a Cone
class Cone {
private:
    vector<Point3D> vertices;

public:
    Cone(double height, double radius, int segments) {
        for (int i = 0; i < segments; ++i) {
            double theta = (2 * M_PI * i) / segments;
            double x = radius * cos(theta);
            double y = radius * sin(theta);
            vertices.push_back(Point3D(x, y, 0));
        }
        vertices.push_back(Point3D(0, 0, height));
    }

    // Rotate the cone around the z-axis by angle (in radians)
    void rotateZ(double angle) {
        double cosA = cos(angle);
        double sinA = sin(angle);
        for (auto& vertex : vertices) {
            double newX = vertex.x * cosA - vertex.y * sinA;
            double newY = vertex.x * sinA + vertex.y * cosA;
            vertex.x = newX;
            vertex.y = newY;
        }
    }
    void display() const {
        for (auto& vertex : vertices) {
            cout << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")" << endl;
        }
    }
};

int main() {
    Cone myCone(5.0, 2.0, 10);
    cout << "Original Cone:" << endl;
    myCone.display();
    // Rotate the cone around the z-axis by 45 degrees (in radians)
    double angleRadians = M_PI / 4.0;
    myCone.rotateZ(angleRadians);
    cout << "\nRotated Cone:" << endl;
    myCone.display();
    return 0;
}
