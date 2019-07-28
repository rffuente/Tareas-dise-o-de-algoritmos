#ifndef functions_h
#define functions_h

typedef struct Point 
{ 
    float x, y; 
}Point;

typedef struct P1P2 
{ 
    struct Point p1;
    struct Point p2;
    float distance;
}P1P2; 

//QUICKSORT ALGORITHM
void swap(Point P[], int i, int j);
int findPivot (int i, int d);
int antesQue(Point p1, Point p2, char type);
int partition (Point *P, int i, int d, int posPivot, char type);
void quickSort (Point *P, int i, int d, char type);
//BRUTE FORCE
float euclidian_distance(Point p1, Point p2);
P1P2 closest_distance_brute_force(Point *P, int n);
//DIVIDE AND CONQUER
P1P2 divide_and_conquer(Point *Px, Point *Py, int n);
P1P2 closest_distance_divide_and_conquer(Point *P, int n);
#endif 