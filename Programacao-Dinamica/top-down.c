#include <stdio.h>

#define max(A,B) (A)>(B)?(A):(B)
#define pesomax 80

int w[10]={10,15,12,13,21,12,5,8,4,10};
float v[10]={10.0,30.0,6.0,13.0,60.0,12.0,25.0,40.0,20.0,5.0};
float memo[11][pesomax+1];

float mochila(int objeto, int peso)
{
    if (memo[objeto][peso]!=-1) return memo[objeto][peso];
    if (w[objeto-1]>peso) return mochila(objeto-1,peso);

    float com = v[objeto-1]+mochila(objeto-1,peso-w[objeto-1]);
    float sem = mochila(objeto-1,peso);

    memo[objeto][peso] = max(com,sem);

    return memo[objeto][peso];
}  

int main(){
    int i,j;
    for (i=0;i<11;i++)
        for (j=0;j<=pesomax;j++)
            if (i==0 || j==0)
                memo[i][j]=0;
            else
                memo[i][j]=-1;

    printf("%f\n",mochila(10, pesomax));

    /*for (i=0;i<=10;i++)
    {
    for (j=0;j<=20;j++)
            printf("%3.0f ",memo[i][j]);
        printf("\n");	
    }*/
}