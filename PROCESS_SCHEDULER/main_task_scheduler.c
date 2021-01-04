#include <stdio.h>
#include <string.h>
//#include "Processes.h"
#include "fcfs.h"
#include "fcfs.c"
//#include "pp.h"
//#include "pp.c"
//#include "srtf.h"
//#include "rr.h"
//#include "Processes.h"


int main() {
	system("chcp 1253");
//Declare Variants   
    int i,n, clock,choice;
	int tasks,quantum;
	
//User Input  and Process Initializing
    printf("++++ Welcome to our virtual task scheduler of an operating system ++++\n");  
    printf("�������� �� ������ ������ ��� ������������������� ��� (�� ms):\n> ");
    scanf("%d", &quantum);
    printf("�������� ��� ������ ��� ���������� ��� �� �����������:\n> ");
    scanf("%d", &tasks);
    struct Process p_list[tasks];
     for (i = 0 ; i < tasks ; i++) {
     	p_list[i].pid= i+1;
     	printf("---- ��������� P%d ----\n",p_list[i].pid);
		printf("�������� �� ����� ������ ��� ���������� (�� ms):\n> ");
		scanf("%d", &p_list[i].arrival_time);
		printf("�������� �� ����� ������������ ��� ���������� (�� ms):\n> ");
		scanf("%d", &p_list[i].process_time);
		printf("�������� ��� ������������� ��� ���������� (�� ������� ������ 1-��������� ��� %d - ����������):\n> ", tasks);
		scanf("%d", &p_list[i].priority);
		printf("� ��������� �������������� ��������!\n\n");
    }
    //Total Burst Limit for General Use
    int x,total_burst_limit;
    for (x=0;x<tasks;x++){
	total_burst_limit = total_burst_limit + p_list[x].process_time;
	}
	//int total_burst_limit = p_list[tasks-1].arrival_time + p_list[tasks-1].process_time;// den douleuei
	
   	printf("�������� �� ������ �� ������:\n");
    printf("+\t (1) ����������� ��� FCFS\t\t\t\t\t\t+\n");
    printf("+\t (2) ����������� ��� PP\t\t\t\t\t\t\t+\n");
    printf("+\t (3) ����������� ��� SRTF\t\t\t\t\t\t+\n");
	printf("+\t (4) ����������� ��� RR\t\t\t\t\t\t\t+\n");
	printf("+\t (5) �������� ���������� ������������� ��� ����� ���� �����������\t+\n");
	printf("�������������� ��� ������� ��� (1 - 5): ");
    scanf("%d", &choice);
    
	//Queue, Clock & Arrays Initialization
    int ready_queue[tasks];
    int front=-1;
    int rear = -1;
    clock=0;
    int allDead;
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
			fcfs_run(p_list,clock, tasks, ready_queue,&front,&rear,&allDead,swaps,life);
			clock++;	
			}while(allDead<tasks);
			printf("============= END OF SIMULATION =============\n");
			
			//Calculating Times for every Process
			fcfs_detailed(p_list, tasks, swaps);
			
			break;	
		case 2:
			//PP Algorithm
		case 3:
			//SRTF Algorithm
		case 4:
			//RR Algorithm
		case 5:
			//Summarize Results
			printf("Time: ");
			int y;
			for(y=0;y<total_burst_limit;y++){
				printf("%d  ",y);
			}
			printf("\n");
			allDead=0;
			printf("FCFS: ");
			do{
			fcfs_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead);
			clock++;	
			}while(allDead<tasks);
			printf("\n");
			allDead=0;
			printf("PP  : ");
			/*do{
			//pp_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead);
			clock++;	
			}while(allDead<tasks);*/
			printf("\n");
			allDead=0;
			printf("SRTF: ");
			/*do{
			//srtf_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead);
			clock++;	
			}while(allDead<tasks);*/
			printf("\n");
			allDead=0;
			printf("RR  : ");
			/*do{
			rr_summarized(p_list,clock, tasks, ready_queue,&front,&rear,&allDead);
			clock++;	
			}while(allDead<tasks);*/
			printf("\n");
			break;
		default:
			printf("�������������� ��� ������� ��� (1 - 5): ");
			scanf("%d", &choice);
			
	}

   
}
