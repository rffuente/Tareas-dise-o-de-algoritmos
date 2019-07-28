#include <stdio.h>
#include <stdlib.h>

struct Point 
{ 
    int x;
    int y; 
};

int main() 
{
    int i,a,x_a, y_a;
    while(scanf("%d", &a) != EOF) {
        //printf("%d\n", p);
        struct Point *P = (struct Point *) malloc(a * sizeof(struct Point));
        for(i=0; i<a; i++){
            scanf("%d %d", &x_a, &y_a);
            P[i].x = x_a;
            P[i].y = y_a;
        }
        for(i = 0; i < a; i++){
            printf("%d - %d\n", P[i].x, P[i].y);
        }
        printf("\n");
        free(P);
    }
    return 0;
}