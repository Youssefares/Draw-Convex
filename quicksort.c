// quickSort.c
#include "quicksort.h"


void quickSort(Point a[], int l, int r)
{
   int j;

   if( l < r )
   {
   	// divide and conquer
       j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }

}



int partition(Point a[], int l, int r){
   double pivot;
   int i, j;
   pivot = a[l].p;
   i = l; j = r+1;

   while( 1){
   	do ++i; while( a[i].p <= pivot && i <= r );
   	do --j; while( a[j].p > pivot );
   	if( i >= j ) break;
   	swap(&a[i],&a[j]);
   }
   swap(&a[l],&a[j]);
   return j;
}

void swap(Point* a,Point* b){
    double t = a->y; a->y = b->y; b->y = t;
    t = a->x; a->x = b->x; b->x = t;
    t = a->p; a->p = b->p; b->p = t;
}
