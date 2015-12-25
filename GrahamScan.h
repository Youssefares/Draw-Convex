#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Cartesian point
typedef struct{
    double x;
    double y;
    double p;
}Point;

//Linked-List LIFO Stack
typedef struct Stack{
    Point p;
    struct Stack* next;
}Stack;


//stack operations
void Push(Point);
Point Peek();
Point Pop();
void traverse();
void printP(Point);

//get polar co-ordinates
double polarangle(Point,Point);
int ccw(Point,Point,Point);
