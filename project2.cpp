#include<iostream>
using namespace std;
int waiting_time (int q[][3], int n);
int Cal_minArrivalandBurst (int arr[][3], int n);
void show (int R[][3], int CT[], int WT[], int TAT[], int N);
int Cal_minBurst (int arr[][3], int n);
int
main ()
{
	 int n;
  cout << "Enter total number of process to be processed:\n";
  cin >> n;
if(n==0){
cout<<"No. of processes can’t be zero ";}
  int p[n][3];
  for (int i = 0; i < n; ++i)
    p[i][0] = i + 1;
  for (int i = 0; i < n; ++i)
    {
      cout << "Enter Burst time and Arrival time for process\n" << i + 1;
      cin >> p[i][1] >> p[i][2];
      if (p[i][2] == 0)
    {
      cout << "Arrival Time can't be Zero! Enter it again!!!\n\n";
      --i;
      n = n - 1;
    }
    }
}
waiting_time (int q[][3], int n)
{
  int arr[10][3];
  for (int i = 0; i < n; ++i)
    {
      arr[i][0] = q[i][0];
      arr[i][1] = q[i][1];
      arr[i][2] = q[i][2];
    }
  int wt[50] = { 0 }, tat[50] ={0}, i = 0, j = 0, k = 0, t = 0, shortest = 0, tot = 0, ct[50] ={0}, min;
  shortest = Cal_minArrivalandBurst (arr, n);
  min = arr[shortest][2];
  int max = arr[0][2];
  for (int i = 0; i < n; ++i)
    {
      tot = tot + arr[i][1];
      if (max < arr[i][2])
    max = arr[i][2];
    }
  t = min;
  for (i = min; i < (tot + min); ++i)
    {
      --arr[shortest][1];
      ++t;
      if (arr[shortest][1] == 0)
    {
      ct[shortest] = t;
      arr[shortest][1] = arr[shortest][2] = 32000;
      if (t >= max)
        shortest = Cal_minBurst (arr, n);
      else
        shortest = Cal_minArrivalandBurst (arr, n);
      t = t + 2;
    }
      if (t <= max)
    {
      j = 0;
      for (int k = 0; k < n; ++k)
        {
          if (arr[k][2] <= t)
        {
          if (arr[shortest][1] > arr[k][1])
            shortest = k;
        }
        }
    }
    }
  for (i = 0; i < n; ++i)
    {
      tat[i] = ct[i] - q[i][2];
      wt[i] = tat[i] - q[i][1];
    }
  show (q, ct, wt, tat, n);
  return t;
}
int Cal_minBurst (int arr[][3], int n)
{
  int shrt=0;
  for (int i = 0; i < n; ++i)
    {
      if (arr[shrt][1] > arr[i][1])
    shrt= i;
    }
  return shrt;
}
