#include <stdio.h>
#include <string.h>
#include "Processes.h"
#include "fcfs.h"
#include "fcfs.c"
#include "pp.h"
#include "pp.c"
#include "srtf.h"
#include "srtf.c"
#include "rr.h"
#include "rr.c"
    

int main() {
	system("chcp 1253");
//Declare Variants   
    int i,n, clock,choice;
	int tasks,quantum;
	
//User Input  and Process Initializing
    printf("++++ Welcome to our virtual task scheduler of an operating system ++++\n");  
    printf("Εισάγετε το κβάντο χρόνου του χρονοπρογραμματιστή σας (σε ms):\n> ");
    scanf("%d", &quantum);
    int myquantum = quantum;
    printf("Εισάγετε τον αριθμό των διεργασιών που θα εκτελεστούν:\n> ");
    scanf("%d", &tasks);
    struct Process p_list[tasks];
     for (i = 0 ; i < tasks ; i++) {
     	p_list[i].pid= i+1;
     	printf("---- Διεργασία P%d ----\n",p_list[i].pid);
		printf("Εισάγετε το χρόνο άφιξης της διεργασίας (σε ms):\n> ");
		scanf("%d", &p_list[i].arrival_time);
		printf("Εισάγετε το χρόνο επεξεργασίας της διεργασίας (σε ms):\n> ");
		scanf("%d", &p_list[i].process_time);
		printf("Εισάγετε την προτεραίοτητα της διεργασίας (ως ακέραιο μεταξύ 1-μικρότερη και %d - μεγαλύτερη):\n> ", tasks);
		scanf("%d", &p_list[i].priority);
		printf("Η διεργασία αρχικοποιήθηκε επιτυχώς!\n\n");
    }
    //Total Burst Limit for General Use
    int x,total_burst_limit;
    for (x=0;x<tasks;x++){
	total_burst_limit = total_burst_limit + p_list[x].process_time;
	}
	
   	printf("Επιλέξτε τι θέλετε να κάνετε:\n");
    printf("+\t (1) Προσομοίωση για FCFS\t\t\t\t\t\t+\n");
    printf("+\t (2) Προσομοίωση για PP\t\t\t\t\t\t\t+\n");
    printf("+\t (3) Προσομοίωση για SRTF\t\t\t\t\t\t+\n");
	printf("+\t (4) Προσομοίωση για RR\t\t\t\t\t\t\t+\n");
	printf("+\t (5) Εκτύπωση συνοπτικών αποτελεσμάτων για όλους τους αλγορίθμους\t+\n");
	printf("Πληκτρολογήστε την επιλογή σας (1 - 5): ");
    scanf("%d", &choice);
    
	//Queue, Clock & Arrays Initialization
    int ready_queue[tasks];
    int front=-1;
    int rear = -1;
    clock=0;
    int allDead;
    int death_time[tasks];
    int swaps[tasks];
    int w,v;
    for (w=0;w<tasks;w++){
    	swaps[w]=0;
	}
	int life[tasks];
	for (v=0;v<tasks;v++){
		life[v]=p_list[v].process_time;
	}
	
	//Case Switcher Based on User's Input
	switch(choice)
	{
		case 1:
			//First Come First Served (FCFS) Algorithm
			
			//Run a Virtual CPU Simulation
			allDead=0;
			printf("++ Virtual CPU Simulation is Starting ++\n");
			printf("==================================\n");
			printf("time \t");
			for(n=0;n<tasks;n++){
			printf("P%d\t",n+1);
			}
			printf("\n");
			do{
			fcfs_run(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,swaps,life, death_time);
			clock++;	
			}while(allDead<tasks);
			printf("============= END OF SIMULATION =============\n");
			
			//Calculating Times for every Process
			fcfs_detailed(p_list, tasks, swaps, death_time);
			
			break;	
		case 2:
			//Preemptive Priority (PP) Algorithm
			
			//Run a Virtual CPU Simulation
			allDead=0;
			printf("++ Virtual CPU Simulation is Starting ++\n");
			printf("==================================\n");
			printf("time \t");
			for(n=0;n<tasks;n++){
			printf("P%d\t",n+1);
			}
			printf("\n");
			do{
			pp_run(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,swaps,life, death_time);
			clock++;	
			}while(allDead<tasks);
			printf("============= END OF SIMULATION =============\n");
			
			//Calculating Times for every Process
			pp_detailed(p_list, tasks, swaps, death_time);
			
			break;
		case 3:
			//Sortest Remaining Time First (SRTF) Algorithm
			
			//Run a Virtual CPU Simulation
			allDead=0;
			printf("++ Virtual CPU Simulation is Starting ++\n");
			printf("==================================\n");
			printf("time \t");
			for(n=0;n<tasks;n++){
			printf("P%d\t",n+1);
			}
			printf("\n");
			do{
			srtf_run(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,swaps,life, death_time);
			clock++;	
			}while(allDead<tasks);
			printf("============= END OF SIMULATION =============\n");
			
			//Calculating Times for every Process
			srtf_detailed(p_list, tasks, swaps, death_time);
			
			break;
		case 4:
			//Round Robin (RR) Algorithm
			
			//Run a Virtual CPU Simulation
			allDead=0;
			printf("++ Virtual CPU Simulation is Starting ++\n");
			printf("==================================\n");
			printf("time \t");
			for(n=0;n<tasks;n++){
			printf("P%d\t",n+1);
			}
			printf("\n");
			do{
			rr_run(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,swaps,life, death_time,&quantum,myquantum);
			clock++;	
			}while(allDead<tasks);
			printf("============= END OF SIMULATION =============\n");
			
			//Calculating Times for every Process
			rr_detailed(p_list, tasks, swaps, death_time);
			
			break;
		case 5:
			//Summarize Results
			printf("Time: ");
			int y;
			for(y=0;y<total_burst_limit;y++){
				printf("%d  ",y);
			}
			printf("\n");
			//FCFS Summarized
			for (v=0;v<tasks;v++){
			life[v]=p_list[v].process_time;
			}
			allDead=0;
			printf("FCFS: ");
			do{
			fcfs_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,life);
			clock++;	
			}while(allDead<tasks);
			printf("\n");
			//PP Summarized
			for (v=0;v<tasks;v++){
				life[v]=p_list[v].process_time;
			}
			allDead=0;
			clock=0;
			front=-1;
			rear=-1;
			printf("PP  : ");
			do{
			pp_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,life);
			clock++;	
			}while(allDead<tasks);
			printf("\n");
			//SRTF Summarized
			for (v=0;v<tasks;v++){
				life[v]=p_list[v].process_time;
			}
			allDead=0;
			clock=0;
			front=-1;
			rear=-1;
			printf("SRTF: ");
			do{
			srtf_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,life);
			clock++;	
			}while(allDead<tasks);
			printf("\n");
			//RR Summrized
			for (v=0;v<tasks;v++){
				life[v]=p_list[v].process_time;
			}
			allDead=0;
			clock=0;
			front=-1;
			rear=-1;
			printf("RR  : ");
			do{
			rr_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,life,&quantum, myquantum);
			clock++;	
			}while(allDead<tasks);
			printf("\n");
			break;
		default:
			printf("Πληκτρολογήστε την επιλογή σας (1 - 5): ");
			scanf("%d", &choice);
			
	}

   
}
