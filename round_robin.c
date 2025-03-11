#include <stdio.h>

// Function to calculate Waiting Time
void calculateWaitingTime(int processes[], int n, int bt[], int wt[], int quantum, int at[]) {
    int rem_bt[n]; // Remaining burst times
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There are still processes left

                if (rem_bt[i] > quantum && at[i] <= t) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else if (at[i] <= t) {
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - at[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break; // If all processes are completed, exit loop
    }
}

// Function to calculate Turnaround Time
void calculateTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average times
void calculateAverageTime(int processes[], int n, int bt[], int at[], int quantum) {
    int wt[n], tat[n];

    calculateWaitingTime(processes, n, bt, wt, quantum, at);
    calculateTurnaroundTime(processes, n, bt, wt, tat);

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processes[n], bt[n], at[n];

    for (int i = 0; i < n; i++) processes[i] = i + 1;

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &at[i], &bt[i]);

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculateAverageTime(processes, n, bt, at, quantum);
    return 0;
}
