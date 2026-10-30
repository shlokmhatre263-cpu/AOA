#include<stdio.h>
void quicksort(int a[], int first, int last)
{
    int i,j,pivot, temp;
    if(first<last)
    {
        i=first;
        j=last;
        pivot=first;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
            {
                i++;
            }
            while(a[j]>a[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort (a,first,j-1);
        quicksort (a,j+1,last);
    }
}
int main()
{
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for( i= 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Unsorted list");
    for( i = 0; i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1);
    printf("Sorted list: ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\n");
}