#include <stdio.h>
#include <string.h>

char exp[1000]="1*2+3*4+5*6+7*8+9*2+1*2+3*4+5*6+7*8+9*2+3";
int res[100][100];

int avalia(int inicio, int fim){
    if (res[inicio][fim]!=-1) return res[inicio][fim];
    if (inicio==fim) return exp[inicio]-'0';
    int i,maior=0;
    for (i=inicio+1;i<fim;i+=2){
        int v1=avalia(inicio,i-1);
        int v2=avalia(i+1,fim);
        int res;
        if (exp[i]=='+') res=v1+v2;
        else res=v1*v2;
        if (res>maior) maior=res;
    }
    res[inicio][fim]=maior;
    return maior;
}

int main(){
    int i,j;

    /*
    for (i=0;i<100;i++)
        for (j=0;j<100;j++)
            res[i][j]=-1;
    */
    //inicializa a matriz com -1
    memset(res, -1, sizeof(res));

    int res=avalia(0,strlen(exp)-1);

    printf("%d\n",res);
}