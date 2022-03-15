#include <sys/time.h>
#include<iostream>
using namespace std;

void recursion(int n,int *a)
{
    if (n == 1)
        return;
    else
    {
        for (int i = 0;i<n/2;i++)
            a[i]+=a[n-i-1];
        n=n/2;
        recursion(n,a);
    }
}

int main()
{

    struct timeval t1, t2;
    int size =16;

    for(;size<=65536;size*=2)
    {
        int *a=new int [size];

        gettimeofday(&t1, NULL);
        for(int j=0;j<1000;j++)
        {
            for(int k=0;k<size;k++)
                a[k]=k;

            recursion(size,a);

        }

        gettimeofday(&t2, NULL);//end
        double deltaT;
        deltaT= (t2.tv_sec-t1.tv_sec) * 1000000 + t2.tv_usec-t1.tv_usec;
        cout<<size<<"   "<<deltaT/1000<<"     "<<a[0]<<endl;
        delete []a;
    }

    return 0;
}

