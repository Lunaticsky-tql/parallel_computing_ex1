#include <sys/time.h>
#include<iostream>
using namespace std;


int main()
{

    struct timeval t1, t2;
    int size =16;
    double sum,sum1,sum2;

    for(;size<=65536;size*=2)
    {
        double *a=new double [size];

        gettimeofday(&t1, NULL);
        for(int j=0;j<1000;j++)
        {
            for(int k=0;k<size;k++)
                a[k]=k;

            sum=0;
            sum1 = 0; sum2 = 0;
            for (int i = 0;i <size;i+=2) {
                sum1 += a[i];
                sum2 += a[i + 1];
            }
            sum = sum1 + sum2;
        }

        gettimeofday(&t2, NULL);//end
        double deltaT;
        deltaT= (t2.tv_sec-t1.tv_sec) * 1000000 + t2.tv_usec-t1.tv_usec;
        cout<<size<<"   "<<deltaT/1000<<"     "<<sum<<endl;
        delete []a;
    }

    return 0;
}
