#include <math.h>
#include <stdio.h>
typedef struct Point{
    int x;
    int y;
} Point;

typedef struct Triangle{
    Point v1;
    Point v2;
    Point v3;
}Triangle;

double length(Point p1, Point p2){
    double l = sqrt( pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
    return l;
}

double area(Triangle t){
    double s1 = length(t.v1, t.v2);
    double s2 = length(t.v2, t.v3);
    double s3 = length(t.v3, t.v1);

    double S = (s1 + s2 + s3)/2;
    double area = sqrt( S*(S-s1)*(S-s2)*(S-s3) );
    return area;
}

int check(Triangle t, Point p){
    Triangle t1 = {t.v1, t.v2, p};
    Triangle t2 = {t.v2, t.v3, p};
    Triangle t3 = {t.v3, t.v1, p};
    double at  = area(t);
    double at1 = area(t1);
    double at2 = area(t2);
    double at3 = area(t3);

    if((fabs(at - (at1 + at2 + at3)) < 0.01))  // |f1-f2| < 0.01
        return 1;
    else
        return 0;
}

int main(){
    Triangle t = {{0,0},{3,0},{0,4}};
    Point p = {0,5};
    double a = area(t);
    printf("%d\n", check(t,p));
}