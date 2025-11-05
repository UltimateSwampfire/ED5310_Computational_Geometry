#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include "point_arithmetic.h"
#include "drawing.h"


const int NUM_POINTS = 5;
Point random_points[NUM_POINTS];

void generate_random_points(Point* random_points, int NUM_POINTS){
    srand(time(NULL));
    for (int i=0; i<NUM_POINTS;i++){
        random_points[i].x = (float)rand()/RAND_MAX * 2.0 - 1.0;
        random_points[i].y = (float)rand()/RAND_MAX * 2.0 - 1.0;
    }
}

void fortune_algorithm(Point* random_points, double sweep_y){
    
}


void display(){
    // TODO: Need to clarify what buffers are and why they are used
    glClear(GL_COLOR_BUFFER_BIT);
    // drawRoad();


    // Draw all perpendicular bisectors
    glColor3d(0.3, 0.3, 1.0);
    glLineWidth(1.0f);
    for (int i=0; i<NUM_POINTS-1; i++){
        for (int j=i+1; j<NUM_POINTS; j++){
            double A, B, C;
            perpendicular_bisector(random_points[i],random_points[j], &A, &B, &C);

            Point s1, s2;
            line_segment(A, B, C, &s1, &s2);

            glBegin(GL_LINES);
                glVertex2d(s1.x, s1.y);
                glVertex2d(s2.x, s2.y);
            glEnd();
        }
    }

    // Draw random points
    glPointSize(6.0f);
    glBegin(GL_POINTS);
    glClearColor(0, 0, 0, 1.0);
    glColor3f(1.0f, 1.0f, 0.0f);
    for (int i=0; i < NUM_POINTS; i++){
        glVertex2d(random_points[i].x, random_points[i].y);
    };
    glEnd();


    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    if (key == 'r'){
        generate_random_points(random_points, NUM_POINTS);
        //TODO: Check what this function does, some kind of 'refresh' button perhaps?
        glutPostRedisplay();
    }
}

int main(int argc, char ** argv){
    printf("I am Malenia, Blade of Miquella. And I have never known defeat.\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Generate Random Points");

    generate_random_points(random_points, NUM_POINTS);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}