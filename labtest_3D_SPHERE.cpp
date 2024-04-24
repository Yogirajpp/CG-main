#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset the modelview matrix

    // Set up the camera
    gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0); // eye, center, up vector

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat lightPosition[] = {1.0, 1.0, 1.0, 0.0}; // Directional light from the top-right
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    GLfloat sphereColor[] = {0.0, 1.0, 0.0, 1.0}; // Green color for the sphere
    glMaterialfv(GL_FRONT, GL_DIFFUSE, sphereColor);

    const int slices = 30; // Number of longitude divisions
    const int stacks = 30; // Number of latitude divisions
    const float radius = 1.0; // Radius of the sphere

    for (int i = 0; i < slices; ++i) {
        float theta1 = i * (2.0 * M_PI) / slices;
        float theta2 = (i + 1) * (2.0 * M_PI) / slices;
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= stacks; ++j) {
            float phi = j * M_PI / stacks;
            float x1 = radius * cos(theta1) * sin(phi);
            float y1 = radius * sin(theta1) * sin(phi);
            float z1 = radius * cos(phi);
            float x2 = radius * cos(theta2) * sin(phi);
            float y2 = radius * sin(theta2) * sin(phi);
            float z2 = radius * cos(phi);
            glNormal3f(x1, y1, z1);
            glVertex3f(x1, y1, z1);
            glNormal3f(x2, y2, z2);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }

    glDisable(GL_LIGHTING);

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Sphere Example");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
