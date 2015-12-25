#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quicksort.h"

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gtypes.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of Hull's window in pixels
#define HEIGHT 1200
#define WIDTH 1200

int main(void){
   int n;
   scanf("%i",&n);
   printf("draw %i points.\n",n);
   GWindow window = newGWindow(WIDTH, HEIGHT);
   Point points[n];
   GOval actualPoints[n];
   Point leastY;
   int index;
   for(int i = 0;i < n;i++){
       GWindowEvent newPoint = waitForEvent(MOUSE_EVENT);
       EventType type = getEventType(newPoint);
       if(type == MOUSE_PRESSED){
           double x = getX(newPoint);
           double y = getY(newPoint);
           points[i].x = x;
           points[i].y = y;
           actualPoints[i] = newGOval(x,y,4,4);
           add(window,actualPoints[i]);
           if(i == 0){
                leastY = points[i];
                index = i;
            }
            else if(points[i].y < leastY.y || (points[i].y == leastY.y  && points[i].x > leastY.x)){
                leastY = points[i];
                index = i;
            }
       }
       else i--;
   }
   points[index].p = 0;
   if(index != 0) swap(&points[index],&points[0]);
   for(int i = 1;i< n;i++)
       points[i].p = polarangle(points[i],leastY);
   quickSort(points,0,n-1);
   Push(points[0]);
   Push(points[1]);
   Push(points[2]);
   for(int i = 3; i < n;i++){
        Point topone = Pop();
        // discarding points with clockwise turns
        while(ccw(Peek(),topone,points[i]) != -1)
            topone = Pop();
        Push(topone);
        Push(points[i]);
   }
   //traverse();
   GLabel label;
      double x, y;
      label = newGLabel("Your Convex Hull!");
      setFont(label, "SansSerif-18");
      x = (getWidth(window) - getWidth(label)) / 2;
      y = (getHeight(window) + getFontAscent(label)) / 2 +300;
      setLocation(label, x, y);
      add(window, label);
   Point first = Peek();
   Point startp, endp;
   while(Peek().x != -13){
       startp = Pop();
       endp = Peek();
       if(Peek().x < 0) break;
       GLine line = newGLine(startp.x+2, startp.y+2, endp.x+2, endp.y+2);
       setColor(line,"RED");
       add(window,line);
       pause(30);
   }
   GLine backhome = newGLine(startp.x+2, startp.y+2, first.x+2, first.y+2);
   setColor(backhome,"RED");
   add(window,backhome);
   pause(1000);
   while(true){
      GWindowEvent close = waitForEvent(KEY_EVENT);
      EventType type = getEventType(close);
       if(type == KEY_TYPED){
           closeGWindow(window);
           break;
       }
   }
   return 0;
}
