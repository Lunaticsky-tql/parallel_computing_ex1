#include <sys/time.h>
#include<iostream>
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
using namespace std;


int main()
{

    struct timeval t1, t2;
    int size =16,sum;

    for(;size<=65536;size*=2)
    {
        int *a=new int [size];

        gettimeofday(&t1, NULL);
        for(int j=0;j<1000;j++)
        {
            for(int k=0;k<size;k++)
                a[k]=k;

            sum=0;
            _for(i,0,size)
                sum += a[i];

        }

        gettimeofday(&t2, NULL);//end
        double deltaT;
        deltaT= (t2.tv_sec-t1.tv_sec) * 1000000 + t2.tv_usec-t1.tv_usec;
        cout<<size<<"   "<<deltaT/1000<<"     "<<sum<<endl;
        delete []a;
    }

    return 0;
}
