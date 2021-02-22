#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM 10000
#define INF 9999999

typedef struct coords{
    double x;
    double y;
} coords;

coords C[TAM];

double dist(int i, int j){
    double DX = C[i].x - C[j].x;
    double DY = C[i].y - C[j].y;

    return sqrt(DX*DX+DY*DY);
}

int comp(const void *a, const void *b) {
    coords *sp1 = (coords *)a;
    coords *sp2 = (coords *)b;
    
    if(sp1->x > sp2->x) 
        return 1;
    else if (sp1->x < sp2->x)
        return -1;
    else
        if(sp1->y > sp2->y)
            return 1;
        else 
            return -1;
}

double calcDist2(int a, int b) {
    double dEsq, dDir, d, valMeio;
    int i, j;
    
    if(a == b) return INF;
    else if(b-a == 1) return dist(a, b);    

    dEsq = calcDist2(a, (a+b)/2);
    dDir = calcDist2((a+b)/2+1, b);
    
    d = (dEsq<dDir) ? dEsq : dDir;
    j = (a+b)/2;
    valMeio = C[j].x;

    do {
        i = (a+b)/2 + 1;

        while (valMeio-C[i].x < d && i <= b){
            dEsq = dist(i, j);
            d = (d < dEsq) ? d : dEsq;
            i++;
        }
        j--;
    }while(valMeio-C[j].x < d && j >= a);

    return d;
}

void main(){
    int N, i;
    double minDist;

    while(scanf("%d", &N) && N){

        for(i=0;i<N;i++){
            scanf("%lf %lf", &C[i].x, &C[i].y);
        }

        qsort(C, N, sizeof(coords), comp);

        minDist = calcDist2(0, N-1);

        if(minDist < TAM){
            printf("%.4lf\n", minDist);
        }else{
            puts("INFINITY");
        }
    }
}