#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define pi  3.141592
bool FFT(int *a,complex double *y,int n)
{
    if (n==1)
    {
        y[0]==(complex double)(a[0]);
        return true;   
    }
    if(n<1)
    {
        return false;
    }
    if(n%2!=0)
    {
        n=n+1;
        *(a+n-1)=0;
    }
    
    int *a_even=(int *)malloc(sizeof(int)*(n/2));
    int *a_odd=(int *)malloc(sizeof(int)*(n/2));
    complex double *y_even=(complex double *)malloc(sizeof(complex double)*(n/2));
    complex double *y_odd=(complex double*)malloc(sizeof(complex double)*(n/2));
    int k=0;
    int l=0;
    for (int i=0;i<=n-1;i++)
    {
        if(i%2==0)
        {
            a_even[k]=a[i];
            k++;
        }
        else
        {
            a_odd[l]=a[i];
            l++;
        }
    }

    FFT(a_even,y_even,n/2);
    FFT(a_odd,y_odd,n/2);

    complex double wn=cos((2*pi)/n)-I*sin((2*pi)/n);
    complex double w=1+I*;
    for(int i=0;i<=n/2-1;i++)
    {
        y[i]=y_even[i]+
    }
}


int main()
{
    

}