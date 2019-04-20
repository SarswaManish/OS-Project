#include<stdio.h>
int w_time(int q[][3],int n);
int minimumBurstAndArrival(int copyq[][3],int n);
void display(int r[][3],int ct[],int wt[],int tat[],int n);
int minBurst(int copyq[][3],int n);
int main()
{
int n;
printf("Enter the number of processes :\n"); scanf("%d",&n);
int p[n][3];
for(int i=0;i<n;++i)
p[i][0]=i+1;
for(int i=0;i<n;++i)
{
printf("Enter Burst Time and Arrival Time for Process %d:", i+1); scanf("%d %d",&p[i][1],&p[i][2]); if(p[i][2]==0)
{
printf("Arrival Time can't be Zero. Process Discarded!!!!!\n\n");
--i;
n=n-1;
}
}
printf("\n\n");
int t=w_time(p,n);
printf("\nTotal time taken by Processor  is:%d\n\n",t);
}
int w_time(int q[][3],int n)
{
int copyp[10][3];
for(int i=0;i<n;++i)
{
copyp[i][0]=q[i][0];
copyp[i][1]=q[i][1];
copyp[i][2]=q[i][2];
}
int wt[50]={0},tat[50]={0},i=0,j=0,k=0,t=0,shortest=0,tot=0,ct[50]={0},min;
shortest=minimumBurstAndArrival(copyp,n);
min=copyp[shortest][2];
int max=copyp[0][2];
for(int i=0;i<n;++i)
{
tot=tot+copyp[i][1];
if(max<copyp[i][2])
max=copyp[i][2];
}
t=min;
for(i=min;i<(tot+min);++i)
{
--copyp[shortest][1];
++t;
if(copyp[shortest][1]==0)
{
ct[shortest]=t;
copyp[shortest][1]=copyp[shortest][2]=32767;
if(t>=max)
shortest=minBurst(copyp,n);
else
shortest=minimumBurstAndArrival(copyp,n);
t=t+2;
}
if(t<=max)
{ j=0;
for(int k=0;k<n;++k)
{
if(copyp[k][2]<=t)
{
if(copyp[shortest][1]>copyp[k][1])
shortest=k;
}
}
}
}
for(i=0;i<n;++i)
{
tat[i]=ct[i]-q[i][2];
wt[i]=tat[i]-q[i][1];
}
display(q,ct,wt,tat,n);
return t;
}
