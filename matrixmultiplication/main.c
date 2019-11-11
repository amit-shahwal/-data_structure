#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20][20],b[20][20],c[20][20],m,n,p,q,i,j,k,sum;
    printf("enter the order of 1st\n");
    scanf("%d%d",&m,&n);
    printf("enter the matrrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    printf("enter order of second matrix:\n");
    scanf("%d%d",&p,&q);
    printf("enter the matrix:\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
        scanf("%d",&b[i][j]);
    if(n!=p)
    {
        printf("sorry\n");
        exit(0);
    }
          for(i=0;i<m;i++)
          {
              for(j=0;j<q;j++)
              {
                  c[i][j]=0;
                  for(k=0;k<p;k++)
                  {
                      c[i][j]=c[i][j]+a[i][k]*b[k][j];
                  }

              }
          }
          printf("product matrix is :\n");
          for(i=0;i<m;i++)
          {
              for(j=0;j<q;j++)
              {
                  printf("%d\t",c[i][j]);
              }
              printf("\n");
          }
    return 0;
}
