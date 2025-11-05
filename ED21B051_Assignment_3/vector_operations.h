#include <math.h>
#include "struct.h"

Vec vecAdd(Vec a, Vec b){
    return (Vec){a.x+b.x, a.y+b.y, a.z+b.z};
};

Vec subtract(Vec a, Vec b){
    return (Vec){a.x-b.x, a.y-b.y, a.z-b.z};
};

Vec cross(Vec a, Vec b){
    return (Vec){
        a.y*b.z - b.y*a.z, 
        a.z*b.x - b.z*a.x, 
        a.x*b.y - a.y*b.x
    };
};

float dot(Vec a, Vec b){
    return (float){a.x*b.x + a.y*b.y + a.z*b.z};
};

int isNonCoplanar(Vec p0, Vec p1, Vec p2, Vec p3){
    // Volume of parallelpiped is non zero
    Vec v1 = subtract(p0, p1);
    Vec v2 = subtract(p0, p2);
    Vec v3 = subtract(p0, p3);

    float vol6 = fabs(dot(v1, cross(v2, v3)));

    return vol6 > 1e-6f;
};

Vec normal(Vec a, Vec b, Vec c){
    return cross(subtract(b,a), subtract(c,a));
};