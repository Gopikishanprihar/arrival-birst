#include<stdio.h> 
 
int main() 
{ 
 
  int count,j=0,n,time,remain,tq1,tq2; 
  int WT[10],TAT[10],AT[10],BT[10],RT[10],t[10];
  int total_turnaround_time=0,total_waiting_time=0;
  float atat=0,awt=0; 
  int i,m,k=0;
  int max,l;
  printf("                      ********OPERATING SYSTEM********              \n");
  printf("                    **************QUESTION 2************            \n");
  printf("Enter the Total Process:\t \n"); 
  scanf("%d",&n); 
  remain=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter the Arrival Time in (ascending order) and Burst Time for Process P[%d]  :\n",i+1); 
    scanf("%d",&AT[i]); 
    scanf("%d",&BT[i]); 
    RT[i]=BT[i]; 
  } 
  time=AT[0]; 
printf("Enter Time Quantum: for 1st iteration(as per the question time slice for 1st iteration is 6) \t\n"); 
  scanf("%d",&tq1); 
   
 	for(i=0;i<n;i++){
		if(AT[i]<=time && RT[i]!=0)
		{
			printf("The process P[%d] is running at present\n",i+1);
			RT[i] -=tq1;
			time+=tq1;
			if(RT[i]<=0)
			{
				printf("The process P[%d] is completed at 1st iteration \n",i+1);
				t[i]=time;
				RT[i]=0;
				TAT[i]=time-BT[i];
				WT[i]=TAT[i]-AT[i];
				printf("%d   %d",TAT[i],WT[i]);
			}
			
		}
	}
	printf("Enter Time Quantum: for 2nd iteration(as per question time slice for 2nd is 10) \t\n"); 
  scanf("%d",&tq2);
  for(i=0;i<n;i++)
  {
		if(AT[i]<=time && RT[i]!=0)
		{
			printf("The process P[%d] is running at present\n",i+1);
			RT[i]-=tq2;
			time+=tq2;
			if(RT[i]<=0)
			{
				printf("the process P[%d] is completed at 2nd iteration\n",i+1);
				t[i]=time;
				RT[i]=0;
					TAT[i]=time-BT[i];
				WT[i]=TAT[i]-AT[i];
				
			}
		
		}
		
		
	} 
	printf("Third iteration is started\n");
	printf("searching for max burst time\n");
	for(i=0;i<n;i++)
	{
		if(RT[i]>0)
		{
			max=RT[i];
		}
	}
	printf("burst time max is %d\n",max);
	if(max!=0){
		for(j=0;j<n;j++)
		{
 			m=0;
			l=0;
			for(i=0;i<n;i++)
			{
				if(RT[i]>=max && RT[i]>0)
				{
					max = RT[i];
					l=i;
				}
				
			}
			 
			if(max!=0)
			{	
			m=l;		
			printf("The process P[%d]   having max burst time %d is running at present\n",m+1,RT[l]);
			time+=RT[l];
			RT[l]=0;
			printf("the process P[%d] is completed at 3rd iteration\n",m+1);
			t[l]=time;
				TAT[l]=time-BT[l];
				WT[l]=TAT[l]-AT[l];
	    	for(k=0;k<n;k++)
     	     {
	     	    if(RT[k]>0)
	    	   {
			      max=RT[k];
			
	    	   }
	    	   else
	    	   {
	    	   	max=0;
			   }
    	     }	
			 printf("next max is %d",max);
	}
		}
	}
	else{
		printf("All process are already  beem completed during 2nd iteration only\n");
	}

	 printf("\n\nProcess\t|Turnaround Time|Waiting Time|Time completed\n\n"); 
	for(i=0;i<n;i++)
	{
		printf("P[%d] %d %d %d \n",i+1,TAT[i],WT[i],t[i]);
	}
	for(i=0;i<n;i++)
	{
		total_turnaround_time +=TAT[i];
		total_waiting_time +=WT[i];
		
	}
	atat=total_turnaround_time/n;
	awt=total_waiting_time/n;
	printf("Total waiting time is %d\n",total_waiting_time);
	printf("Total turnaround time is %d",total_turnaround_time);
	 printf("Average turn around time is%f\n",atat);
	 printf("Average wating time is %f\n",awt);
	 printf("*******************************************ALL THE PROCESSES HAVE BEEN COMPLETED******************************************\n");
     printf("********************************************************THE END******************************************\n"); 
}
