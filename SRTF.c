#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,j;
	printf("enter no.of processes ");
	scanf("%d",&n);
	int at[n+1],bt[n+1],ct[n+1],tat[n+1],wt[n+1],p[n+1],b[n+1];
	printf("enter arrival and burst times");
	for(i=1;i<=n;i++){
		scanf("%d%d",&at[i],&bt[i]);
		p[i]=i;
		b[i]=bt[i];
	}
	int temp,min=INT_MAX,mini,max=INT_MIN,c=0;
	ct[0]=0;
	j=1;
	while(j<=n){
		min=INT_MAX;
		for(i=1;i<=n;i++){
			if(min>=at[i]&&b[i]!=0){
				if(min==at[i]&&b[mini]>b[i]&&b[i]!=0){
					min=at[i];
					mini=i;
				}
				min=at[i];
				mini=i;
			}
			if(max<at[i]){
				max=at[i];//
			}
		}
		min=INT_MAX;
		if(c<=at[mini]){
			if(c<at[mini]){
				//printf("idle %d %d\n",c,at[mini]);
				printf("idle |");
			}
			//printf("p%d %d-%d\n",p[mini],at[mini],at[mini]+1);
			printf("p%d |",p[mini]);
			c=at[mini]+1;
			b[mini]=b[mini]-1;
			if(b[mini]==0){
				ct[mini]=c;
				j=j+1;
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(at[i]<=c&&b[i]<=min&&b[i]!=0){
					if(min==b[i]&&at[mini]>at[i]){
						min=b[i];
						mini=i;
					}
					min=b[i];
					mini=i;
				}
			}
			if(c<max){
				//printf("p%d %d-%d\n",p[mini],c,c+1);
				printf("p%d |",p[mini]);
				c=c+1;
				b[mini]=b[mini]-1;
				if(b[mini]==0){
					ct[mini]=c;
					j=j+1;
				}
			}
			else{
				//printf("p%d %d-%d\n",p[mini],c,c+b[mini]);
				printf("p%d |",p[mini]);
				c=c+b[mini];
				b[mini]=0;
				ct[mini]=c;
				j=j+1;
			}
		}
		//j=j+1;
	}
	for(i=1;i<=n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	printf("\n\n\np.no\tat\tbt\tct\ttat\twt\t\n");
	for(i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
		printf("\n");
	}

}
	/*
	0 8
	1 6
	2 5
	3 2
	4 4
	5 1
	*/
	/*
	5 1
	2 1
	4 3
	1 10
	3 4
	1 8
	2 6
	*/
