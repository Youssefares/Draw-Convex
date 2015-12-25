
#include "GrahamScan.h"
Stack* top = NULL;

/**Stack Operations**/
void Push(Point n){
    Stack* newTop = (Stack*)malloc(sizeof(Stack));
    if(newTop == NULL)
        return;
    newTop->p = n;
    newTop->next = top;
    top = newTop;
    return;
}

Point Pop(){
    Stack* doomed = top;
    Point p = top->p;
    top = top->next;
    free(doomed);
    return p;
}

Point Peek(){
    if(top == NULL){
    //bad luck
       Point ending = {-13,-13};
       return ending;
    }
    return top->p;
}


void traverse(){
    Stack* traversor;
    for(traversor = top; traversor != NULL; traversor = traversor->next)
        printP(traversor->p);
}



/*******
   prints the point as (x,y)
**/

void printP(Point p){
    printf("(%.2f,%.2f)",p.x,p.y);
}

/*********
  calculates the polar angle difference between 2 points
**/
double polarangle(Point a, Point b){
    double x = a.x-b.x;
    double y = a.y-b.y;
    //less than 90
    if(x > 0)
        return atan(y/x)*180/3.14;
    if(x == 0)
        return 90;
    else
        return 180 +atan(y/x)*180/3.14;
    
}

/********
  Return 1 if the three points make a Counter-Clock-Wise Turn, -1 if Clock-wise &
  0 if the three points are collinear.
  This uses Signed area and the determinant of slopes.
**/
int ccw(Point a, Point b, Point c){
    double area = 0.5*((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x));
    if (area < 0)       return  1; //clockwise
    else if (area > 0)  return  -1; //counterclockwise
    else                return  0; // linear
}
