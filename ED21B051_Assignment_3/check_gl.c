#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void display(void){
    const unsigned char *ver = glGetString(GL_VERSION);
    const unsigned char *renderer = glGetString(GL_RENDERER);
    const unsigned char *glsl = glGetString(GL_SHADING_LANGUAGE_VERSION);
    printf("OpenGL version: %s\n", ver ? ver : (const unsigned char*)"(none)");
    printf("Renderer      : %s\n", renderer ? renderer : (const unsigned char*)"(none)");
    printf("GLSL version  : %s\n", glsl ? glsl : (const unsigned char*)"(none)");
    fflush(stdout);

    exit(0);
};

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(64, 64);
    glutCreateWindow("OpenGL version check");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
};