
#include <stdio.h>

void knapsack(int n, int objectNo[], float weight[], float profit[], float capacity)
{
    float x[20], tp = 0.0, u;
    int i;

    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n && u > 0)
    {
        x[i] = u / weight[i];
        tp = tp + (x[i] * profit[i]);
    }

    /* Result Vector with Object Labels */
    printf("\nThe Result Vector is:\n");

    for (i = 0; i < n; i++)
    {
        printf("Object %d = %.2f\n", objectNo[i], x[i]);
    }

    printf("\nMaximum Profit is: %.2f\n", tp);
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;
    int objectNo[20], tempObj;

    printf("\nEnter the no. of objects: ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each object:\n");

    for (i = 0; i < num; i++)
    {
        printf("Object %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
        objectNo[i] = i + 1;
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    /* Calculate Profit / Weight Ratio */
    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    /* Display Original Order */
    printf("\nOriginal Order:\n");
    printf("Object\tWeight\tProfit\tRatio\n");

    for (i = 0; i < num; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               objectNo[i], weight[i], profit[i], ratio[i]);
    }

    /* Sort according to Profit/Weight Ratio */
    printf("\nRearrangement during sorting:\n");

    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                tempObj = objectNo[i];
                objectNo[i] = objectNo[j];
                objectNo[j] = tempObj;

                printf("\nAfter swapping:");
                printf("\nPosition %d = Object %d", i + 1, objectNo[i]);
                printf("\nPosition %d = Object %d\n", j + 1, objectNo[j]);
            }
        }
    }

    /* Display Final Sorted Order */
    printf("\nFinal Sorted Order:\n");
    printf("Object\tWeight\tProfit\tRatio\n");

    for (i = 0; i < num; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               objectNo[i], weight[i], profit[i], ratio[i]);
    }

    /* Apply Fractional Knapsack */
    knapsack(num, objectNo, weight, profit, capacity);

    return 0;
}
