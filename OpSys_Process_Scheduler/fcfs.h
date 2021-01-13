//FCFS CPU Run Function
void fcfs_run(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int swaps[],int life[], int death_time[]);
      
//Function to calculate FCFS Average Times and Print Detailed Results 
void fcfs_detailed( Process p_list[], int n, int swaps[], int death_time[]);

void fcfs_summarized(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int life[]);
    

