#include<stdio.h> 
#include<conio.h>

void thirdIT(int num,int remt[10],int Cur_time,int arrt[10], int bst[10]);

int main() 
{
	int ProcNo,j,num,CurTime,RemProc,indicator,tq,Wait,tut,arrt[10],bst[10],remt[10],ivar=1;
	indicator = 0;
	Wait = 0;
	tut = 0;
	printf("Enter the number of processes..... "); 
	scanf("%d",&num);
	RemProc = num;
	
	printf("\nEnter the details of the processes which u entered\n");
	for(ProcNo = 0; ProcNo < num;ProcNo++) 
	{
		printf("\nProcess P%d\n\t",ProcNo+1);
		printf("Arrival time = "); 
		scanf("%d",&arrt[ProcNo]);
		printf("\tBurst time = "); 
		scanf("%d",&bst[ProcNo]); 
		remt[ProcNo]=bst[ProcNo]; 
	} 
	printf("\ First round with 3 as time quantum : \n"); 
	tq=3;
	CurTime=0;
	for(ProcNo=0;RemProc!=0;) 
	{
		if(remt[ProcNo]<=tq && remt[ProcNo]>0)
		{ 
			CurTime+=remt[ProcNo]; 
			remt[ProcNo]=0; 
			indicator=1; 
		} 
		else if(remt[ProcNo]>0)
		{ 
			remt[ProcNo]-=tq; 
			CurTime+=tq; 
		} 
		if(remt[ProcNo]==0 && indicator==1)			
		{ printf("%d",ProcNo);
			RemProc--;				
			printf("P %d",ProcNo+1); 
			printf("\t\t\t%d",CurTime-arrt[ProcNo]);
			printf("\t\t\t%d\n",CurTime-bst[ProcNo]-arrt[ProcNo]);
			Wait+=CurTime-arrt[ProcNo]-bst[ProcNo]; 
			tut+=CurTime-arrt[ProcNo]; 
			indicator=0; 
                       
		} 
		if(ProcNo==num-1){
			ivar++;
			if(ivar==2){
				ProcNo=0;
				tq=6;
				printf("\n Completion of First");
				printf("\nSecond round is initiated with 6 unit as time quantum \n");
			}
			else{
				printf("\n Second round is  Over");
				break;
			}
		}
		else if(CurTime >= arrt[ProcNo+1]){
			ProcNo++;
		}
		else{
			ProcNo=0;
		}
	}
	thirdIT(num,remt,CurTime,arrt,bst);
	return 0;
}


void thirdIT(int num,int remt[10],int Cur_time,int arrt[10], int bst[10])
{
	float averageWait,averagetut;
    int i,j,n=num,temp,bursTime[20],ProcNo[20],WaiTime[20],tutime[20],total=0,loc;
    
    printf("\nThird round with least burst time starts\n");
    
    for(i=0;i<n;i++)
    {
        bursTime[i]=remt[i];
        WaiTime[i]=Cur_time-arrt[i]-bursTime[i];
		ProcNo[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(bursTime[j]<bursTime[loc]){
            	loc=j;
            }
        }
        temp=bursTime[i];
        bursTime[i]=bursTime[loc];
        bursTime[loc]=temp;
        temp=ProcNo[i];
        ProcNo[i]=ProcNo[loc];
        ProcNo[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	WaiTime[i]+=bursTime[j];
        }
        total+=WaiTime[i];
    }
    averageWait=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tutime[i]=bursTime[i]+WaiTime[i];
        total=total + tutime[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",ProcNo[i],bursTime[i],WaiTime[i],tutime[i]);
    }
    averagetut=(float)total/n;
    printf("\n\nAverage waiting time = %f",averageWait);
    printf("\nAverage turnaround time = %f\n",averagetut);
	
}





