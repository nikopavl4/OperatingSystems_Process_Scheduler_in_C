//Structure Process Declaration
typedef struct Process {
   int   pid;
   int   arrival_time;
   int   process_time;
   int   priority;
}Process;

//FCFS CPU Run Function
void fcfs_run(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int swaps[],int life[])
{
	//Variables Declaration
	int j,k,l,m;
	char printables[n];

	//Print '-' for Processes NOT in the ready_queue
	  for (k=0; k<n; k++){
		for (l=*front; l<=*rear;l++){
			if (p_list[k].pid!=ready_queue[l]){
			  printables[k]='-';}
		}
	}

	// Insert an element in the ready_queue
	for (j=0; j<n; j++){
		if (p_list[j].arrival_time == clock){
			if (*front == -1)
      			{*front = 0;}
    		(*rear)++;
    		ready_queue[*rear] = p_list[j].pid;
    		//printf("\nInserted -> P%d\n", p_list[j].pid);
		}
	}
	
	//Update CPU outputs
	for (k=0; k<=n; k++){
		for (l=*front; l<=*rear;l++){
			if (p_list[k].pid==ready_queue[l]){
				printables[k]='W';
		    }
		    
			if (p_list[k].pid==ready_queue[*front]){
				printables[k]='R';
			}
		}
	}
	
    // Ready_queue Sorting + SWAPS
    // No Need for FCFS Algorithm
    //swaps[]++
    
	//Delete Unecessary Elements from the Queue
	life[ready_queue[*front]-1]--;
	if(life[ready_queue[*front]-1]<=0){
	if (*front == -1)
    {printf("!Queue is Empty\n");}
  else {
    //printf("\nDeleted : %d", ready_queue[*front]);
    (*allDead)++;
    (*front)++;
    }if (*front > *rear)
      {*front = *rear = -1;}
  }
  
   //Print CPU Outputs
  	printf("%d \t",clock);
	for (m=0;m<=n;m++){
		printf("%c \t",printables[m]);
	}
	printf("\n");
	
}

//Calculate Waiting Time for Each Process - Function
void calculateWaitingTime(Process p_list[], int n, int burst_time[], int waiting_time[])  
{  
    // waiting time for first process is 0  
    waiting_time[0] = 0;  
    
    // calculating waiting time
	int i;  
    for (i = 1; i < n ; i++ )  {
    waiting_time[i] =  burst_time[i-1] + waiting_time[i-1] - p_list[i].arrival_time + p_list[i-1].arrival_time;
    if(waiting_time[i]<0){
    	waiting_time[i] = 0;
	}
	}

}  
    
//Calculate TurnAround Time for Each Process - Function
void calculateTurnAroundTime( Process p_list[], int n, int burst_time[], int waiting_time[], int turnaround_time[])  
{  
    // calculating turnaround time
	int i; 
    for (i = 0; i < n ; i++)  
        turnaround_time[i] = burst_time[i] + waiting_time[i];  
}  
    
//Function to calculate FCFS Average Times and Print Detailed Results 
void fcfs_detailed( Process p_list[], int n, int swaps[])  
{  
    int j;
    int processes[n],bt[n];
    for (j=0;j<n;j++){
    	processes[j]= p_list[j].pid;
    	bt[j]=p_list[j].process_time;
	}
    int wt[n], tat[n], total_wt = 0, total_tat = 0;  
    
    //Function to calculate waiting time of each process
    calculateWaitingTime(p_list, n, bt, wt);  
    
    //Function to calculate turn around time for each process
    calculateTurnAroundTime(p_list, n, bt, wt, tat);  
    
    //Display Header
    printf("Processes   Burst time   Waiting time   Number of Swaps   Turn around time\n");  
    
    // Calculate total waiting time and total turn around time and display them
	int i;  
    for (i=0; i<n; i++)  
    {  
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("   P%d ",(i+1)); 
        printf("\t\t%d", p_list[i].process_time ); 
        printf("\t\t%d",wt[i] );
		printf("\t\t%d",swaps[i] ); 
        printf("\t\t%d\n",tat[i] );  
    }  
    
    //Calculate & Display Average Times
	int avg_waiting_time=(float)total_wt / (float)n; 
    int avg_turnaround_time=(float)total_tat / (float)n; 
    printf("Average waiting time = %d \n",avg_waiting_time); 
    printf("Average turn around time = %d \n",avg_turnaround_time);  
} 

void fcfs_summarized(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead)
{
	//Variables Declaration
	int j,k,l,m;
	char print_id;
	
	//Print '-' if Ready_queue is empty
	if((*front)== -1){
		print_id= '-';
	}
	
	// Insert an element in the ready_queue
	for (j=0; j<n; j++){
		if (p_list[j].arrival_time == clock){
			if (*front == -1)
      			{*front = 0;}
    		(*rear)++;
    		ready_queue[*rear] = p_list[j].pid;
    		//printf("\nInserted -> P%d\n", p_list[j].pid);
		}
	}
	
	// Ready_queue Sorting
    // No Need for FCFS Algorithm
    
    //Update outputs
	for (k=0; k<=n; k++){
		for (l=*front; l<=*rear;l++){ 
			if (p_list[k].pid==ready_queue[*front]){
				print_id=p_list[k].pid +'0';
			}
		}
	}
    
	//Delete Unecessary Elements from the Queue
	p_list[ready_queue[*front]-1].process_time--;
	if(p_list[ready_queue[*front]-1].process_time<=0){
	if (*front == -1)
    {printf("!Queue is Empty\n");}
  else {
    //printf("\nDeleted : %d", ready_queue[*front]);
    (*allDead)++;
    (*front)++;
    }if (*front > *rear)
      {*front = *rear = -1;}
  }
  
   //Print Summarized Outputs
   	printf("P%c ",print_id);
}
    

