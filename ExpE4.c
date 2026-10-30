
#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int job[20], deadline[20], profit[20];
    int slot[20], maxDeadline = 0, totalProfit = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter deadline and profit of each job:\n");

    for (i = 0; i < n; i++)
    {
        job[i] = i + 1;
        printf("Job %d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);

        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    // Sort jobs by profit in descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;

                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    // Initialize time slots
    if (maxDeadline > n)
        maxDeadline = n;

    for (i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    // Schedule jobs using Greedy Method
    for (i = 0; i < n; i++)
    {
        for (j = deadline[i] - 1; j >= 0; j--)
        {
            if (j < maxDeadline && slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += profit[i];
                break;
            }
        }
    }

    // Display scheduled jobs
    printf("\nScheduled Jobs:\n");

    for (i = 0; i < maxDeadline; i++)
    {
        if (slot[i] != -1)
            printf("Job %d\t", job[slot[i]]);
    }

    printf("\nMaximum Profit: %d\n", totalProfit);

    return 0;
}
