#include<stdio.h>
void read(int num[10][10],int r,int c,FILE *fp)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            fscanf(fp,"%d",&num[i][j]);
        }
    }
}
int transpose(int num[10][10],int r,int c)
{
    int trans[10][10];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            trans[i][j]=num[j][i];
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(trans[i][j]!=num[i][j])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int num[10][10];
    int r,c,status=1;
    FILE *fp;
    fp=fopen("text3.txt","r");
    printf("Enter row and columns\n");
    scanf("%d%d",&r,&c);
    if(r==c)
    {
        read(num,r,c,fp);
        status=transpose(num,r,c);
        if(status==0)
        {
            printf("Matrix is not Symmetric\n");
        }
        else
            printf("Matrix is Symmetric\n");
    }
    else
        printf("The given matrix is not square matrix\n");
    fclose(fp);
    return 0;
}
