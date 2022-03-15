#include <sys/time.h>
#include<iostream>
using namespace std;

 const int N = 5000; // matrix size
 double a[N],b[N][N] ,sum[N];

 void init (int n) // generate a  matrix
 {
 for (int i = 0; i < N; i++){
    a[i]=N-i;
 for (int j = 0; j < N; j++)
 b[i][j] =i/2==0? (i + j):(i-j) ;
 }
 }

int main()
{
  struct timeval t1, t2;
  init (N);

  gettimeofday(&t1, NULL);//begin

  for(int i = 0; i < N; i++){
 sum[i] = 0.0;
for(int j = 0; j < N; j++)
sum[i]+= b[j][i]*a[j];
}

  gettimeofday(&t2, NULL);//end

  double deltaT;
  deltaT= (t2.tv_sec-t1.tv_sec) * 1000000 + t2.tv_usec-t1.tv_usec;
  cout<<deltaT/1000;
  return 0;
}
