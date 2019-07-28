#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//STRUCTS
//Point x,y
typedef struct Point 
{ 
    float x, y; 
}Point;

//Struct for save the closest points and his distance
typedef struct P1P2 
{ 
    struct Point p1;
    struct Point p2;
    float distance;
}P1P2; 
  
//QUICKSORT IMPLEMENTATION

void swap(Point P[], int i, int j) {
    struct Point tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
};

int findPivot (int i, int d) {
    return (i+d)/2;
};

int antesQue(Point p1, Point p2, char type) 
{   
    if(type == 'x')
    {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
};

int partition (Point *P, int i, int d, int posPivot, char type) {
    do {
        while (antesQue(P[++i], P[posPivot], type));
        while ((i < d) && antesQue(P[posPivot], P[--d], type));
        swap(P, i, d);
    } while (i < d);
    return i; 
};

void quickSort (Point *P, int i, int d, char type) {
    int posPivot, k;
    if (d <= i) return; 
    posPivot = findPivot(i, d);
    swap(P, posPivot, d); 
    k = partition(P, i-1, d, d, type);
    swap(P, k, d); 
    quickSort(P, i, k-1, type);
    quickSort(P, k+1, d, type);
};
//------------------------------------------------//

//BRUTE FORCE

float euclidian_distance(Point p1, Point p2)
{
    return pow((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)), 0.5);
};

P1P2 closest_distance_brute_force(Point *P, int n)
{
    int i, j, i_min=0, j_min=0;
    float dist, aux;
    P1P2 p1_p2;
    for (i = 0; i < n; ++i)
    {  
        for (j = i+1; j < n; j++)
        {
            if(i_min == 0 && j_min == 0)
            {
                dist = euclidian_distance(P[i], P[j]);
                i_min = i;
                j_min = j;
            }
            else
            {
                aux = euclidian_distance(P[i], P[j]);
                if(aux < dist)
                {
                    dist = aux;
                    i_min = i;
                    j_min = j;
                }
            }
        } 
    }
    p1_p2.p1 = P[i_min];
    p1_p2.p2 = P[j_min];
    p1_p2.distance = euclidian_distance(P[i_min], P[j_min]);
    return p1_p2;
};

//DIVIDE AND CONQUER

P1P2 divide_and_conquer(Point *Px, Point *Py, int n) {
    P1P2 p1_p2, p1_p2l, p1_p2r; 

    if (n <= 3)
    {
        return closest_distance_brute_force(Px, n); 
    }
        
    int mid = n / 2;
    Point mid_point = Px[mid];

    Point Pyl[n]; 
    Point Pyr[n]; 
    int i, l = 0, r = 0; 
    for (i = 0; i < n; i++) 
    { 
        if (Py[i].x <= mid_point.x)
        {
            Pyl[l++] = Py[i]; 
        }
        else
        {
            Pyr[r++] = Py[i]; 
        }
    }

    p1_p2l = divide_and_conquer(Px, Pyl, mid);
    p1_p2r = divide_and_conquer(Px + mid, Pyr, n - mid);

    if (p1_p2l.distance < p1_p2r.distance) 
    {
        p1_p2 = p1_p2l;
    }
    else
    {
        p1_p2 = p1_p2r;
    }

    Point *strip = (Point *) malloc(n * sizeof(Point));

    int k = 0; 
    for (i = 0; i < n; i++) 
    {
        if (fabs(Py[i].x - mid_point.x) < p1_p2.distance) 
        {
            strip[k] = Py[i];
            k++; 
        }
    }

    float dist;
    int j;
    for (i = 0; i < k; ++i) {
        for (j = i+1; j < k && fabs(strip[j].y - strip[i].y) < p1_p2.distance; ++j) {
            dist = euclidian_distance(strip[i], strip[j]);
            if (dist < p1_p2.distance) {
                p1_p2.distance = dist;
                p1_p2.p1 = strip[i];
                p1_p2.p2 = strip[j];
            }
        }
    }
    free(strip);
    return p1_p2;
}

P1P2 closest_distance_divide_and_conquer(Point *P, int n) 
{ 
    Point *Px; 
    Point *Py; 
    int i;

    Px = (Point *) malloc(n * sizeof(Point));
    Py = (Point *) malloc(n * sizeof(Point));

    for (i = 0; i < n; i++) 
    { 
        Px[i] = P[i]; 
        Py[i] = P[i]; 
    } 
    quickSort(Px, 0, n-1, 'x');
    quickSort(Py, 0, n-1, 'y');

    return divide_and_conquer(Px, Py, n); 
} 