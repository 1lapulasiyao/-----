#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define pi  3.141592

//FFT：对输入离散信号进行傅里叶变换，得到其各个虚指数分量的傅里叶系数
/*
输入:（1）int *a：输入离散信号序列的地址
     （2）complex double *y:输出傅里叶系数数组的地址
     （3）int n: a和y的长度

输出：True代表傅里叶变换成功
     False代表失败


*/
bool FFT(int *a,complex double *y,int n)
{
    /*
    判断输入的n符不符合要求
    n==1时设置递归出口
    n不是偶数时扩展至偶数
    */
    if (n==1)
    {
        y[0]=(complex double)(a[0]);
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
    
    /*
    动态申请内存，even代表数组下标为偶数的部分，odd为奇数
    */
    int *a_even=(int *)malloc(sizeof(int)*(n/2));
    int *a_odd=(int *)malloc(sizeof(int)*(n/2));
    complex double *y_even=(complex double *)malloc(sizeof(complex double)*(n/2));
    complex double *y_odd=(complex double*)malloc(sizeof(complex double)*(n/2));
    
    /*
    将输入离散信号序列分成偶数下班和奇数下标两个部分
    */
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

    /*
    递归求解
    */
    FFT(a_even,y_even,n/2);
    FFT(a_odd,y_odd,n/2);
    free(a_even);
    free(a_odd);

    /*
    FFT算法核心
    */
    complex double wn=cos((2*pi)/n)-I*sin((2*pi)/n);
    complex double w=1+I*0;
    for(int i=0;i<=n/2-1;i++)
    {
        y[i]=y_even[i]+w*y_odd[i];
        y[i+n/2]=y_even[i]-w*y_odd[i];
        w=w*wn;
    }
    free(y_even);
    free(y_odd);

    return true;
}


int main()
{
    int a[4]={1,1,0,0};
    complex double y[4];
    FFT(a,y,4);
    printf("%f",cimag(y[1]));
    
}