//RR CPU Run Function
void rr_run(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int swaps[],int life[], int death_time[], int *quantum, int myquantum);
    
//Function to calculate RR Average Times and Print Detailed Results 
void rr_detailed( Process p_list[], int n, int swaps[], int death_time[]);

//Function to Calculate RR Gant Diagram
void rr_summarized(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int life[],int *quantum, int myquantum );


