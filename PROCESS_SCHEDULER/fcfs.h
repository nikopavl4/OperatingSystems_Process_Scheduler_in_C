#include "Processes.h"

//FCFS CPU Run Function
void fcfs_run(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead,int swaps[],int life[]);

//Calculate Waiting Time for Each Process - Function
void calculateWaitingTime(Process p_list[], int n, int burst_time[], int waiting_time[]) ;
    
//Calculate TurnAround Time for Each Process - Function
void calculateTurnAroundTime( Process p_list[], int n, int burst_time[], int waiting_time[], int turnaround_time[]);  

    
//Function to calculate FCFS Average Times and Print Detailed Results 
void fcfs_detailed( Process p_list[], int n, int swaps[])  ;

void fcfs_summarized(Process p_list[], int clock, int n, int ready_queue[], int *front, int *rear,int *allDead);
    

