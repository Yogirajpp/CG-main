#include <iostream>
#include <cmath>

struct Point {
    float x;
    float y;
};

class Transformations2D {
public:
    // Translate points by (tx, ty)
    static void translate(Point& point, float tx, float ty) {
        point.x += tx;
        point.y += ty;
        std::cout << "Translation Matrix:\n";
        std::cout << "1 0 " << tx << "\n";
        std::cout << "0 1 " << ty << "\n";
        std::cout << "0 0 1\n";
    }

    // Scale points by (sx, sy)
    static void scale(Point& point, float sx, float sy) {
        point.x *= sx;
        point.y *= sy;
        std::cout << "Scaling Matrix:\n";
        std::cout << sx << " 0 0\n";
        std::cout << "0 " << sy << " 0\n";
        std::cout << "0 0 1\n";
    }

    // Rotate points by an angle (in degrees) around the arbitrary point
    static void rotate(Point& point, float angle, const Point& center) {
        float radians = angle * M_PI / 180.0;
        float x = point.x - center.x;
        float y = point.y - center.y;
        point.x = center.x + (x * cos(radians) - y * sin(radians));
        point.y = center.y + (x * sin(radians) + y * cos(radians));
        std::cout << "Rotation Matrix:\n";
        std::cout << cos(radians) << " " << -sin(radians) << " 0\n";
        std::cout << sin(radians) << " " << cos(radians) << " 0\n";
        std::cout << "0 0 1\n";
    }
};

int main() {
    // Triangle points
    Point points[] = { {3, 5}, {4, 5}, {9, 8} };
    const int numPoints = sizeof(points) / sizeof(points[0]);

    // Arbitrary rotation center
    Point rotationCenter = { 10, 7 };

    // Translation amounts
    float tx = 5, ty = 6;

    // Scaling factors
    float sx = 5, sy = 7;

    // Rotation angle
    float angle = -60; // clockwise

    std::cout << "Original Triangle:\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    }
    std::cout << "\n";

    std::cout << "Arbitrary Rotation Center: (" << rotationCenter.x << ", " << rotationCenter.y << ")\n";
    std::cout << "\n";

    // Apply scaling transformation
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Scaling for Point " << i + 1 << ":\n";
        Transformations2D::scale(points[i], sx, sy);
        std::cout << "\n";
    }

    // Apply rotation transformation
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Rotation for Point " << i + 1 << ":\n";
        Transformations2D::rotate(points[i], angle, rotationCenter);
        std::cout << "\n";
    }

    // Apply translation transformation
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Translation for Point " << i + 1 << ":\n";
        Transformations2D::translate(points[i], tx, ty);
        std::cout << "\n";
    }

    std::cout << "Transformed Triangle:\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    }

    return 0;
}