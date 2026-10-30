#include<stdio.h>
int mid;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        mid = l + (r - l) / 2;

        if (arr[mid] == x)
            mid;

        if (arr[mid] > x)
            binarySearch(arr, l, mid - 1, x);

        if (arr[mid] < x)
            binarySearch(arr, mid + 1, r, x);
    }

    -1;
}

int main()
{
    int arr[100],n,i,j,x,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter %d integers:\n",n);

    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n");
    printf("Entered Array is:");
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }

        arr[j+1]=key;
    }

    printf("\n");
    printf("Sorted Array is:");
    printf("\n");

    for(j=0;j<n;j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
    printf("\n");
    printf("Enter the number to be found:");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    if(result == x)
    {
        printf("\n");
        printf("Element %d is present at %d\n",result,mid);
        printf("\n");
    }
    else
    {
        printf("Element not found");
    }
    0;
}