#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <time.h>
#include <math.h>
#include "vector_operations.h"
#include <struct.h>
#include "camera.h"
#include "drawing.h"

#define NUM_POINTS 100
#define PI 3.14159265359f

Vec points[NUM_POINTS];

int dead[NUM_POINTS][NUM_POINTS];

Face faces[NUM_POINTS * 6];
int face_count = 0;

void generatePoints(){
    srand(1234);
    for(int i = 0; i < NUM_POINTS; i++){
        points[i].x = ((float)rand() / RAND_MAX) * 2 - 1;
        points[i].y = ((float)rand() / RAND_MAX) * 2 - 1;
        points[i].z = ((float)rand() / RAND_MAX) * 2 - 1;
    };
};

void add_face(int a, int b, int c){
    faces[face_count].a = a;
    faces[face_count].b = b;
    faces[face_count].c = c;

    faces[face_count].n = normal(points[a],points[b], points[c]);

    dead[a][b] = dead[b][c] = dead[c][a] = 0; //Declare these edges as not removed
    face_count += 1;
}


void ConvexHull3D(){
    // Initalize dead matrix
    for(int i=0;i<NUM_POINTS;i++){
        for(int j=0;j<NUM_POINTS;j++){
            dead[i][j] = 0;
        }
    }

    // Create the seed faces with oposide edge cycles
    add_face(0,1,2);
    add_face(0,2,1);

    // Iterate over all other vertices
    for(int i=3;i<NUM_POINTS;i++){
        // Collect non-visible faces
        Face f2[NUM_POINTS * 3];

        // Count of all non-visible faces
        int f2_count = 0;

        for (int j=0; j<face_count;j++){
            Vec diff = subtract(points[i], points[faces[j].a]);

            // If face is visible
            if (dot(diff, faces[j].n) > 1e-6){
                // Declare the clockwise edges of the face to be dead
                dead[faces[j].a][faces[j].b] = 1;
                dead[faces[j].b][faces[j].c] = 1;
                dead[faces[j].c][faces[j].a] = 1;
            }
            //If face is not visible, add it to temporary f2_count as it is still a hull face
            else{
                f2[f2_count] = faces[j];
                f2_count+=1;
            }
        }

        // Add faces from exposed edges and rebuild hull
        face_count = 0;
        for (int j=0; j<f2_count; j++){
            int vertices[3] = {f2[j].a, f2[j].b, f2[j].c};
            // Iterate over each edge in the current face in f2
            for (int k=0; k < 3; k++){
                int a = vertices[k];
                int b = vertices[(k+1)%3];
                if (dead[b][a]){
                    add_face(b, a, i);
                }
            }
        }
        // Overrite previous array of faces
        for (int j=0; j < f2_count; j++){
            faces[face_count] = f2[j];
            face_count +=1;
        }
    }
};

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Camera orientations
    float yawRad = camYaw * PI / 180.0f;
    float pitchRad = camPitch * PI/180.0f;

    //Camera position in Cartesian coordinates
    float camX = camRadius * cosf(pitchRad) * cosf(yawRad);
    float camY = camRadius * sinf(pitchRad);
    float camZ = camRadius * cosf(pitchRad) * sinf(-yawRad);

    gluLookAt(camX, camY, camZ, 0,0,0, 0,1,0);

    //Draw the vertices of the point cloud
    glPointSize(7.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < NUM_POINTS; i ++){
        glColor4f(0.0f,0.0f,0.0f,1.0f);
        glVertex3f(points[i].x, points[i].y, points[i].z);
    };

    // An OpenGL rendering error requires us to render the first face twice, not sure why.
    draw_face(points, faces[0]);
    //Draw the faces of the convex hull
    for (int i=0; i < face_count; i++){
        draw_face(points, faces[i]);
    };

    glEnd();
    glutSwapBuffers();

};

int main(int argc, char **argv){
    
    srand((unsigned int)time(NULL));
    generatePoints();
    ConvexHull3D();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Point Viewer");
    
    init();


    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
};