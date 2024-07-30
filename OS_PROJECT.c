#include <stdio.h>
#include <stdbool.h>
int main()
{
	printf("\t****************************************************************************\n");
	printf("\t  IMPLEMENTATION OF BANKER'S ALGORITHM FOR MULTIPLE INSTANCES DYNAMICALLY\n");
	printf("\t****************************************************************************\n");
	int  p, r, i, j, process, dp, mneed[20][20], rneed[20][20], alloc[20][20], cavail[20], completed[20], safeSequence[20];
	static int count = 0;
	bool flag = true;
	printf("Enter the total number of processes: ");
	scanf("%d", &p);
	printf("\nEnter the total number of resources: ");
	scanf("%d", &r);
	printf("\nEnter the allocation for each process: ");
	for(i=0;i<p;i++)
	{
		printf("\nFor process %d: \n",i+1);
		for(j=0;j<r;j++)
			scanf("%d", &alloc[i][j]);	
	}
	printf("\nEnter the maximum need for each process: ");
	for(i=0;i<p;i++)
	{
		printf("\nFor process %d :\n",i+1);
		for(j=0;j<r;j++)
			scanf("%d", &mneed[i][j]);
	}
	printf("\nEnter the current available resources: \n");
	for(i=0;i<r;i++){
			scanf("%d", &cavail[i]);	
	}
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			rneed[i][j] = mneed[i][j]-alloc[i][j];
		}
	}
	for(i = 0; i< p; i++)
		completed[i] = 0;
	while(count!=p&&process!=-1){
		process = -1;
		for(i=0;i<p;i++){
			if(completed[i]==0){
				process = i ;
				for(j = 0; j < r; j++){
					if(cavail[j]<rneed[i][j]){
						process = -1;
						dp = i;
						break;
					}
				}
			}
			if(process!=-1){
				break;
			}
		}
		if(process!=-1){
			safeSequence[count]=process+1;
			count++;
			for(i=0;i<r;i++){
				cavail[i] += alloc[process][i];
				alloc[process][i] = 0;
				mneed[process][i] = 0;
				completed[process] = 1;
			}
		}
	}
	for(i=0;i<p;i++){
		if(completed[i]==0){
			flag = false;
		}   
	}
	if(flag== true)
    {
		printf("\nThe system is in safe state.\n");
		printf("The safe sequence is: ");
    	for( i = 0; i < p; i++)
			printf("P%d  ", safeSequence[i]);
    }
	else{
		printf("\nThe system is in unsafe state.");
		printf("\nThe process which cause deadlock is: P%d", dp);
	}
}