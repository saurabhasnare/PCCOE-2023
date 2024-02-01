#include<stdio.h>

#include<string.h>
#include<stdlib.h>

int process[10],arrival_time[10],burst_time[10],waiting_time[10],turnaround_time[10],temp_burst_time[10];
float avg_waiting_time,avg_turnaround_time,total_wait_time=0,total_turnaround_time=0;

int n,i,j,temp,quant_time,y_n,sum,count,wait_time,tat_time;
int priority[10];
void part1(){
	
	printf("\nEnter How Many Process do u want : ");
	scanf("%d",&n);
	
	printf("\nEnter %d process : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&process[i]);
	}
	
	printf("enter %d arrival time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arrival_time[i]);
        }
	printf("enter %d burst time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&burst_time[i]);
	}

}
void part2(){
	waiting_time[0]=0;
	turnaround_time[0]=waiting_time[0]+burst_time[0];
	for(i=1;i<n;i++){
	
		waiting_time[i]=burst_time[i-1]+waiting_time[i-1];
		turnaround_time[i]=waiting_time[i]+burst_time[i];
		total_wait_time+=waiting_time[i];
		total_turnaround_time+=turnaround_time[i];
	}
	avg_waiting_time=total_wait_time/n;
	avg_turnaround_time=total_turnaround_time/n;
	printf("\np\t A.T\t B.T\t TAT\t WT");
	
	for(i=0;i<n;i++)
    	{
    		printf("\n----------------------------------------------------------------------------------");
      		printf("\nP%d\t %d\t %d \t %d \t %d",process[i],arrival_time[i],burst_time[i],turnaround_time[i],waiting_time[i]);
    	}
    	printf("\naverage turnaround time is %f",avg_turnaround_time);

    	printf("\naverage wating timme is %f",avg_waiting_time);
}
void fcfs_scheduling(){
	
	part1();
	for(i=0;i<n;i++)
	{
	     for(j=0;j<(n-i);j++)
	    {
		      if(arrival_time[j]>arrival_time[j+1])
		     {
				temp=process[j+1];
				process[j+1]=process[j];
				process[j]=temp;
				
				temp=arrival_time[j+1];
				arrival_time[j+1]=arrival_time[j];
				arrival_time[j]=temp;
				
				temp=burst_time[j+1];
				burst_time[j+1]=burst_time[j];
				burst_time[j]=temp;
		      }
	     }
	}
	part2();
	
}

void sjf_scheduling(){
	
	part1();	
	for(i=0;i<n;i++)
	{
	     for(j=0;j<(n-i-1);j++)
	    {
		      if(burst_time[j]>burst_time[j+1])
		     {
				temp=process[j+1];
				process[j+1]=process[j];
				process[j]=temp;
				
				temp=burst_time[j+1];
				burst_time[j+1]=burst_time[j];
				burst_time[j]=temp;
				
				temp=arrival_time[j+1];
				arrival_time[j+1]=arrival_time[j];
				arrival_time[j]=temp;
				
		      }
	     }
	}
	
	part2();

}

void round_robin_scheduling(){

	printf("\nEnter How Many Process do u want : ");
	scanf("%d",&n);
	y_n=n;
	
	printf("\nEnter %d process : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&process[i]);
	}
	
	printf("enter %d arrival time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arrival_time[i]);
        }
	printf("enter %d burst time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&burst_time[i]);
	    temp_burst_time[i]=burst_time[i];
	}
	
	printf("Enter the Time Quantum for the process: \n");  
	scanf("%d", &quant_time);  
	
	
	printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
	for(sum=0, i = 0; y_n!=0; )  
	{  
		if(temp_burst_time[i] <= quant_time && temp_burst_time[i] > 0) 
		{  
    			sum = sum + temp_burst_time[i];  
    			temp_burst_time[i] = 0;  
    			count=1;  
    		}     
    		else if(temp_burst_time[i] > 0)  
    		{  
        		temp_burst_time[i] = temp_burst_time[i] - quant_time;  
        		sum = sum + quant_time;    
    		}  
    		if(temp_burst_time[i]==0 && count==1)  
    		{  
        		y_n--; 
        		printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst_time[i], sum-arrival_time[i], sum-arrival_time[i]-burst_time[i]);  
        		wait_time = wait_time+sum-arrival_time[i]-burst_time[i];  
        		tat_time = tat_time+sum-arrival_time[i];  
        		count =0;     
    		}  
    		if(i==n-1)  
    		{  
        		i=0;  
    		}  
    		else if(arrival_time[i+1]<=sum)  
    		{  
        		i++;  
    		}  
    		else  
    		{  
        		i=0;  
    		}  
	}  
	 
	avg_waiting_time = wait_time * 1.0/n;  
	avg_turnaround_time = tat_time * 1.0/n;  
	printf("\n Average Turn Around Time: \t%f", avg_waiting_time);  
	printf("\n Average Waiting Time: \t%f", avg_turnaround_time);  
	
}


void priority_scheduling(){
	
	printf("\nEnter How Many Process do u want : ");
	scanf("%d",&n);
	
	printf("\nEnter %d process : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&process[i]);
	}
	
	printf("enter %d priority :",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&priority[i]);
        }
	printf("enter %d burst time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&burst_time[i]);
	}


	for(i = 0; i< n; i++)  
	{	  
    		int pos = i;  
		for(j = i + 1; j < n; j++)  
    		{		  
        	if(priority[j]>priority[pos])  
            	pos = j;  
    		}  
  
    		 int p=process[i];
    		 int b=burst_time[i];
    		 int tpr=priority[i];
    		 
    		 
    		
    		process[i]=process[pos];
    		burst_time[i]=burst_time[pos];
    		priority[i]=priority[pos];
    		
    		process[pos]=p;
    		burst_time[pos]=b;
    		priority[pos]=tpr;
    		
    		
    	
	}  
	
	
	waiting_time[0]=0;
	turnaround_time[0]=waiting_time[0]+burst_time[0];
	total_turnaround_time+=turnaround_time[0];
	for(i=1;i<n;i++){
	
		waiting_time[i]=burst_time[i-1]+waiting_time[i-1];
		turnaround_time[i]=waiting_time[i]+burst_time[i];
		total_wait_time+=waiting_time[i];
		total_turnaround_time+=turnaround_time[i];
	}
	avg_waiting_time=total_wait_time/(float)n;
	avg_turnaround_time=total_turnaround_time/(float)n;
	printf("\np\t B.T\t TAT\t WT");
	
	for(i=0;i<n;i++)
    	{
    		printf("\n----------------------------------------------------------------------------------");
      		printf("\nP%d\t %d \t %d \t %d",process[i],burst_time[i],turnaround_time[i],waiting_time[i]);
    	}
    	printf("\naverage turnaround time is %f",avg_turnaround_time);

    	printf("\naverage wating timme is %f",avg_waiting_time);
  
}

int main(){
	int choice,ch;
	do{
		printf("\n1.FCFS\n2.SJF\n3.Round Robin\n4.Priority\n5.Exit");
		printf("\nEnter Your choice :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				fcfs_scheduling();
				break;
			case 2:
				sjf_scheduling();
				break;
				
			case 3:
				round_robin_scheduling();
				break;
			case 4:
				priority_scheduling();
				break;
			case 5:
				exit(0);
				break;
			default:
				break;
		}
		printf("\n-------------------------------------------------");
		printf("\nDo You want to continue press 1 :\n");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}
