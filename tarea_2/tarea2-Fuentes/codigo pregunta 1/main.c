#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) 
{
    int i, a; 
    float x_a, y_a;
    P1P2 p1_p2;
    struct Point *P;
    if(atoi(argv[1]) == 1)
    {
        printf("Fuerza Bruta: \n");
    }
    else
    {
        printf("Dividir, Conquistar y Combinar: \n");
    }
    while(scanf("%d", &a) != EOF) {
        P = (struct Point *) malloc(a * sizeof(struct Point));
        for(i=0; i<a; i++){
            scanf("%f %f", &x_a, &y_a);
            P[i].x = x_a;
            P[i].y = y_a;
        }
        if(atoi(argv[1]) == 1)
        {
            p1_p2 = closest_distance_brute_force(P, a);
        }
        else
        {
            p1_p2 = closest_distance_divide_and_conquer(P, a);
        }
        printf("%f %f\n", p1_p2.p1.x, p1_p2.p1.y);
        printf("%f %f\n", p1_p2.p2.x, p1_p2.p2.y); 
        printf("\n");
        free(P);
    }
    return 0;
}