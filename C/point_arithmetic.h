#include <stdio.h>
#include <math.h>
#include "structs.h"


Point midpoint(Point a, Point b){
    Point m;
    m.x = (a.x + b.x)*0.5f;
    m.y = (a.y + b.y)*0.5f;
    return m;
}

void perpendicular_bisector(Point a, Point b, double* A, double* B, double* C){

    Point m = midpoint(a, b);

    double dy = b.y - a.y;
    double dx = b.x - a.x;
    
    *A = dx;
    *B = dy;

    *C = -((*A) * m.x + (*B) * m.y);
}

void line_segment(double A, double B, double C, Point* p1, Point* p2){

    double x1, y1, x2, y2;

    if (B != 0){
        x1 = -1.0;
        x2 = 1.0;
        y1 = (-C - x1 * A)/B;
        y2 = (-C - x2 * A)/B;
    }
    else{
        // Vertical line, x = constant
        x1 = x2 = - C/A;
        y1 = -1.0;
        y2 = 1.0;
    }

    p1->x = x1; p1->y = y1;
    p2->x = x2; p2->y = y2;

}