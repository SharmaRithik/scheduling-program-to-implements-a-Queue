#include<istdio.h>
        // declaring all required variables
struct process{
int process_name,
    arrival_time,
    burst_time,
    waiting_time,
    turning_time,
    priority,
    burst_time_copy;
}queuea[20],queueb[20];
int main(){	
struct process code;
// for keeping values safe we need copy of every value, as we would manupulate the input values which may cause problem at the end
int a,
    b,
    c,
    time=0,
    t1,
    t2,
    bu_t=0,
    largest,
    totalProcess,
    count=0,
    pf2=0,
    totalProcess2,
    n,
    pos,
    flag=0,
    y;
float wait_time=0,
      turnaround_time= 0,
      average_waiting_time,
      average_turnaround_time;
printf("********Written by Rithik sharma********\n");
printf("**** k18AZB49    11800883 **************\n");
printf("\nENTER TOTAL NUMBER OF PROCESSES = ");
//saving reference value to other var
scanf("%d",&totalProcess);
n=totalProcess;
for(a=0;a<totalProcess;a++){
    	printf("\nENTER PROCESS NAME = ");
        scanf("%d",&queuea[a].process_name);
        printf("\nENTER DETAILS FOR PROCESS =  %d:\n",queuea[a].process_name);
        printf("ENTER ARRIVAL TIME = ");
        scanf("%d",&queuea[a].arrival_time);
        printf("ENTER BURST TIME = ");
        scanf("%d",&queuea[a].burst_time);
        queuea[a].burst_time_copy=queuea[a].burst_time;
        printf("ENTER PRIORITY = \t");
        scanf("%d",&queuea[a].priority);
    }
	//some things are fixed throughout the program
        //time quantum for fixed priority
        //time quantum for round robin
    printf("\nTIME QUANTUM FOR FIXED QUEUE SCHEDULING = ");
    scanf("%d",&t1);
    printf("\nTIME QUANTUM FOR ROUND ROBIN = ");
    scanf("%d",&t2);
    printf("\n\nPROCESS\t|TURNAROND TIME |WAITING TIME\n\n");
	    //input complete
              //to calculate
              //average waiting time
              //average turn around time
    for(a=0;a<totalProcess;a++){
        pos=a;
	for(b=a+1;b<totalProcess;b++)
        {
            if(queuea[b].arrival_time<queuea[pos].arrival_time)
                pos=b;
        }
        code=queuea[a];
        queuea[a]=queuea[pos];
        queuea[pos]=code;
    }
    time=queuea[0].arrival_time;
    //traversing queue and checking if the current position is less than equal to the ath index of queue
    for(a=0;totalProcess!=0;a++)
    {
    	while(count!=t1)
    	{
    	//traversing the queue according to the arrival time and priority
		count++;
    		if(queuea[a].arrival_time<=time)
    		{
    			for(b=a+1;b<totalProcess;b++)
    			{
    				if(queuea[b].arrival_time==time&&queuea[b].priority<queuea[a].priority)
    				{
    					queueb[pf2]=queuea[a];
						pf2++;
    					for(c=a;c<totalProcess-1;c++)
    						queuea[c]=queuea[c+1];
    					totalProcess--;
						count=0;
    					a=b-1;
    					b--;
					}
				}
			}
			time++;
			queuea[a].burst_time--;
			if(queuea[a].burst_time==0)
			{//finding turn around time = time taken - arriavl time
			//analysing the waiting time = turning time - burst time 
				queuea[a].turning_time=time-queuea[a].arrival_time;
				queuea[a].waiting_time=queuea[a].turning_time-queuea[a].burst_time_copy;
				printf("%d\t|\t%d\t|\t%d\n",queuea[a].process_name,queuea[a].turning_time,queuea[a].waiting_time);
				wait_time+=time-queuea[a].arrival_time-queuea[a].burst_time_copy; 
    			turnaround_time+=time-queuea[a].arrival_time;
    			for(c=a;c<totalProcess-1;c++)
    				queuea[c]=queuea[c+1];a--;
    			totalProcess--;
				count=t1;break;
			}
		}
	     count=0;
                //traversing via burst times to finish every process
                if(queuea[a].burst_time!=0)
                {
                        queueb[pf2]=queuea[a];
                        pf2++;
                        for(c=a;c<totalProcess-1;c++)
                        queuea[c]=queuea[c+1];
                totalProcess--;
                }
                        if(a==totalProcess-1)
                                a=-1;
        }

	   return 0;
    }
