#include <GLUT/glut.h>
#include <OpenGL/gl.h>

//Camera Parameters (Deg)
float camYaw = 0.0f;
float camPitch = 0.0f;
float camRadius = 3.0f;

void specialKeys(int key, int x, int y){
    float angleStep = 3.0f;
    switch (key){
        case GLUT_KEY_LEFT:
            camYaw -= angleStep;
            // if (camYaw <= -89){camYaw = -89;};
            break;
        case GLUT_KEY_RIGHT:
            camYaw += angleStep;
            // if (camYaw >= 89){camYaw = 89;};
            break;
        case GLUT_KEY_UP:
            camPitch += angleStep;
            if (camPitch >= 89){camPitch = 89;};
            break;
            // max_index += 1;
            // if (max_index >= 20){max_index = 20;};
            // break;
        case GLUT_KEY_DOWN:
            camPitch -= angleStep;
            if (camPitch <= -89){camPitch = -89;};
            break;
            // max_index -= 1;
            // if (max_index <=0){max_index = 0;};
            // break;

    }
    glutPostRedisplay();
};

void init(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 0.1, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,3, 0,0,0, 0,1,0);

};
