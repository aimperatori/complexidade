#include <stdio.h>

int S[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int M=sizeof(S)/sizeof(S[0]);
#define NMax 200
#define MMax 200
int T[MMax][NMax];

int C(int S[], int m, int N){
	if (N==0) return 1;
	if (N<0 || m<0) return 0;
	if (T[m-1][N]==-1) T[m-1][N]=C(S, m-1, N);
    // diminui o m em 1 para nao repetir
	if (T[m][N-S[m]]==-1) T[m][N-S[m]] = C(S, m-1, N-S[m]); 
    
	return T[m-1][N]+T[m][N-S[m]];
}

int main(){
    int N=500,i,j;
    for (i=0;i<MMax;i++)
        for (j=0;j<NMax;j++)
            T[i][j]=-1;

    printf("%d\n",C(S,M-1,N));
}