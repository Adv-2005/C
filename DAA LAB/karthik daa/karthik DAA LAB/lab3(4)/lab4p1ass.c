#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

int **cost;
int *assignment, *best_assignment;
int MAX_TASKS, best_cost = INT_MAX;
int i, j; // Initialize int i and j outside of the loops

// Generate random cost matrix
void generate_random_cost_matrix() {
    srand(time(NULL));
    for (i = 0; i < MAX_TASKS; i++)
        for (j = 0; j < MAX_TASKS; j++)
            cost[i][j] = rand() % 10 + 1;
}

// Calculate total cost of an assignment
int calculate_cost() {
    int total_cost = 0;
    for (i = 0; i < MAX_TASKS; i++)
        total_cost += cost[i][assignment[i]];
    return total_cost;
}

// Generate all possible assignments (brute-force)
void generate_assignments(int task) {
    if (task == MAX_TASKS) {
        int current_cost = calculate_cost();
        if (current_cost < best_cost) {
            best_cost = current_cost;
            for (i = 0; i < MAX_TASKS; i++)
                best_assignment[i] = assignment[i];
        }
        return;
    }

    for (i = 0; i < MAX_TASKS; i++) {
        int assigned = 0;
        for (j = 0; j < task; j++) {
            if (assignment[j] == i) {
                assigned = 1;
                break;
            }
        }
        if (!assigned) {
            assignment[task] = i;
            generate_assignments(task + 1);
        }
    }
}

int main() {
    printf("Enter the number of tasks/workers: ");
    scanf("%d", &MAX_TASKS);

    cost = (int **)malloc(MAX_TASKS * sizeof(int *));
    for (i = 0; i < MAX_TASKS; i++)
        cost[i] = (int *)malloc(MAX_TASKS * sizeof(int));
    assignment = (int *)malloc(MAX_TASKS * sizeof(int));
    best_assignment = (int *)malloc(MAX_TASKS * sizeof(int));

    clock_t start, end;
    start = clock(); // Start time measurement

    generate_random_cost_matrix();

    printf("Generated Cost Matrix:\n");
    for (i = 0; i < MAX_TASKS; i++) {
        for (j = 0; j < MAX_TASKS; j++)
            printf("%d ", cost[i][j]);
        printf("\n");
    }

    for (i = 0; i < MAX_TASKS; i++)
        assignment[i] = -1;

    generate_assignments(0);

    printf("Best Assignment:\n");
    for (i = 0; i < MAX_TASKS; i++)
        printf("Task %d assigned to Worker %d\n", i, best_assignment[i]);
    printf("Minimum Cost: %d\n", best_cost);

    end = clock(); // End time measurement
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.6lf seconds\n", time_taken); // Print execution time

    for (i = 0; i < MAX_TASKS; i++)
        free(cost[i]);
    free(cost);
    free(assignment);
    free(best_assignment);

    return 0;
}
