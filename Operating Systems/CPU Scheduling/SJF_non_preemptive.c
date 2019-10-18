#include<stdio.h>
int main(){
	int Arrival_time[100],Burst_time[100],TurnAround_time[100]={0},completion_time[100],waiting_time[100],seq[100];
	int i,j,count,n,min,p;
	float awt,ata;
	printf("Enter no. of process: ");
	scanf("%d",&n);
	printf("Enter their Arrival Time and Burst_time Time\n");
	for (i=0;i<n;i++){
		printf("process-%d :",i+1);
		scanf("%d%d",&Arrival_time[i],&Burst_time[i]);
	}
	p=Arrival_time[0];
	min=0;
	for (i=0;i<n && Arrival_time[i]==p;i++){
		if (Burst_time[min]>Burst_time[i]) 
				min=i;
	}
	seq[min]=1;
	completion_time[min]=Arrival_time[min]+Burst_time[min];
	TurnAround_time[min]=completion_time[min]-Arrival_time[min];
	waiting_time[min]=0;
	awt=0;
	ata=TurnAround_time[min];
	count=n-1;
	j=min;
	while(count>0){
		for (i=0;i<n;i++){
			if (TurnAround_time[i]==0){
				min=i;
				while(Arrival_time[i]==Arrival_time[min]){
					if (Burst_time[min]>Burst_time[i] && TurnAround_time[i]==0) {
						min=i;
					}
					i++;
				}
			break;}
		}
		for (i=0;(i<n && completion_time[j]>= Arrival_time[i]);i++){
			if (Burst_time[min]>Burst_time[i] && TurnAround_time[i]==0) 
			{
				min=i;
			}
		}
		seq[min]=n-count+1;
		completion_time[min]=Burst_time[min]+completion_time[j];
		if (Arrival_time[min]>completion_time[j])
			completion_time[min]=Burst_time[min]+Arrival_time[min];
		j=min;
		TurnAround_time[min]=completion_time[min]-Arrival_time[min];
		ata+=TurnAround_time[min];
		waiting_time[min]=TurnAround_time[min]-Burst_time[min];
		awt+=waiting_time[min];
		count-=1;
	}
	printf("SORTEST JOB FIRST SCHEDULING(NON-PREEMPTIVE)\n");
	printf("ProcessNo.\tArrival\t\tBurstTime\tCompletion\tTurnAround\tWaiting\t\tSequence\n");
	for (i=0;i<n;i++){
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,Arrival_time[i],Burst_time[i],completion_time[i],TurnAround_time[i],waiting_time[i],seq[i]);
	}
	printf("Average Waiting Time: %f\n",awt/n);
	printf("Average TurnAround Time: %f\n",ata/n);
}
