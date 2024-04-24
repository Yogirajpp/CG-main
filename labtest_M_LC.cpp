#include <iostream>
#include <graphics.h>
#include<cmath>

using namespace std;

// Define region codes for different areas
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define window boundaries
const int xLeft = 300;
const int xRight = 700;
const int yTop = 300;
const int yBottom = 700;

//Compute Region
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xLeft)     // Left
        code |= LEFT;
    else if (x > xRight) // Right
        code |= RIGHT;
    if (y < yTop)      // Above
        code |= TOP;
    else if (y > yBottom) // Below
        code |= BOTTOM;

    return code;
}

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;


    int steps = std::max(std::abs(dx), std::abs(dy));


    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    float x = x1;
    float y = y1;

    for (int i = 1; i <= steps; i++) {
        x += xIncrement;
        y += yIncrement;

        putpixel(round(x), round(y), GREEN);
    }
}

// Cohen–Sutherland clipping algorithm
void clipLine(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true) {
        if (code1 == 0 && code2 == 0) { // Both endpoints lie within rectangle
            accept = true;
            break;
        } else if (code1 & code2) { // Both endpoints are outside rectangle
            break;
        } else {
            int x, y;
            
            int codeOut = code1 ? code1 : code2;

            // Find intersection point
            if (codeOut & TOP) {           // Point is above box
                x = x1 + (x2 - x1) * (yTop - y1) / (y2 - y1);
                y = yTop;
            } else if (codeOut & BOTTOM) { // Point is below box
                x = x1 + (x2 - x1) * (yBottom - y1) / (y2 - y1);
                y = yBottom;
            } else if (codeOut & RIGHT) {  // Point is to the right of box
                y = y1 + (y2 - y1) * (xRight - x1) / (x2 - x1);
                x = xRight;
            } else if (codeOut & LEFT) {   // Point is to the left of box
                y = y1 + (y2 - y1) * (xLeft - x1) / (x2 - x1);
                x = xLeft;
            }

            // Replace point outside the rectangle by intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Drawing the line
        drawLineDDA(x1, y1, x2, y2);
    }
}

int main() {
    initwindow(1000, 1000, "Line Clipping Algo");

    // // Intersect the box (Partially Clipped)
    // drawLineDDA(150, 250, 400, 600);
    // drawLineDDA(250, 300, 500, 550);
    // drawLineDDA(500, 250, 550, 550);

    // // Inside the box (Not Clipped)
    // drawLineDDA(350, 450, 600, 500);

    // // Outside the box (Fully Clipped)
    // drawLineDDA(710, 450, 750, 750);

    // Bounding box
    rectangle(xLeft, yTop, xRight, yBottom);


    // Intersect the box (Partially Clipped)
    clipLine(150, 250, 400, 600);
    clipLine(250, 300, 500, 550);
    clipLine(500, 250, 550, 550);

    // Inside the box (Not Clipped)
    clipLine(350, 450, 600, 500);

    // Outside the box (Fully Clipped)
    clipLine(710, 450, 750, 750);
    
    getch();
    closegraph();

    return 0;
}