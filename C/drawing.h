#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void draw_rectangle(double x1, double y1, double x2, double y2, double r, double g, double b){
    glColor3d(r, g, b);
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x2, y1);
    glVertex2d(x2, y2);
    glVertex2d(x1, y2);
    glEnd();
}

void drawRoad(){
    double grassWidth = 0.2;
    double whiteLineWidth = 0.1;
    // Draw Grass
    draw_rectangle(-1,-1,1,-1+grassWidth,0.3, 0.6, 0.0);
    draw_rectangle(-1,1,1,1-grassWidth,0.3, 0.6, 0.0);

    // Draw Road
    draw_rectangle(-1,-1+grassWidth,1,1-grassWidth,0.3, 0.3, 0.3);

    // Draw Borders
    draw_rectangle(-1, -1+grassWidth-whiteLineWidth/2, 1, -1+grassWidth+whiteLineWidth/2, 0.9, 0.9, 0.9);
    draw_rectangle(-1, 1-grassWidth+whiteLineWidth/2, 1, 1-grassWidth-whiteLineWidth/2, 0.9, 0.9, 0.9);

    //Draw middle dividers

    //TODO: Need broken dividers and not solid, so that they can move across the screen
    draw_rectangle(-1, whiteLineWidth/2, 1, whiteLineWidth/4, 0.9, 0.9, 0.9);
    draw_rectangle(-1, -whiteLineWidth/2, 1, -whiteLineWidth/4, 0.9, 0.9, 0.9);


}