#include <sys/time.h>
#include<iostream>
using namespace std;


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

            for (int m = size; m > 1; m /= 2)
                for (int i= 0;i <m/2;i++)
                    a[i] = a[i*2] + a[i*2+1];
        }

        gettimeofday(&t2, NULL);//end
        double deltaT;
        deltaT= (t2.tv_sec-t1.tv_sec) * 1000000 + t2.tv_usec-t1.tv_usec;
        cout<<size<<"   "<<deltaT/1000<<"     "<<a[0]<<endl;
        delete []a;
    }

    return 0;
}
