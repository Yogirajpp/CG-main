#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point3D {
    double x, y, z;
    Point3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
};

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
        vertices.push_back(Point3D(0, 0, height)); // Apex of the cone
    }

    // Scale the cone along x, y, and z axes
    void scale(double sx, double sy, double sz) {
        for (auto& vertex : vertices) {
            vertex.x *= sx;
            vertex.y *= sy;
            vertex.z *= sz;
        }
    }
    void display() const {
        for (const auto& vertex : vertices) {
            cout << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")" << endl;
        }
    }
};

int main() {
    Cone myCone(5.0, 2.0, 10);
    cout << "Original Cone:" << endl;
    myCone.display();
    myCone.scale(2.0, 3.0, 4.0);
    cout << "\nScaled Cone:" << endl;
    myCone.display();

    return 0;
}
