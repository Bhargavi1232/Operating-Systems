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
	int n,i,j,mini;
	printf("enetr number of processes\n");
	scanf("%d",&n);
	int p[n+1],prior[n+1],at[n+1],bt[n+1],ct[n+1],tat[n+1],wt[n+1];
	printf("enetr at's bt's and priorities\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&at[i],&bt[i],&prior[i]);
		p[i]=i;
	}
	ct[0]=0;
	int min=INT_MAX;
	for(j=1;j<=n;j++)
	{
		min=INT_MAX;
		for(i=j;i<=n;i++)
		{
			if(at[i]<=min)
			{
				if(min==at[i] && prior[min]>prior[i])
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
			swap(prior,mini,j);
			ct[j]=at[j]+bt[j];
		}
		else
		{
			for(i=j;i<=n;i++)
			{
				if(at[i]<=ct[j-1]&& min>prior[i])
				{
					min=prior[i];
					mini=i;
				}
			}
			swap(at,mini,j);
			swap(bt,mini,j);
			swap(p,mini,j);
			swap(prior,mini,j);
			ct[j]=ct[j-1]+bt[j];
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
	printf("\nP_ID\tAT\tBT\tPRIOR\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],prior[i],ct[i],tat[i],wt[i]);
	}
}
