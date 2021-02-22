#include <stdio.h>

#define max(A,B) (A)>(B)?(A):(B)
#define MAXPIZZA 31
#define MAXPEDIDOS 20

int w[MAXPEDIDOS];
int v[MAXPEDIDOS];
int memo[MAXPEDIDOS][MAXPIZZA];

int mochila(int objeto, int tempo){
    if (memo[objeto][tempo]!=-1) return memo[objeto][tempo];
    if (w[objeto-1]>tempo) return mochila(objeto-1, tempo);

    int com = v[objeto-1]+mochila(objeto-1, tempo-w[objeto-1]);
    int sem = mochila(objeto-1, tempo);

    memo[objeto][tempo] = max(com, sem);

    return memo[objeto][tempo];
}  

void main(){
    int N, P;
    int i,j;

    while(scanf("%d", &N) && N){

        scanf("%d", &P);

        for(i=0;i<N;i++){
            scanf("%d %d", &v[i], &w[i]);
        }

        for (i=0;i<=MAXPEDIDOS;i++)
            for (j=0;j<=P;j++)
                if (i==0 || j==0)
                    memo[i][j]=0;
                else
                    memo[i][j]=-1;

        printf("%d min.\n", mochila(N, P));
    }
}