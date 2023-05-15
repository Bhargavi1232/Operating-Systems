#include<stdio.h>
int main()
{
	int n,i,j,temp;
	float sum=0,sum1=0;
	printf("enetr num of processes");
	scanf("%d",&n);
	int at[n+1],bt[n+1],ct[n+1],tat[n+1],wt[n+1],p[n+1];
/*	printf("Enetr arraival times");
	for(i=1;i<=n;i++)
		scanf("%d",&at[i]);
	printf("enter burst times");
	for(i=1;i<=n;i++)
		scanf("%d",&bt[i]);
	for(i=1;i<=n;i++)
		p[i]=i	*/
	printf("Arrival time,Burst time");
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&at[i],&bt[i]);
		p[i]=i;
	}
	ct[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(at[j]>at[j+1])
			{
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ct[i-1]>=at[i])
			ct[i]=ct[i-1]+bt[i];
		else
			ct[i]=at[i]+bt[i];
	}
	for(i=1;i<=n;i++)
		tat[i]=ct[i]-at[i];
	for(i=1;i<=n;i++)
		wt[i]=tat[i]-bt[i];
	printf("P_id\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],bt[i]);
		printf("\n");
	}
	for(i=1;i<=n;i++)
		sum=sum+tat[i];
	printf("AVERAGE TRT IS %f\n",(sum)/n);
	for(i=1;i<=n;i++)
		sum1=sum1+wt[i];
	printf("AVERAGE WT IS %f\n",(sum1)/n);
	//GANTT CHART REPRESENTATION
	printf("gantt chart representation\n");
	for(i=1;i<=n;i++)
	{
		if(at[i]>ct[i-1])
			printf("%d to %d-idle\n",ct[i-1],at[i]);
		printf("%d to %d-p[%d]\n",ct[i-1],ct[i],p[i]);
	}
}
