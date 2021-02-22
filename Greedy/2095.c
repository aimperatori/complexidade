#include <stdio.h>
#include <stdlib.h>

#define TAM 100000

int f=0;
int S;

int comp(const void *a, const void *b) {    
    return (*(int*)a - *(int*)b);
}

int binary_search(long long int d, int s, long long int *vetor){      
    int l, m, found;
    
    l = s-1; 
    found = 0;
      
    while (f <= l){
        m = (f + l) / 2;

        if (d <= vetor[m]) {
            l = m - 1;
        }
        else if (d > vetor[m]) {
            found = 1;
            f++;
            break;
        }
    }

    return found;
}

int main(){
	int i, cont=0;
	long long int v1[TAM], v2[TAM];
	
	scanf("%d", &S);    
	
	for (i=0; i < S; i++){
		scanf("%lld", &v1[i]);
	}
	
	for (i=0; i < S; i++){
        scanf("%lld", &v2[i]);
	}
	
    qsort(v1, S, sizeof(long long int), comp);
    qsort(v2, S, sizeof(long long int), comp);

	for (i=0; i < S; i++){
        if(binary_search(v2[i],S,v1)) 
            cont++;
    }
	
	printf("%d\n", cont);

	return 0;
}