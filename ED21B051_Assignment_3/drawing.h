#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <struct.h>

void draw_face(Vec* points, Face face){

        Vec A = points[face.a];
        Vec B = points[face.b];
        Vec C = points[face.c];
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glColor4f(0.2f,0.7f,0.2f, 0.7f);

        glBegin(GL_TRIANGLES);

        glVertex3f(A.x, A.y, A.z);
        glVertex3f(B.x, B.y, B.z);
        glVertex3f(C.x, C.y, C.z);

        glEnd();

        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);

        glLineWidth(2.0f);
        glColor4f(0.0f,1.0f,0.0f, 0.2f);

        glBegin(GL_LINES);

        glVertex3f(A.x, A.y, A.z);
        glVertex3f(B.x, B.y, B.z);

        glVertex3f(A.x, A.y, A.z);
        glVertex3f(C.x, C.y, C.z);

        glVertex3f(B.x, B.y, B.z);
        glVertex3f(C.x, C.y, C.z);

        glEnd();

};