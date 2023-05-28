#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void mergesort(int a[],int lb,int up,FILE *fp1);
void merge(int a[],int lb,int mid,int up,FILE *fp1);
int main()
{
    float duration;
    FILE *fp1;
    fp1=fopen("num1.txt","r");
    clock_t start,end;
    int lo,up,n,i,num[100];
    srand(time(0));
    printf("enter no\n");
    fscanf(fp1,"%d",&n);
     printf("enter lo\n");
    fscanf(fp1,"%d",&lo);
     printf("enter up\n");
    fscanf(fp1,"%d",&up);
    for(i=0;i<n;i++)

    {
       num[i]=(rand()%(up-lo+1))+lo;
        printf("%d ",num[i]);
    }
    printf("\n");
    start=clock();
    mergesort(num,0,n-1,fp1);
    end=clock();
    duration=(float)(end-start)/ CLOCKS_PER_SEC;
     printf("after merge sort\n");
      for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("Time taken: %f seconds\n", duration);
    printf("\n");
    return 0;
}

void mergesort(int a[],int lb,int up,FILE *fp1)
{
    int mid;
    if(lb<up)
    {
        mid=(lb+up)/2;
         mergesort(a,lb,mid,fp1);
          mergesort(a,mid+1,up,fp1);
           merge(a,lb,mid,up,fp1);

    }
}
void merge(int a[],int lb,int mid,int up,FILE *fp1)
{
    int b[20];
   int k=mid+1;
    mid=(lb+up)/2;
   int l=lb;
int   start=lb;
   while(lb<=mid && k<=up)
   {
       if(a[lb]>=a[k])
       {
           b[l]=a[k];
           k++;
       }
       else
       {
           b[l]=a[lb];
           lb++;
       }
       l++;
   }
   if(lb>mid)
   {
       while(k<=up)
       {
           b[l]=a[k];
           l++;
           k++;
       }
   }
   else
   {
     while(lb<=mid)
     {
         b[l]=a[lb];
         l++;
         lb++;
     }
   }

   for(l=start;l<=up;l++)
    a[l]=b[l];
}
