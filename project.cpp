#include<stdio.h>
int main()
{
	int bt[10],at[10],p[10],n,temp,i,j,wt[10],sum=0;//bt=burst time,at=arrival time,p=process,n=no. of process,wt=waiting time
	float avg;
	printf("total no of process");
	scanf("%d",&n);
	printf("\nenter arrival time for each process:-");
	for(i=0;i<n;i++)
	{
		printf("\narrival time of process P%d:",i);
		scanf("%d",&bt[i]);
		at[i]=i;
	}
	printf("\n\nenter burst time for each process:-");
	for(i=0;i<n;i++)
	{
		printf("\nburst time of process P%d:",i);
		scanf("%d",&bt[i]);
		p[i]=i;
	}
	
	return 0;
}
