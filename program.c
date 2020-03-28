#include <stdio.h>
struct process{
        // declaring all required variables
        int process_name;
        int priority;
        int burst_time;
        int arrival_time;
        int waiting_time;
        int turn_around_time;
}queuea[20],queueb[20];
int main(){
struct process code;
// for keeping values safe we need copy of every value, as we would manupulate the input values which may cause problem at the end
        int time=0,
            time1=0,
            time2=0,
            burst_time=0,
            count=0,
            number_of_process,
            number,
            time_quanta_1,
            time_quanta_2;
        float avg_wt_time,
              avg_turnaround_time,
              waiting_time=0,
              turnaround_time=0;
printf("*****WRITTEN BY RITHIK SHARMA*****\n");
printf("*****K18AZB49 11800883************\n");
              printf("ENTER TOTAL NUMBER OF PROCESSES = ");
              scanf("%d",&number_of_process);
              //saving reference value to other var
              number=number_of_process;
              for(int a=0;a<number_of_process;a++){
                       printf("ENTER PROCESS NAME = ");
                       scanf("%d",&queuea[a].process_name);
                       printf("ENTER DETAILS ABOUT THE PROCESS  %d:\n",queuea[a].process_name);
                       printf("ENTER ARRIVAL TIME = ");
                       scanf("%d",&queuea[a].arrival_time);
                       printf("ENTER BURST TIME = ");
                       scanf("%d",&queuea[a].burst_time);
                       queuea[a].burst_time=queuea[a].burst_time;
                       printf("ENTER PRIORITY = ");
                       scanf("%d",&queuea[a].priority);
              }
              //some things are fixed throughout the program 
              //time quantum for fixed priority 
              //time quantum for round robin 
              printf("\nENTER TIME QUANTUM FOR FIXED PRIORITY = ");
              scanf("%d",&time_quanta_1);
              printf("\nENTER TIME QUANTUM FOR ROUND ROBIN = ");
              scanf("%d",&time_quanta_2);
              printf(" PROCESS | TURN AROUND TIME | WAITING TIME \n");
              //input complete 
              //to calculate 
              //average waiting time
              //average turn around time
              
        return 0;
}
