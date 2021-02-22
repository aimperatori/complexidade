#include <stdio.h>

int S[]={1,2,3,4,5,6,7,8,9,10};
int M=sizeof(S)/sizeof(S[0]);

int C(int S[], int m, int N){
//	printf("M=%d N=%d\n",m,N);
	if (N==0) return 1;
	if (N<0 || m<0) return 0;
	return C(S,m-1,N)+C(S,m,N-S[m]);
}

int main(){
    int N=500;
    printf("%d\n",C(S,M-1,N));
}