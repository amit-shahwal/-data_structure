#include <stdio.h>
#include <stdlib.h>

int main()
{int i,j,k,sum=0,mt[40][40],a[40][40],b[40][40],m,n,p,q;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    scanf("%d%d",&p,&q);
    if(n!=p)
    {
        exit(0);
    }else{

for(i=0;i<p;i++)
        for(j=0;j<q;j++)
        scanf("%d",&b[i][j]);


    for(i=0;i<m;i++){
        for(j=0;j<q;j++) {
for(k=0;k<q;k++)
{
    sum=sum+a[i][k]*b[k][j];

}
    mt[i][j]=sum;sum=0;}}
    for(i=0;i<m;i++){
        for(j=0;j<q;j++){
                printf(" %d ",mt[i][j]);}
        printf("\n");}

    }

    return 0;
}
