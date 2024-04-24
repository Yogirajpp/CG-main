#include <GL/glut.h>
#include <cmath>

const int slices = 30;
const float radius = 1.0f;
const float height = 2.0f;

void drawCylinder() {
    // Draw top circle
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color for top face
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, height, 0.0f); // Center of top circle
    for (int i = 0; i <= slices; ++i) {
        float theta = (2.0f * M_PI * static_cast<float>(i)) / slices;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        glVertex3f(x, height, z); // Vertex of top circle
    }
    glEnd();

    // Draw bottom circle
    glColor3f(0.0f, 1.0f, 0.0f); // Green color for bottom face
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); // Center of bottom circle
    for (int i = slices; i >= 0; --i) {
        float theta = (2.0f * M_PI * static_cast<float>(i)) / slices;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        glVertex3f(x, 0.0f, z); // Vertex of bottom circle
    }
    glEnd();

    // Draw side faces
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for side faces
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; ++i) {
        float theta = (2.0f * M_PI * static_cast<float>(i)) / slices;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        glVertex3f(x, height, z); // Vertex of top circle
        glVertex3f(x, 0.0f, z);   // Vertex of bottom circle
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Set the camera position

    // Draw the cylinder
    drawCylinder();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cylinder");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
