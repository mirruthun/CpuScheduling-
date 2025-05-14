#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

#define HIGH_PRIORITY 1
#define MEDIUM_PRIORITY 2
#define LOW_PRIORITY 3

// Task Structure
struct Task {
    int id;
    int priority;
    int execution_time; // in seconds
};

// Function to execute tasks based on priority
void execute_task(struct Task t) {

if (t.priority == HIGH_PRIORITY) {
        printf("Executing HIGH priority task (ID: %d) at MAX CPU frequency\n", t.id);
    } else if (t.priority == MEDIUM_PRIORITY) {
        printf("Executing MEDIUM priority task (ID: %d) at NORMAL CPU frequency\n", t.id);
    } else {
        printf("Executing LOW priority task (ID: %d) at LOW CPU frequency\n", t.id);
    }

    sleep(t.execution_time); // Simulate task execution
    printf("Task (ID: %d) completed\n", t.id);
}

// Function to enter low-power mode when no tasks remain
void enter_low_power_mode() {
    printf("No tasks pending. Entering LOW POWER MODE...\n");
    sleep(2); // Simulating low power state
}

int main() {
    // Simulating IoT tasks
    struct Task tasks[] = {
        {1, LOW_PRIORITY, 2},     // Cloud backup
        {2, HIGH_PRIORITY, 1},    // Fire alarm detection
        {3, MEDIUM_PRIORITY, 3},  // Temperature sensor update
        {4, LOW_PRIORITY, 2}      // Data sync
};

    int n = sizeof(tasks) / sizeof(tasks[0]);

    // Sorting tasks by priority (HIGH -> MEDIUM -> LOW)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Executing tasks in order of priority
    for (int i = 0; i < n; i++) {
        execute_task(tasks[i]);
    }

    // Entering low power mode if no tasks remain
    enter_low_power_mode();

    return 0;
}



