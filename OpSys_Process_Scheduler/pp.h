//PP CPU Run Function
void pp_run(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int swaps[],int life[], int death_time[]);
    
//Function to calculate PP Average Times and Print Detailed Results 
void pp_detailed( Process p_list[], int n, int swaps[], int death_time[]);

//Function to Calculate PP Gant Diagram
void pp_summarized(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int life[]);


