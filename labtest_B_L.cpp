#include <iostream>
#include <graphics.h>

// Function to implement Bresenham's line drawing algorithm
void drawLineBresenham(int x1, int y1, int x2, int y2) {
    // Calculate differences in x and y
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Determine the sign of increments for x and y
    int signX = (x1 < x2) ? 1 : -1;
    int signY = (y1 < y2) ? 1 : -1;

    // Initialize decision parameters for the algorithm
    int decision = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);

    // Initialize graphics
    initwindow(800, 800, "Bresenham's Line Drawing Algorithm");

    // Start plotting points
    int x = x1;
    int y = y1;

    putpixel(x, y, WHITE);

    while (x != x2 || y != y2) {
        if (decision > 0) {
            decision += twoDyMinusDx;
            x += signX;
            y += signY;
        } else {
            decision += twoDy;
            x += signX;
        }

        // Draw a pixel at the current coordinates
        putpixel(x, y, WHITE);
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

    // Call the Bresenham function to draw the line
    drawLineBresenham(x1, y1, x2, y2);

    return 0;
}
