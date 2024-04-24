#include <graphics.h>
#include <math.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int rx2 = rx * rx, ry2 = ry * ry;
    int p, px = 0, py = 2 * rx2 * y;

    // Region 1
    p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        px += 2 * ry2;
        if (p < 0)
            p += ry2 + px;
        else {
            y--;
            py -= 2 * rx2;
            p += ry2 + px - py;
        }
    }

    // Region 2
    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        py -= 2 * rx2;
        if (p > 0)
            p += rx2 - py;
        else {
            x++;
            px += 2 * ry2;
            p += rx2 - py + px;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Center and radius of the ellipse
    int xc = 320, yc = 240, rx = 150, ry = 100;

    // Draw the ellipse
    drawEllipse(xc, yc, ry, rx);

    getch();
    closegraph();
    return 0;
}
