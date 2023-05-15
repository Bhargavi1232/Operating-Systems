#include<stdio.h>
#include<limits.h>
void swap(int arr[],int a,int b)
{
	int temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
int main()
{
	int n,i,j,mini,temp,k;
	printf("enetr number of processes");
	scanf("%d",&n);
	int p[n+1],at[n+1],bt[n+1],ct[n+1],tat[n+1],wt[n+1],visited[n+1];
	printf("enetr ATs and BTs");
	for(i=1;i<=n;i++)
	{
			scanf("%d%d",&at[i],&bt[i]);
			p[i]=i;
			visited[i]=0;
	}	
	//sorting
	ct[0]=0;
	int min=INT_MAX;
	for(j=1;j<=n;j++)
	{
		min=INT_MAX;
		for(i=j;i<=n;i++)
		{
			if(at[i]<=min && visited[i]!=1)
			{
				if(min==at[i]&&bt[min]>bt[i])
				{
					min=at[i];
					mini=i;
				}
				min=at[i];
				mini=i;
			}
		}
		min=INT_MAX;
		if(ct[j-1]<=at[mini])
		{
			swap(at,mini,j);
			swap(bt,mini,j);
			swap(p,mini,j);
			ct[j]=at[j]+bt[j];
			visited[j]=1;
		}
		else
		{
			for(i=j;i<=n;i++)
			{
				if(at[i]<=ct[j-1]&&bt[i]<min)
				{
					min=bt[i];
					mini=i;
				}
			}
			swap(at,mini,j);
			swap(bt,mini,j);
			swap(p,mini,j);
			ct[j]=ct[j-1]+bt[j];
			visited[j]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ct[i-1]>=at[i])
		{
			ct[i]=ct[i-1]+bt[i];
		}
		else
		{
			ct[i]=at[i]+bt[i];
		}
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	printf("p.no\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("GANTT CHART_____\n");
/*	for(i=1;i<=n;i++)
	{
		if(at[i]>ct[i-1])
		{
			printf("%d-%d_>idle\n",ct[i-1],at[i]);
		}
		printf("%d ",p[i]);
	}*/
		for(i=1;i<=n;i++)
	{
		if(at[i]>ct[i-1])
		{
			printf("%d to %d-idle\n",ct[i-1],at[i]);
		    k=at[i]-ct[i-1];
		}
		
		else
		{
			printf("%d to %d-p[%d]\n",ct[i-1],ct[i],p[i]);
			continue;
		}
		printf("%d to %d---p[%d]\n",k+ct[i-1],ct[i],p[i]);
	}
}
/*
2
4
19
6
10
4
13
2
14
5
16
3 */
