#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a process
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void calculate_average_times(Process processes[], int n, float *avg_wait_time, float *avg_turnaround_time) {
    int total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    *avg_wait_time = (float)total_wait_time / n;
    *avg_turnaround_time = (float)total_turnaround_time / n;
}

void fcfs(Process processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }
}

void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0, min_index;
    int *is_completed = (int *)calloc(n, sizeof(int));

    while (completed < n) {
        min_index = -1;
        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && processes[i].arrival_time <= current_time) {
                if (min_index == -1 || processes[i].burst_time < processes[min_index].burst_time) {
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            current_time++;
            continue;
        }

        processes[min_index].waiting_time = current_time - processes[min_index].arrival_time;
        processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;
        processes[min_index].completion_time = current_time + processes[min_index].burst_time;
        current_time += processes[min_index].burst_time;
        is_completed[min_index] = 1;
        completed++;
    }

    free(is_completed);
}

void round_robin(Process processes[], int n, int time_quantum) {
    int current_time = 0, completed = 0;
    Process queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        queue[rear++] = processes[i];
    }

    while (completed < n) {
        Process *current = &queue[front];
        front = (front + 1) % n;

        if (current->remaining_time <= time_quantum) {
            current_time += current->remaining_time;
            current->remaining_time = 0;
            current->completion_time = current_time;
            current->turnaround_time = current->completion_time - current->arrival_time;
            current->waiting_time = current->turnaround_time - current->burst_time;
            completed++;
        } else {
            current_time += time_quantum;
            current->remaining_time -= time_quantum;
        }

        if (current->remaining_time > 0) {
            queue[rear] = *current;
        }
    }
}

int main() {
    int n, choice, time_quantum;
    float avg_wait_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("\nEnter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\nChoose the scheduling algorithm:\n1. FCFS\n2. SJF\n3. Round Robin\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            printf("Enter the time quantum: ");
            scanf("%d", &time_quantum);
            round_robin(processes, n, time_quantum);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    calculate_average_times(processes, n, &avg_wait_time, &avg_turnaround_time);

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
