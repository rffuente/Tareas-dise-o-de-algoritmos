#include <stdio.h>
#include <float.h> 
#include <stdlib.h> 
#include <math.h> 
  
// A structure to represent a Point in 2D plane 
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
  
//QUICKSORT

void swap(Point P[], int i, int j) {
    struct Point tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
}

int findPivot (int i, int d) {
    return (i+d)/2;
}

int antesQue(Point p1, Point p2, char type) 
{   
    if(type == 'x')
    {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

int partition (Point *P, int i, int d, int posPivot, char type) {
    do {
        while (antesQue(P[++i], P[posPivot], type));
        while ((i < d) && antesQue(P[posPivot], P[--d], type));
        swap(P, i, d);
    } while (i < d);
    return i; // retorna la primera posición en la partición de la derecha
}

void quickSort (Point *P, int i, int d, char type) {
    int posPivot, k;
    if (d <= i) return; // Arreglo de tamaño 0 o 1, no hace falta ordenar
    posPivot = findPivot(i, d);
    swap(P, posPivot, d); // intercambia pivote con el último elemento
    k = partition(P, i-1, d, d, type);
    swap(P, k, d); // intercambia pivote con primer elemento partición derecha
    quickSort(P, i, k-1, type);
    quickSort(P, k+1, d, type);
}

//BRUTE FORCE

float euclidian_distance(Point p1, Point p2)
{
    return pow((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)), 0.5);
}

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
    //printf("%f %f\n",P[i_min].x, P[i_min].y);
    //printf("%f %f\n",P[j_min].x, P[j_min].y);
    //printf("\n"); 
    p1_p2.p1 = P[i_min];
    p1_p2.p2 = P[j_min];
    p1_p2.distance = euclidian_distance(P[i_min], P[j_min]);
    return p1_p2;
};

P1P2 divide_and_conquer(Point *Px, Point *Py, int n) {
    P1P2 d, d_l, d_r; // Structure to save closest pair

    /* If there is only one point */
    if (n <= 3)
        return closest_distance_brute_force(Px, n); 
        
    /* Compute midpoint */
    int mid = n / 2;
    Point mid_point = Py[mid];

    /* Recursively search closest point in each division */
    d_l = divide_and_conquer(Px, Py, mid);
    d_r = divide_and_conquer(Px + mid, Py + mid, n - mid);

    /* Compare which is the closes pair on point of each division */
    if (d_l.distance < d_r.distance) 
        d = d_l;
    else
        d = d_r;

    /* Search points bewtween division with smaller distance than min distance computed above */
    Point *strip = (Point *) malloc(n * sizeof(Point));
    int k = 0; 
    for (int i = 0; i < n; i++) 
        if (fabs(Py[i].x - mid_point.x) < d.distance) 
            strip[k] = Py[i], k++; 
    
    /* Sort strip points according to y coordinate */
    //quickSort(strip, 0, k - 1, smallY);  

    // Pick all points one by one and try the next points till the difference 
    // between y coordinates is smaller than d. 
    // This is a proven fact that this loop runs at most 6 times
    double dist;
    for (int i = 0; i < k; ++i) {
        for (int j = i+1; j < k && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d.distance * d.distance; ++j) {
            dist = euclidian_distance(strip[i], strip[j]);
            if (dist < d.distance) {
                d.distance = dist;
                d.p1 = strip[i];
                d.p2 = strip[j];
            }
        }
    }

    return d;
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
    quickSort (Px, 0, n-1, 'x');
    quickSort (Py, 0, n-1, 'y');

    //closestUtil(Px, Py, n);
    // Use recursive function closestUtil() to find the smallest distance 
    return divide_and_conquer(Px, Py, n); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int i, a; 
    float x_a, y_a;
    P1P2 p1_p2_1, p1_p2_2 ;
    while(scanf("%d", &a) != EOF) {
        struct Point *P = (struct Point *) malloc(a * sizeof(struct Point));
        for(i=0; i<a; i++){
            scanf("%f %f", &x_a, &y_a);
            P[i].x = x_a;
            P[i].y = y_a;
        }
        p1_p2_1 = closest_distance_brute_force(P, a);
        p1_p2_2 = closest_distance_divide_and_conquer(P, a);
        printf("%f %f\n", p1_p2_1.p1.x, p1_p2_1.p1.y);
        printf("%f %f\n", p1_p2_1.p2.x, p1_p2_1.p2.y); 
        printf("-------------------");
        printf("\n");
        printf("%f %f\n", p1_p2_2.p1.x, p1_p2_2.p1.y);
        printf("%f %f\n", p1_p2_2.p2.x, p1_p2_2.p2.y); 
        free(P);
    }
    return 0; 
} 