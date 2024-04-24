#include <graphics.h>
#include <iostream>
using namespace std;

// Rectangle Regions
int xmin = 300;
int ymin = 300;
int xmax = 700;
int ymax = 700;

// Liang-Barsky line clipping algorithm
void liangBarsky(int x1, int y1, int x2, int y2) {
    int p[4], q[4];
    float t1 = 0, t2 = 1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int k;

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            cout << "Line is parallel to clipping window and outside\n";
            return;
        }
        if (p[i] != 0) {
            float t = (float)q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) t1 = t;
            } else {
                if (t < t2) t2 = t;
            }
        }
    }

    if (t1 > t2) {
        cout << "Line lies completely outside the clipping window\n";
        return;
    }

    int x_start = x1 + t1 * dx;
    int y_start = y1 + t1 * dy;
    int x_end = x1 + t2 * dx;
    int y_end = y1 + t2 * dy;

    line(x_start, y_start, x_end, y_end);
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
    rectangle(xmin, ymax, xmax, ymin);


    // Intersect the box (Partially Clipped)
    liangBarsky(150, 250, 400, 600);
    liangBarsky(250, 300, 500, 550);
    liangBarsky(500, 250, 550, 550);

    // Inside the box (Not Clipped)
    liangBarsky(350, 450, 600, 500);

    // Outside the box (Fully Clipped)
    liangBarsky(710, 450, 750, 750);
    
    getch();
    closegraph();

    return 0;
}