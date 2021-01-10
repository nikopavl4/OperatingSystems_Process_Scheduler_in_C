//SRTF CPU Run Function
void srtf_run(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int swaps[],int life[], int death_time[]);
    
//Function to calculate SRTF Average Times and Print Detailed Results 
void srtf_detailed( Process p_list[], int n, int swaps[], int death_time[]);

//Function to Calculate SRTF Gant Diagram
void srtf_summarized(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int life[]);


