#include<stdio.h>
#include<math.h>
const int N = 40;
int  f[N],j;

int main()
{
    int x;
    scanf("%d",&x);
    f[0]=0;
    f[1]=1;
    f[2]=1;
    for(j=3 ; j<=x; j++){
        f[j]=f[j-1]+f[j-2]+f[j-3];
    }
    printf("%d",f[x]);
    return 0;
}