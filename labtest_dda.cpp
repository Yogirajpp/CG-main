#include <iostream>
#include <graphics.h>
#include<cmath>

// Function to implement DDA algorithm for line generation
void drawLineDDA(int x1, int y1, int x2, int y2) {
    // Calculate the differences in x and y
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate the number of steps to be taken for generating the line
    int steps = std::max(std::abs(dx), std::abs(dy));

    // Calculate the increment in x and y for each step
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    // Initialize graphics
    initwindow(800, 800, "DDA Line Drawing Algorithm");

    // Initial coordinates
    float x = x1;
    float y = y1;

    // Draw the line using DDA algorithm
    for (int i = 1; i <= steps; i++) {
        x += xIncrement;
        y += yIncrement;

        // Draw a pixel at the current coordinates
        putpixel(round(x), round(y), WHITE);
    }

    // Wait for a key press before closing the window
    getch();
    closegraph();
}

int main() {
    // Example usage
    int x1, y1, x2, y2;
    x1 = 250, y1 = 300;
    x2 = 500, y2 = 550;

    // Call the DDA function to draw the line
    drawLineDDA(x1, y1, x2, y2);

    return 0;
}
