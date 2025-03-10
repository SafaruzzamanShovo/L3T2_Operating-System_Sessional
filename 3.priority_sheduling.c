#include<stdio.h>
int n, bt[20], wt[20], TNT[20], pid[20],ps[20];

void waiting_time(){
    wt[0] = 0;
    for(int i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

}

void turnaround_time(){

    for(int i = 0; i < n; i++){
        TNT[i] = wt[i] + bt[i];
    }

}
int main(){

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        pid[i] = i;
        printf("Enter the Burst Time for Process %d:",pid[i]);
        scanf("%d",&bt[i]);
    }

    for(int i = 0; i < n; i++){
        printf("Enter the Priority for Process %d:",pid[i]);
        scanf("%d",&ps[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(ps[i] > ps[j]){
                int temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    waiting_time();
    turnaround_time();
    printf("\nProcess  \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for(int i = 0; i < n; i++){
        printf("P%d \t\t %d \t\t %d \t\t %d\n",pid[i],bt[i],wt[i],TNT[i]);
    }

    int wt_sum = 0;
    int tnt_sum = 0;
    for(int i = 0; i < n; i++){
        wt_sum += wt[i];
        tnt_sum += TNT[i];
    }

    printf("Average Waiting Time : %.04lf \n", (wt_sum/n)*1.0);
    printf("Average Turnaround Time : %.04lf \n", (tnt_sum/n)*1.0);



}

