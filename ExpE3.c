
#include <stdio.h>

void minMax(int arr[], int low, int high, int *min, int *max)
{
    int mid, min1, max1, min2, max2;

    if (low == high)
    {
        *min = *max = arr[low];
    }
    else if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        minMax(arr, low, mid, &min1, &max1);
        minMax(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int arr[100], n, i, min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    minMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
