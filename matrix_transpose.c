#include<stdio.h>
void read(int arr[10][10],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

void transpose(int arr[10][10],int r,int c)
{
    int trans[10][10];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            trans[i][j]=arr[j][i];
        }
    }
    display_arr(trans,r,c);
}
void display_arr(int a[10][10],int m,int n)
{
    int i,j;
    printf("The elements are\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    int arr[10][10],trans[10][10];
    int r,c;
    printf("Enter row and columns\n");
    scanf("%d %d",&r,&c);
    read(arr,r,c);
    display_arr(arr,r,c);
    transpose(arr,r,c);
    return 0;
}
